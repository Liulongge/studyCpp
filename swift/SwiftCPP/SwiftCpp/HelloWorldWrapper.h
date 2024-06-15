#ifndef HelloWorldWrapper_h
#define HelloWorldWrapper_h

#import <Foundation/Foundation.h>

@interface HelloWorldWrapper : NSObject
- (NSString *) sayHello:(int)param;
- (NSInteger) getRandomNumber;
- (NSInteger) setNSPath:(NSString *)path;
@end

#endif /* HelloWorldWrapper_h */

