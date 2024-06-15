// C++头文件

#ifndef HelloWorld_hpp
#define HelloWorld_hpp

#include <stdio.h>
#include <string>

std::string sayHello(int i, char *);
std::int64_t setNSPath(std::string &path);

class HelloWorld {
public:
  std::int64_t getRandomNumber();
};

#endif /* HelloWorld_hpp */
