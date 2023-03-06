//Factory.h
#pragma once
#include<map>
#include<iostream>
#include<functional>
#include"message.h"
 
class Factory {
public:
	template<typename T>
	class Register
	{
		public:
		Register(const std::string& key)
		{
			Factory::get_instance().map_.emplace(key, [] { return new T(); });
		}
 
		template<typename... Args>
		Register(const std::string& key, Args... args)
		{
			Factory::get_instance().map_.emplace(key, [&] { return new T(args...); });
		}
	};
 
	static Message* produce(const std::string& key)
	{
		if (map_.find(key) == map_.end())
			throw std::invalid_argument("the message key is not exist!");
 
		return map_[key]();
	}

private:
	Factory() {};
	Factory(const Factory&) = delete;
	Factory(Factory&&) = delete;
 
	static Factory& get_instance()
	{
		static Factory instance;
		return instance;
	}

	static std::map<std::string, std::function<Message*()> > map_; // 声明
};

std::map<std::string, std::function<Message*()> > Factory::map_; // 定义

#define REGISTER_MESSAGE_VNAME(T) reg_msg_##T##_
#define REGISTER_MESSAGE(T, key, ...) static Factory::Register<T> REGISTER_MESSAGE_VNAME(T)(key, ##__VA_ARGS__);