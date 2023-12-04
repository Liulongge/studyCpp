#include <iostream>
#include <opencv2/opencv.hpp>

// 定义Transform基类
class Transform {
public:
    virtual cv::Mat operator()(const cv::Mat& image) const = 0;
};

// 定义RotateTransform类，用于图像旋转
class Rotate : public Transform {
public:
    Rotate(double angle) : angle_(angle) {}

    virtual cv::Mat operator()(const cv::Mat& image) const 
    {
        cv::Mat rotated;
        cv::Point2f center(image.cols / 2, image.rows / 2);
        cv::Mat rotationMatrix = cv::getRotationMatrix2D(center, angle_, 1.0);
        cv::warpAffine(image, rotated, rotationMatrix, image.size());
        return rotated;
    }

private:
    double angle_;
};

// 定义ResizeTransform类，用于图像缩放
class Resize : public Transform {
public:
    Resize(double scale) : scale_(scale) {}

    virtual cv::Mat operator()(const cv::Mat& image) const 
    {
        cv::Mat scaled;
        cv::resize(image, scaled, cv::Size(), scale_, scale_);
        return scaled;
    }

private:
    double scale_;
};

// 定义GrayTransform类，用于图像灰度化
class Gray : public Transform {
public:
    virtual cv::Mat operator()(const cv::Mat& image) const 
    {
        cv::Mat gray;
        cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
        return gray;
    }
};

// 定义TransformPipeline类，用于处理图像
class Transforms {
public:
    Transforms(const std::vector<Transform*>& transforms) : transforms_(transforms) {}

    cv::Mat operator()(const cv::Mat& image) const 
    {
        cv::Mat image_tmp = image.clone();
        for (const auto& transform : transforms_) 
        {
            image_tmp = (*transform)(image_tmp);
        }
        return image_tmp;
    }

private:
    std::vector<Transform*> transforms_;
};

int main() {
    // 读取图像
    cv::Mat image = cv::imread("./cat.jpg");

    // 定义Transform对象
    Rotate rotate(45);
    Resize res ize(0.5);
    Gray gray;

    // 定义TransformPipeline对象，并添加Transform
    Transforms transforms({&rotate, &resize, &gray});

    // 处理图像
    cv::Mat transformed = transforms(image);

    // 显示原始图像和处理后的图像
    cv::imshow("Original Image", image);
    cv::imshow("Transformed Image", transformed);
    cv::waitKey(0);

    return 0;
}


// ------------------ 相同实现还有 ------------------
// // 定义一个抽象的Transform类，作为所有变换的基类
// class Transform {
// public:
//     // 构造函数
//     Transform() {}

//     // 析构函数
//     virtual ~Transform() {}

//     // 纯虚函数，子类必须实现
//     virtual void apply(cv::Mat& image) = 0;
// };

// // 定义一个Resize类，继承自Transform类，实现图像的缩放
// class Resize : public Transform {
// private:
//     // 缩放的目标宽度和高度
//     int width;
//     int height;
// public:
//     // 构造函数，接收宽度和高度参数
//     Resize(int width, int height) : width(width), height(height) {}

//     // 析构函数
//     ~Resize() {}

//     // 重写apply函数，使用cv::resize函数实现图像的缩放
//     void apply(cv::Mat& image) override {
//         cv::resize(image, image, cv::Size(width, height));
//     }
// };

// // 定义一个Rotate类，继承自Transform类，实现图像的旋转
// class Rotate : public Transform {
// private:
//     // 旋转的角度
//     double angle;
// public:
//     // 构造函数，接收角度参数
//     Rotate(double angle) : angle(angle) {}

//     // 析构函数
//     ~Rotate() {}

//     // 重写apply函数，使用cv::getRotationMatrix2D和cv::warpAffine函数实现图像的旋转
//     void apply(cv::Mat& image) override {
//         // 获取图像的中心点
//         cv::Point2f center(image.cols / 2.0, image.rows / 2.0);
//         // 计算旋转矩阵
//         cv::Mat rot_mat = cv::getRotationMatrix2D(center, angle, 1.0);
//         // 应用旋转变换
//         cv::warpAffine(image, image, rot_mat, image.size());
//     }
// };

// // 定义一个Compose类，继承自Transform类，实现多个变换的组合
// class Compose : public Transform {
// private:
//     // 一个存储Transform指针的向量
//     std::vector<Transform*> transforms;
// public:
//     // 构造函数，接收一个Transform指针的向量
//     Compose(std::vector<Transform*> transforms) : transforms(transforms) {}

//     // 析构函数
//     ~Compose() {
//         // 释放所有Transform指针的内存
//         for (auto transform : transforms) {
//             delete transform;
//         }
//     }

//     // 重写apply函数，依次调用每个Transform指针的apply函数
//     void apply(cv::Mat& image) override {
//         for (auto transform : transforms) {
//             transform->apply(image);
//         }
//     }
// };
