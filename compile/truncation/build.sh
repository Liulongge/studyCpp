# mac
echo "\033[1;31m << 关闭implicit编译告警，使用隐式函数声明 >> \033[0m"
gcc demo.c test.c -o demo -Wno-implicit
echo "\033[1;36m << 运行程序: >> \033[0m"
./demo
rm demo

echo "\033[1;31m << 开启implicit编译告警，编译报错如下 >> \033[0m"
gcc demo.c test.c -o demo -std=c89