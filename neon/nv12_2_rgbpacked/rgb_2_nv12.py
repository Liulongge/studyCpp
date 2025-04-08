import cv2
import numpy as np

def resize_to_even(image, target_width, target_height):
    """调整图像尺寸，并确保宽高是偶数"""
    # 检查目标尺寸是否为偶数
    assert target_width % 2 == 0 and target_height % 2 == 0, "目标宽高必须是偶数"
    
    # 使用双线性插值调整尺寸
    resized_img = cv2.resize(image, (target_width, target_height), interpolation=cv2.INTER_LINEAR)
    return resized_img

def rgb_to_nv12(rgb_img):
    """将RGB图像转换为NV12格式"""
    h, w = rgb_img.shape[:2]
    assert w % 2 == 0 and h % 2 == 0, "图像宽高必须是偶数"

    # 转换为YUV420 (I420)
    yuv_i420 = cv2.cvtColor(rgb_img, cv2.COLOR_RGB2YUV_I420)
    
    # 提取Y、U、V分量
    y = yuv_i420[:h, :w]                          # Y分量（h x w）
    u = yuv_i420[h:h + h//4, :w//2]               # U分量（h/4 x w/2）
    v = yuv_i420[h + h//4:, :w//2]                # V分量（h/4 x w/2）

    # 检查U/V是否为空
    if u.size == 0 or v.size == 0:
        raise ValueError("提取的U/V分量为空，请检查输入图像和转换逻辑")

    # 交错UV分量（NV12的核心步骤）
    uv_interleaved = np.zeros((h//2, w), dtype=np.uint8)
    uv_interleaved[:, 0::2] = u.repeat(2, axis=0)  # U分量扩展
    uv_interleaved[:, 1::2] = v.repeat(2, axis=0)  # V分量扩展

    # 合并Y和UV
    nv12 = np.vstack((y, uv_interleaved))
    return nv12

def save_nv12_to_bin(nv12_data, output_path):
    """将NV12数据保存为.bin文件"""
    with open(output_path, 'wb') as f:
        f.write(nv12_data.tobytes())  # 写入二进制数据
    print(f"NV12数据已保存至: {output_path}")

if __name__ == "__main__":
    input_path = "car.jpg"          # 输入图像路径
    output_path = "output_640x360.nv12.bin"  # 输出.bin文件路径
    target_width, target_height = 640, 360  # 目标尺寸

    # 1. 读取图像（OpenCV默认BGR格式）
    bgr_img = cv2.imread(input_path)
    if bgr_img is None:
        raise FileNotFoundError(f"无法读取图像: {input_path}")

    # 2. 转为RGB（如果函数需要RGB输入）
    rgb_img = cv2.cvtColor(bgr_img, cv2.COLOR_BGR2RGB)

    # 3. Resize到目标尺寸（640x360）
    rgb_img = resize_to_even(rgb_img, target_width, target_height)

    # 4. 转换为NV12
    nv12_data = rgb_to_nv12(rgb_img)
    print("NV12数据形状:", nv12_data.shape)  # 应为 (540, 640) = (360 + 180, 640)

    # 5. 保存为.bin文件
    save_nv12_to_bin(nv12_data, output_path)