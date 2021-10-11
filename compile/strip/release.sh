echo "\033[32m 编译test.so \033[0m"
g++ test.cpp -o test.so -shared -fPIC

echo "\033[32m 去除test.so符号表 \033[0m"
strip test.so

nm test.so

echo "\033[32m 编译main并链接test.so \033[0m"
g++ main.cpp -o demo ./test.so

echo "\033[32m 执行demo \033[0m"
chmod 777 demo
./demo
