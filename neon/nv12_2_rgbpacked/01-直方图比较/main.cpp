#include <opencv2/opencv.hpp>
#include <fstream>
#include <iostream>
#include <cstdint>
#include <cstring>
#include <cmath>
#include <cstdlib>

void nv12_2_rgb_packed_opencv(uint8_t *src, uint8_t *dst, uint16_t width, uint16_t height)
{
    // 将NV12数据转换为OpenCV Mat对象
    cv::Mat nv12_mat(height * 3 / 2, width, CV_8UC1, src);

    // 将NV12转换为BGR格式
    cv::Mat bgr_mat;
    cv::cvtColor(nv12_mat, bgr_mat, cv::COLOR_YUV2BGR_NV12);

    // 如果需要RGB格式，可以使用cvtColor再次转换
    cv::Mat rgb_mat(height, width, CV_8UC3, dst);
    cv::cvtColor(bgr_mat, rgb_mat, cv::COLOR_BGR2RGB);
}

void nv12_2_rgb_packed_cpp(uint8_t *src, uint8_t *dst, uint16_t width, uint16_t height)
{
    uint8_t *y_plane = src;
    uint8_t *uv_plane = src + width * height;

    for (uint16_t j = 0; j < height; ++j)
    {
        for (uint16_t i = 0; i < width; ++i)
        {
            // Get Y value
            int y_index = j * width + i;
            int Y = y_plane[y_index];

            // Get U and V values
            int uv_index = ((j >> 1) * width) + (i & ~1); // Each UV pair spans 2 horizontal pixels
            int U = uv_plane[uv_index] - 128;
            int V = uv_plane[uv_index + 1] - 128;

            // Convert YUV to RGB
            int C = Y - 16;
            int D = U + 359 * C >> 8; // (298 * C + 516 * U) / 1024 ≈ 359 * C / 1024 + 516 * U / 1024
            int E = V + 148 * C >> 8; // (298 * C + 409 * V) / 1024 ≈ 359 * C / 1024 (simplified as 148*2+C adjustment logic here for conceptual)
            // Exact computation:
            // R = (298*(Y-16) + 409*(V-128) + 128) >> 8;
            // G = (298*(Y-16) - 100*(U-128) - 208*(V-128) + 128) >> 8;
            // B = (298*(Y-16) + 516*(U-128) + 128) >> 8;

            // Optimized integer arithmetic (fixed-point approximation):
            int R = (298 * C + 409 * V + 128) >> 8;
            int G = (298 * C - 100 * U - 208 * V + 128) >> 8;
            int B = (298 * C + 516 * U + 128) >> 8;

            // Clamp RGB values to [0, 255]
            R = R < 0 ? 0 : (R > 255 ? 255 : R);
            G = G < 0 ? 0 : (G > 255 ? 255 : G);
            B = B < 0 ? 0 : (B > 255 ? 255 : B);

            // Store RGB in packed format
            uint32_t rgb_index = y_index * 3; // Each pixel has 3 bytes (RGB)
            dst[rgb_index] = static_cast<uint8_t>(R);
            dst[rgb_index + 1] = static_cast<uint8_t>(G);
            dst[rgb_index + 2] = static_cast<uint8_t>(B);
        }
    }
}

// #include <arm_neon.h>
// #include <cstdint>
// #include <cstdlib>

// #include <arm_neon.h>
// #include <cstdint>
// #include <algorithm>

// void nv12_2_rgb_packed_neon(uint8_t *src, uint8_t *dst, uint16_t width, uint16_t height) {
//     uint8_t *y_plane = src;
//     uint8_t *uv_plane = src + width * height;

//     // Constants for YUV to RGB conversion (BT.601)
//     const int16x8_t v_16 = vdupq_n_s16(16);
//     const int16x8_t v_128 = vdupq_n_s16(128);
//     const int16x8_t v_298 = vdupq_n_s16(298);
//     const int16x8_t v_409 = vdupq_n_s16(409);
//     const int16x8_t v_m100 = vdupq_n_s16(-100);
//     const int16x8_t v_m208 = vdupq_n_s16(-208);
//     const int16x8_t v_516 = vdupq_n_s16(516);
//     const int16x8_t v_zero = vdupq_n_s16(0);
//     const int16x8_t v_255 = vdupq_n_s16(255);
//     const int16x8_t v_round = vdupq_n_s16(128);
// printf("%d\n", dst[1]);
//     // Process 8 pixels at a time for the main block
//     uint16_t main_width = width & ~7;
//     uint16_t main_height = height & ~1;

//     for (uint16_t y = 0; y < main_height; y += 2) {
//         for (uint16_t x = 0; x < main_width; x += 8) {
//             // Load Y for two rows
//             uint8x8_t y00 = vld1_u8(y_plane + y * width + x);
//             uint8x8_t y10 = vld1_u8(y_plane + (y + 1) * width + x);

//             // Load UV (interleaved)
//             uint8x8x2_t uv = vld2_u8(uv_plane + (y / 2) * width + x);

//             // Convert Y to 16-bit and subtract 16
//             int16x8_t c0 = vsubq_s16(vreinterpretq_s16_u16(vmovl_u8(y00)), v_16);
//             int16x8_t c1 = vsubq_s16(vreinterpretq_s16_u16(vmovl_u8(y10)), v_16);

//             // Convert UV to 16-bit and subtract 128
//             int16x8_t u = vsubq_s16(vreinterpretq_s16_u16(vmovl_u8(uv.val[0])), v_128);
//             int16x8_t v = vsubq_s16(vreinterpretq_s16_u16(vmovl_u8(uv.val[1])), v_128);

//             // Compute R, G, B components
//             int16x8_t r0 = vshrq_n_s16(vmlaq_s16(vmlaq_s16(v_round, c0, v_298), v, v_409), 8);
//             int16x8_t g0 = vshrq_n_s16(vmlaq_s16(vmlaq_s16(vmlaq_s16(v_round, c0, v_298), u, v_m100), v, v_m208), 8);
//             int16x8_t b0 = vshrq_n_s16(vmlaq_s16(vmlaq_s16(v_round, c0, v_298), u, v_516), 8);

//             int16x8_t r1 = vshrq_n_s16(vmlaq_s16(vmlaq_s16(v_round, c1, v_298), v, v_409), 8);
//             int16x8_t g1 = vshrq_n_s16(vmlaq_s16(vmlaq_s16(vmlaq_s16(v_round, c1, v_298), u, v_m100), v, v_m208), 8);
//             int16x8_t b1 = vshrq_n_s16(vmlaq_s16(vmlaq_s16(v_round, c1, v_298), u, v_516), 8);

//             // Clamp to [0, 255]
//             r0 = vmaxq_s16(vminq_s16(r0, v_255), v_zero);
//             g0 = vmaxq_s16(vminq_s16(g0, v_255), v_zero);
//             b0 = vmaxq_s16(vminq_s16(b0, v_255), v_zero);

//             r1 = vmaxq_s16(vminq_s16(r1, v_255), v_zero);
//             g1 = vmaxq_s16(vminq_s16(g1, v_255), v_zero);
//             b1 = vmaxq_s16(vminq_s16(b1, v_255), v_zero);

//             // Convert to 8-bit and interleave
//             uint8x8x3_t rgb0 = {
//                 vmovn_u16(vreinterpretq_u16_s16(r0)),
//                 vmovn_u16(vreinterpretq_u16_s16(g0)),
//                 vmovn_u16(vreinterpretq_u16_s16(b0))
//             };

//             uint8x8x3_t rgb1 = {
//                 vmovn_u16(vreinterpretq_u16_s16(r1)),
//                 vmovn_u16(vreinterpretq_u16_s16(g1)),
//                 vmovn_u16(vreinterpretq_u16_s16(b1))
//             };
//             // Store results
//             vst3_u8(dst + (y * width + x) * 3, rgb0);
//             vst3_u8(dst + ((y + 1) * width + x) * 3, rgb1);
//         }
//     }

//     // Process remaining columns (right edge)
//     if (width != main_width) {
//         for (uint16_t y = 0; y < main_height; y += 2) {
//             for (uint16_t x = main_width; x < width; ++x) {
//                 // Process 1 pixel at a time
//                 int Y0 = y_plane[y * width + x];
//                 int Y1 = y_plane[(y + 1) * width + x];

//                 int uv_index = (y / 2) * width + (x & ~1);
//                 int U = uv_plane[uv_index] - 128;
//                 int V = uv_plane[uv_index + 1] - 128;

//                 int C0 = Y0 - 16;
//                 int C1 = Y1 - 16;

//                 // Compute RGB
//                 int R0 = (298 * C0 + 409 * V + 128) >> 8;
//                 int G0 = (298 * C0 - 100 * U - 208 * V + 128) >> 8;
//                 int B0 = (298 * C0 + 516 * U + 128) >> 8;

//                 int R1 = (298 * C1 + 409 * V + 128) >> 8;
//                 int G1 = (298 * C1 - 100 * U - 208 * V + 128) >> 8;
//                 int B1 = (298 * C1 + 516 * U + 128) >> 8;

//                 // Clamp and store
//                 dst[(y * width + x) * 3]     = std::clamp(R0, 0, 255);
//                 dst[(y * width + x) * 3 + 1] = std::clamp(G0, 0, 255);
//                 dst[(y * width + x) * 3 + 2] = std::clamp(B0, 0, 255);

//                 dst[((y + 1) * width + x) * 3]     = std::clamp(R1, 0, 255);
//                 dst[((y + 1) * width + x) * 3 + 1] = std::clamp(G1, 0, 255);
//                 dst[((y + 1) * width + x) * 3 + 2] = std::clamp(B1, 0, 255);
//             }
//         }
//     }

//     // Process remaining rows (bottom edge)
//     if (height != main_height) {
//         for (uint16_t y = main_height; y < height; ++y) {
//             for (uint16_t x = 0; x < width; ++x) {
//                 int Y = y_plane[y * width + x];
//                 int uv_index = (y / 2) * width + (x & ~1);
//                 int U = uv_plane[uv_index] - 128;
//                 int V = uv_plane[uv_index + 1] - 128;

//                 int C = Y - 16;
//                 int R = (298 * C + 409 * V + 128) >> 8;
//                 int G = (298 * C - 100 * U - 208 * V + 128) >> 8;
//                 int B = (298 * C + 516 * U + 128) >> 8;

//                 dst[(y * width + x) * 3]     = std::clamp(R, 0, 255);
//                 dst[(y * width + x) * 3 + 1] = std::clamp(G, 0, 255);
//                 dst[(y * width + x) * 3 + 2] = std::clamp(B, 0, 255);
//             }
//         }
//     }
// }
#include <arm_neon.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

void nv12_2_rgb_packed_neon(uint8_t* nv12, uint8_t* rgb, int width, int height) {
    uint8_t* y_plane = nv12;
    uint8_t* uv_plane = nv12 + width * height;
    
    const float32x4_t c128 = vdupq_n_f32(128.0f);
    const float32x4_t c0 = vdupq_n_f32(0.0f);
    const float32x4_t c255 = vdupq_n_f32(255.0f);
    
    // YUV 到 RGB 的转换系数
    const float32x4_t y_scale = vdupq_n_f32(1.1686275f);
    const float32x4_t v_r = vdupq_n_f32(1.6039216f);
    const float32x4_t u_g = vdupq_n_f32(0.3921569f);
    const float32x4_t v_g = vdupq_n_f32(0.8156863f);
    const float32x4_t u_b = vdupq_n_f32(2.0235294f);
    
    for (int y = 0; y < height; y++) {
        uint8_t* y_row = y_plane + y * width;
        uint8_t* uv_row = uv_plane + (y / 2) * width;
        uint8_t* rgb_row = rgb + y * width * 3;
        
        int x = 0;
        // 主循环处理8个像素（2个UV对）
        for (; x <= width - 8; x += 8) {
            // 加载8个Y分量
            uint8x8_t y_vec = vld1_u8(y_row + x);
            
            // 加载2对UV分量（4字节：U0,V0,U1,V1）
            uint8x8_t uv_vec = vld1_u8(uv_row + (x & ~1));
            
            // 提取并复制UV分量
            uint8x8_t u_vec = vtbl1_u8(uv_vec, (uint8x8_t){0,0,2,2,0,0,2,2}); // U0,U0,U1,U1,U0,U0,U1,U1
            uint8x8_t v_vec = vtbl1_u8(uv_vec, (uint8x8_t){1,1,3,3,1,1,3,3}); // V0,V0,V1,V1,V0,V0,V1,V1
            
            // 扩展Y分量到32位浮点
            uint16x8_t y_u16 = vmovl_u8(y_vec);
            float32x4_t y_f32_lo = vcvtq_f32_u32(vmovl_u16(vget_low_u16(y_u16)));
            float32x4_t y_f32_hi = vcvtq_f32_u32(vmovl_u16(vget_high_u16(y_u16)));
            
            // 预处理Y分量：Y = (Y - 16) * 1.164
            y_f32_lo = vmulq_f32(vsubq_f32(y_f32_lo, vdupq_n_f32(16.0f)), y_scale);
            y_f32_hi = vmulq_f32(vsubq_f32(y_f32_hi, vdupq_n_f32(16.0f)), y_scale);
            
            // 扩展UV分量到32位浮点
            uint16x8_t u_u16 = vmovl_u8(u_vec);
            uint16x8_t v_u16 = vmovl_u8(v_vec);
            
            float32x4_t u_f32_lo = vcvtq_f32_u32(vmovl_u16(vget_low_u16(u_u16)));
            float32x4_t u_f32_hi = vcvtq_f32_u32(vmovl_u16(vget_high_u16(u_u16)));
            float32x4_t v_f32_lo = vcvtq_f32_u32(vmovl_u16(vget_low_u16(v_u16)));
            float32x4_t v_f32_hi = vcvtq_f32_u32(vmovl_u16(vget_high_u16(v_u16)));
            
            // 预处理UV分量：U = U - 128, V = V - 128
            u_f32_lo = vsubq_f32(u_f32_lo, c128);
            u_f32_hi = vsubq_f32(u_f32_hi, c128);
            v_f32_lo = vsubq_f32(v_f32_lo, c128);
            v_f32_hi = vsubq_f32(v_f32_hi, c128);
            
            // 计算RGB分量（低4个像素）
            float32x4_t r_lo = vaddq_f32(y_f32_lo, vmulq_f32(v_f32_lo, v_r));
            float32x4_t g_lo = vsubq_f32(y_f32_lo, vmulq_f32(u_f32_lo, u_g));
            g_lo = vsubq_f32(g_lo, vmulq_f32(v_f32_lo, v_g));
            float32x4_t b_lo = vaddq_f32(y_f32_lo, vmulq_f32(u_f32_lo, u_b));
            
            // 计算RGB分量（高4个像素）
            float32x4_t r_hi = vaddq_f32(y_f32_hi, vmulq_f32(v_f32_hi, v_r));
            float32x4_t g_hi = vsubq_f32(y_f32_hi, vmulq_f32(u_f32_hi, u_g));
            g_hi = vsubq_f32(g_hi, vmulq_f32(v_f32_hi, v_g));
            float32x4_t b_hi = vaddq_f32(y_f32_hi, vmulq_f32(u_f32_hi, u_b));
            
            // 裁剪到0-255范围并转换为8位
            uint8x8_t r8 = vqmovn_u16(vcombine_u16(
                vqmovn_u32(vcvtq_u32_f32(vmaxq_f32(c0, vminq_f32(c255, r_lo)))),
                vqmovn_u32(vcvtq_u32_f32(vmaxq_f32(c0, vminq_f32(c255, r_hi))))
            ));
            uint8x8_t g8 = vqmovn_u16(vcombine_u16(
                vqmovn_u32(vcvtq_u32_f32(vmaxq_f32(c0, vminq_f32(c255, g_lo)))),
                vqmovn_u32(vcvtq_u32_f32(vmaxq_f32(c0, vminq_f32(c255, g_hi))))
            ));
            uint8x8_t b8 = vqmovn_u16(vcombine_u16(
                vqmovn_u32(vcvtq_u32_f32(vmaxq_f32(c0, vminq_f32(c255, b_lo)))),
                vqmovn_u32(vcvtq_u32_f32(vmaxq_f32(c0, vminq_f32(c255, b_hi))))
            ));
            
            // 交错存储RGB数据
            uint8x8x3_t rgb_pixels = {r8, g8, b8};
            vst3_u8(rgb_row + x * 3, rgb_pixels);
        }
        
        // 处理剩余的像素（宽度不是8的倍数）
        for (; x < width; x++) {
            int uv_x = x & ~1;  // 对齐到UV对
            
            float y = (float)y_row[x] - 16.0f;
            float u = (float)uv_row[uv_x] - 128.0f;
            float v = (float)uv_row[uv_x + 1] - 128.0f;
            
            y *= 1.164f;
            
            float r = y + 1.596f * v;
            float g = y - 0.391f * u - 0.813f * v;
            float b = y + 2.018f * u;
            
            // 裁剪到0-255范围
            r = fmaxf(0.0f, fminf(255.0f, r));
            g = fmaxf(0.0f, fminf(255.0f, g));
            b = fmaxf(0.0f, fminf(255.0f, b));
            
            rgb_row[x * 3] = (uint8_t)r;
            rgb_row[x * 3 + 1] = (uint8_t)g;
            rgb_row[x * 3 + 2] = (uint8_t)b;
        }
    }
}

int main()
{
    // 图像尺寸（需要根据实际情况设置）
    const int width = 640;
    const int height = 360;

    // NV12格式的大小
    const size_t nv12_size = width * height * 3 / 2;
    const size_t rgb_packed_size = width * height * 3;

    // 读取NV12格式的二进制文件
    std::ifstream input_file("../output_640x360.nv12.bin", std::ios::binary);
    if (!input_file)
    {
        std::cerr << "无法打开输入文件" << std::endl;
        return -1;
    }

    // 分配内存以存储NV12数据
    std::vector<uint8_t> nv12_data(nv12_size);
    std::vector<uint8_t> rgb_packed_data_opencv(rgb_packed_size);
    std::vector<uint8_t> rgb_packed_data_cpp(rgb_packed_size);
    std::vector<uint8_t> rgb_packed_data_neon(rgb_packed_size);
    input_file.read(reinterpret_cast<char *>(nv12_data.data()), nv12_size);
    input_file.close();

    if (input_file.gcount() != nv12_size)
    {
        std::cerr << "读取文件失败或文件大小不匹配" << std::endl;
        return -1;
    }

    nv12_2_rgb_packed_opencv(nv12_data.data(), rgb_packed_data_opencv.data(), width, height);
    nv12_2_rgb_packed_cpp(nv12_data.data(), rgb_packed_data_cpp.data(), width, height);
    nv12_2_rgb_packed_neon(nv12_data.data(), rgb_packed_data_neon.data(), width, height);

    // 将RGB数据保存为二进制文件
    std::ofstream output_file_opencv("output_rgb_opencv.bin", std::ios::binary);
    output_file_opencv.write(reinterpret_cast<char *>(rgb_packed_data_opencv.data()), rgb_packed_size);

    std::ofstream output_file_cpp("output_rgb_cpp.bin", std::ios::binary);
    output_file_cpp.write(reinterpret_cast<char *>(rgb_packed_data_cpp.data()), rgb_packed_size);

    std::ofstream output_file_neon("output_rgb_neon.bin", std::ios::binary);
    output_file_neon.write(reinterpret_cast<char *>(rgb_packed_data_neon.data()), rgb_packed_size);

    std::cout << "转换完成，RGB数据已保存到 output_rgb.bin" << std::endl;

    return 0;
}