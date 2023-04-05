#include <iostream>  
#include <vector>  
#include <string>  
#include <tuple>  

using namespace std;
std::tuple<std::string, int> giveName(void)
{
	std::string cw("Caroline");
	int a(2013);
	std::tuple<std::string, int> t = std::make_tuple(cw, a);
	return t;
}

int main()
{
	//tuple作为返回值  
	auto tmp = giveName();
	std::cout << "name: " << get<0>(tmp)
		<< " years: " << get<1>(tmp) << std::endl;

	std::tuple<std::string, int> tmp2 = giveName();
	// auto [a, b] = giveName(); // c++17
	return 0;
}
