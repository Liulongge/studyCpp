// 在C++11中添加原始字符串的字面量，定义方式为R"xxx(原始字符串)xxx"
// 其()两边的字符串可以忽略。
// 原始字面量R可以直接表示字符串的实际含义，而不需要额外对字符串做转义(\)或链接等操作(\)。
// 
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
#if 0
// D:helloworld    est.txt
// D:\hello\world\test.txt
// <html>
//         <head>
//         <海贼王>
//         </title>
//         </head>
    string str = "D:\hello\world\test.txt";
    cout << str << endl;
    string str1 = "D:\\hello\\world\\test.txt";
    cout << str1 << endl;
    string str2 = "<html>\n\
        <head>\n\
        <海贼王>\n\
        </title>\n\
        </head>\n\
    ";
    cout << str2 << endl;
#else
// D:\hello\world\test.txt
// D:\\hello\\world\\test.txt
// <html>
//         <head>
//         <海贼王>
//         </title>
//         </head>
    string str = R"(D:\hello\world\test.txt)";
    cout << str << endl;
    string str1 = R"(\D:\\hello\\world\\test.txt)";
    cout << str1 << endl;
    string str2 = R"(<html>
        <head>
        <海贼王>
        </title>
        </head>
    )";
    cout << str2 << endl;
#endif 
}