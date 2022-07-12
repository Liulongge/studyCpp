// g++ 1_coutColor.cpp -o demo

#include <iostream>
 
//the following are UBUNTU/LINUX ONLY terminal color codes.
#define RESET   "\33[0m"
#define BLACK   "\33[30m"      /* Black */
#define RED     "\33[31m"      /* Red */
#define GREEN   "\33[32m"      /* Green */
#define YELLOW  "\33[33m"      /* Yellow */
#define BLUE    "\33[34m"      /* Blue */
#define MAGENTA "\33[35m"      /* Magenta */
#define CYAN    "\33[36m"      /* Cyan */
#define WHITE   "\33[37m"      /* White */
#define BOLDBLACK   "\33[1m\33[30m"      /* Bold Black */
#define BOLDRED     "\33[1m\33[31m"      /* Bold Red */
#define BOLDGREEN   "\33[1m\33[32m"      /* Bold Green */
#define BOLDYELLOW  "\33[1m\33[33m"      /* Bold Yellow */
#define BOLDBLUE    "\33[1m\33[34m"      /* Bold Blue */
#define BOLDMAGENTA "\33[1m\33[35m"      /* Bold Magenta */
#define BOLDCYAN    "\33[1m\33[36m"      /* Bold Cyan */
#define BOLDWHITE   "\33[1m\33[37m"      /* Bold White */
 
int main(int argc, const char * argv[])
{
    // insert code here...
    std::cout<<RED      << "Hello, World! in RED" << RESET << std::endl;
    std::cout<<GREEN    << "Hello, World! in GREEN" << RESET << std::endl;
    std::cout<<YELLOW   << "Hello, World! in YELLOW" << RESET << std::endl;
    std::cout<<BLUE     << "Hello, World! in BLUE" << RESET << std::endl;
    std::cout<<MAGENTA  << "Hello, World! in MAGENTA" << RESET << std::endl;
    std::cout<<CYAN     << "Hello, World! in CYAN" << RESET << std::endl;
    std::cout<<WHITE    << "Hello, World! in WHITE" << RESET << std::endl;
    std::cout<<BOLDRED  << "Hello, World! in BOLDRED" << RESET << std::endl;
    std::cout<<BOLDCYAN << "Hello, World! in BOLDCYAN" << RESET << std::endl;
    std::cout << "======" << std::endl;
    return 0;
}
