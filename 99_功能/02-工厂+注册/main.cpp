//main.cpp
 
#include"factory.h"
using namespace std;

REGISTER_MESSAGE(Message1, "message1",5, 7);

int main() {
	
	Message* p = Factory::produce("message1");
	p->foo();
	return 0;
}