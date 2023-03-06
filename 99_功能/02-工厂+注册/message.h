//Message.h
 
#pragma once
 
#include"factory.h"
class Message
{
public:
	virtual ~Message() {}
 
	virtual void foo()
	{
 
	}
};
 
class Message1 : public Message
{
public:

	Message1()
	{
		std::cout << "message1 Construct" << std::endl;
	}
 
	Message1(int a)
	{
		std::cout << "message1: " << a << std::endl;
	}
 
	Message1(int a, int b)
	{
		std::cout << "message2: " << a << b << std::endl;
	}
	
	~Message1()
	{
	}
 
	void foo()
	{
		std::cout << "message1 foo" << std::endl;
	}
};

class Message2 : public Message
{
public:
 
	Message2()
	{
		std::cout << "message2" << std::endl;
	}
 
	Message2(int a)
	{
		std::cout << "message2: " << a << std::endl;
	}
 
 	Message2(int a, int b)
	{
		std::cout << "message2: " << a << b << std::endl;
	}

	~Message2()
	{
	}
 
	void foo()
	{
		std::cout << "message2" << std::endl;
	}
};