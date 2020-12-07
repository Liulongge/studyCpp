#include<iostream>
#include<cstring>
using namespace std;
int main(void)
{
    char str[200] = "Hello,World";
    char str2[] =  "Hello,World";
    cout << sizeof(str) << "  " << strlen(str) << endl;      //200  11
    cout << sizeof(str2) << "  " << strlen(str2) << endl;    //12   11
    return 0;
}