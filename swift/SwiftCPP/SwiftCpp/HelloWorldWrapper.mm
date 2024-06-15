// 接口文件


#import <Foundation/Foundation.h>
#import "HelloWorldWrapper.h"
#import "HelloWorld.hpp"

@implementation HelloWorldWrapper

- (NSString *) sayHello:(int)param
{
  std::string helloWorldMessage = sayHello(param, "abc");
  return [NSString
          stringWithCString:helloWorldMessage.c_str()
          encoding:NSUTF8StringEncoding];
}

- (int) setNSPath:(NSString *)path
{
    std::string stdString = [path UTF8String];
    std::int64_t status = setNSPath(stdString);
    return int(status);
}

- (int) getRandomNumber
{
  HelloWorld helloWorld;
  std::int32_t randomNumber = helloWorld.getRandomNumber();
  return int(randomNumber);
}

@end
