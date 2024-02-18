// 条款2：尽量以const、enum、inline替换#define(优先选择编译器而不是预处理器)
// 
// 举例：
//      #define ASPECT_RATIO 1.653
//      符号名称ASPECT_RATIO可能永远不会被编译器看到。他可能在源码进入编译器之前被预处理期删除。
//  (如果发生错误，编译器给出的错误信息可能是1.653，而不是ASPECT_RATIO。设想一下如果这部分不是自己写的，而是来自某个头文件？)
//      目标代码中，可能出现多个1.653副本
//      
//      替换(更好的)方案：
//      const double AspectRatio = 1.653 // 全大写名称通常用于宏，因此需要更改名称
// 
//      将#define替换为常量时，有两种特殊的情况值得一提：
//      1、定义常量指针
//          #define AUTHORNAME "Scott Meyers"
//          const char *const authorName = "Scott Meyers";
//          const std::string authorName("Scott Meyers");
//      2、特殊情况涉及特定于类的常量
//          要把常量的作用域限制为类，就必须把他设置成成员；要确保最多有一个常量的副本，就必须把他设为静态成员
//          class GamePlayer {
//          private:
//              #define NUMTURNS 5 // 宏无法将作用域限制在类的内部
//              static const int NumTurns = 5; // const 声明
//              int scores[NumTurns]; // 使用const
//          }