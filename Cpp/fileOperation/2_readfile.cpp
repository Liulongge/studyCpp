#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// 程序运行时产生的数据都属于临时数据，程序一旦运行结束都会被释放
// 通过 文件可以将数据持久化
// C++中对文件操作需要包含头文件<fstream>

// 文件类型分为两类：
// 1.文本文件 - 文件以ASCII码形式存储在计算机中
// 2.二进制文件 - 文件以文本的二进制形式存储在计算机中，用户一般不能直接读他们

// 文件流
// 操作文件三大类：
// ofstream：写操作
// ifstream：读操作
// fstream： 读写操作

// ######## 文本文件写文件 ########
// 写文件步骤如下：
// 1.包含头文件
//     #include <fstream>
// 2.创建流对象
//     ofstream ofs;
// 3.打开文件
//     ofs.open("文件路径", 打开方式)：
// 4.写数据
//     ofs << "要写入的数据"
// 5.关闭文件
//     ofs.close()

// 文件打开方式：
// 1.  ios::in      为读文件而打开文件
// 2.  ios::out     为写文件而打开文件
// 3.  ios::ate     初始位置，文件尾
// 4.  ios::app     追加方式写文件
// 5.  ios::trunc   如果文件存在，先删除，再创建
// 6.  ios::binary  二进制方式

// 注意：文件打开方式可以配合使用，利用 | 操作符
// 例如：用二进制方式写文件 iOS::binary | ios::out


// ######## ########
// 读文件与写文件步骤相似，但是读取方式相对于比较多

// 读文件步骤是如下：
// 1.包好头文件
//     #include <fstream>
// 2.创建流对象
//     ifstream
// 3.打开文件并判断文件是否打开成功
//     ifs.open("文件路径", 打开方式)；
// 4.读数据
//     四种方式读取
// 5.关闭文件
//     ifs.close();


// 总结
// 读文件可以利用 ifstream ，或者 fstream
// 利用 is_open() 函数可以判断文件是否打开成功
// close() 关闭文件
void test01()
{
    // 1.包好头文件
    //     #include <fstream>
    // 2.创建流对象
    ifstream ifs;
    // 3.打开文件并判断文件是否打开成功
    ifs.open("test.txt", ios::in);
    // 判断是否打开成功
    if( !ifs.is_open() )
    {
        cout << "open file failed" << endl;
        return;
    }
    // 4.读数据
    //     四种方式读取
    // 1. while 形式，读取完毕后 返回假
    char buffer[1024] = {0};
    while( ifs >> buffer)
    {
        cout << buffer << endl;
    }

    // 2. 
    // char buffer2[1024] = {0};
    // while( ifs.getline(buffer2, sizeof(buffer2)) ) // 准备了多大空间 
    // {
    //     cout << buffer2 << endl;
    // }

    // 3.
    // string buffer3;
    // while( getline( ifs, buffer3 ) )
    // {
    //     cout << buffer3 << endl;
    // }

    // 4.不推荐使用
    // EOF：end of file，文件尾
    // 一次读取一个字符，效率比较低
    // char c;
    // while( ( c = ifs.get() ) != EOF )
    // {
    //     cout << c << endl;
    // }

    // 5.关闭文件
    ifs.close();
}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}