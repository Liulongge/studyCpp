#include <opencv2/opencv.hpp>
#include <fstream>
#include <vector>

using namespace cv;
using namespace std;

/**
 * @brief 从二进制文件加载NV12数据
 * @param file_path 文件路径
 * @param width 图像宽度
 * @param height 图像高度
 * @return Mat NV12格式的Mat对象
 */
Mat loadNV12FromBin(const string& file_path, int width, int height) {
    // 计算NV12数据大小 (Y: w×h, UV: w×h/2)
    size_t data_size = width * height * 3 / 2;
    
    // 读取二进制文件
    ifstream file(file_path, ios::binary);
    if (!file.is_open()) {
        cerr << "无法打开文件: " << file_path << endl;
        return Mat();
    }
    
    // 读取数据到vector
    vector<uchar> buffer(data_size);
    file.read(reinterpret_cast<char*>(buffer.data()), data_size);
    
    // 创建Mat对象 (单通道，高度为1.5倍原始高度)
    return Mat(height * 3 / 2, width, CV_8UC1, buffer.data());
}

/**
 * @brief 将NV12转换为RGB Packed格式
 * @param nv12 NV12格式的Mat
 * @param width 图像宽度
 * @param height 图像高度
 * @return Mat RGB格式的Mat对象
 */
Mat nv12ToRgbPacked(const Mat& nv12, int width, int height) {
    // 检查输入尺寸
    if (nv12.rows != height * 3 / 2 || nv12.cols != width) {
        cerr << "NV12尺寸不匹配!" << endl;
        return Mat();
    }
    
    // 方法1: 使用OpenCV内置转换 (推荐)
    Mat rgb;
    cvtColor(nv12, rgb, COLOR_YUV2RGB_NV12);
    
    // 方法2: 手动转换 (当内置方法不可用时)
    /*
    Mat yuv_i420(height * 3 / 2, width, CV_8UC1);
    
    // 复制Y分量
    nv12(Rect(0, 0, width, height)).copyTo(yuv_i420(Rect(0, 0, width, height)));
    
    // 分离UV分量并转换为I420格式
    Mat uv = nv12(Rect(0, height, width, height / 2));
    Mat u(height / 2, width / 2, CV_8UC1);
    Mat v(height / 2, width / 2, CV_8UC1);
    
    for (int i = 0; i < uv.rows; ++i) {
        for (int j = 0; j < uv.cols; j += 2) {
            u.at<uchar>(i / 2, j / 2) = uv.at<uchar>(i, j);
            v.at<uchar>(i / 2, j / 2) = uv.at<uchar>(i, j + 1);
        }
    }
    
    // 合并为I420格式
    u.copyTo(yuv_i420(Rect(0, height, width / 2, height / 2)));
    v.copyTo(yuv_i420(Rect(0, height + height / 2, width / 2, height / 2)));
    
    // 转换为RGB
    cvtColor(yuv_i420, rgb, COLOR_YUV2RGB_I420);
    */
    
    return rgb;
}

int main() {
    // 参数设置
    string input_path = "input.nv12.bin";
    string output_path = "output_rgb.jpg";
    int width = 1280;  // 必须为偶数
    int height = 720;   // 必须为偶数
    
    // 1. 加载NV12二进制数据
    Mat nv12 = loadNV12FromBin(input_path, width, height);
    if (nv12.empty()) {
        cerr << "加载NV12数据失败!" << endl;
        return -1;
    }
    
    // 2. 转换为RGB
    Mat rgb = nv12ToRgbPacked(nv12, width, height);
    if (rgb.empty()) {
        cerr << "转换失败!" << endl;
        return -1;
    }
    
    // 3. 保存结果
    imwrite(output_path, rgb);
    cout << "转换成功! 结果已保存到: " << output_path << endl;
    
    // 4. 显示结果 (可选)
    imshow("RGB Output", rgb);
    waitKey(0);
    
    return 0;
}