# 参考：
# https://blog.csdn.net/u010164190/article/details/128167936?spm=1001.2014.3001.5506

# g++ -fPIC -shared -o libtest.so -fvisibility=default test.cc

# nm libtest.so
# 0000000000003f10 T __Z7test_01v
# 0000000000003f44 T __Z7test_02v
#                  U _printf
# 注意：
# 可以看到test_01()和test_02()函数都是GLOBAL DEFAULT状态，说明此libtest.so可以被外界导出和调用的。


g++ -fPIC -shared -o libtest.so -fvisibility=hidden test.cc

# 0000000000003f10 T __Z7test_01v
# 0000000000003f44 t __Z7test_02v
#                  U _printf
# test_02()函数为LOCAL  DEFAULT局部函数，说明不能被外界导出和调用。因为在test_02()函数没有
# 声明__attribute ((visibility("default")))，所以为局部隐藏，不能被外界调用。