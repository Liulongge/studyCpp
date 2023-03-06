#include<stdio.h>


#define TEST_VERSION(a, b, c) (((a) << 16) + ((b) << 8) + (c))
#define TEST_VERSION_CODE TEST_VERSION(4, 0, 0)

// 基础版本号，一般为3位数字
// x.y.z
// 可简单理解为 大版本.小版本.补丁号
// major.minor.patch
// x 主版本号 当API兼容性变化时，x需要递增
// y 次版本号 当增加功能 但不影响兼容性，y需要递增 (奇数为开发版本 偶数为正式版本 不一定)
// z 修订号   当bug修复但不影响兼容性，z需要递增

// xyz 必须为正整数
// 0.y.z 表示 处于开发阶段，系统可能不稳定 ，1.y.z 说明已有稳定版本
// 其他规则
// 常见
// Realease 代表稳定的版本
// GA       代表广泛认可的稳定版
// M        代表里程碑版 Milestone 具有一些全新的功能或是聚游里程碑一一的版本

// 其他
// pre_realease 先行版本号 可能不稳定 存在兼容性问题 ，格式 x.y.z[a-c][正整数] 例如 1.2.2.a22 1.2.2.c6
// Snapshot     快照版本 不稳定 处于开发中的版本
// Alpha        内部版本
// DEV          开发版本
// Beta         测试版
// Demo         演示版
// Enhance      增强版
// Free         免费版
// Full Version 完整版
// Final        最终版 正式版
// LTS          长期维护版本 一般为18个月
// Pro          专业版
// Plus         加强版
// Retail       零售版
// Shareware    共享版 一般有功能限制
// SR           修正版 Senior 中文解释为资深
// Trial        试用版
// Release      发行版
// RC           即将作为正式版发布
// Standrad     标准版
// Ultimate     旗舰版
// Upgrade      升级版

int main(void)
{
    printf("%d, %d.%d.%d\n", TEST_VERSION_CODE, \
        TEST_VERSION_CODE >> 16, \
        ((TEST_VERSION_CODE >> 8) & 0xFF), \
        (TEST_VERSION_CODE & 0xFF));
    return 0;
}