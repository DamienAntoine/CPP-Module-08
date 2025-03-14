#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

	std::list<int> lst;
	lst.push_back(100);
	lst.push_back(200);
	lst.push_back(300);

	std::cout << "TESTING VECTORS:\n";
	try
	{
		int pos = easyfind(vec, 30);
		std::cout << "Found value 30 at position: " << pos << std::endl;

		pos = easyfind(vec, 50);
		std::cout << "Found value 50 at position: " << pos << std::endl;
	}
	catch(const NotFoundException& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\nTESTING LISTS:\n";
	try
	{
		int pos = easyfind(lst, 200);
		std::cout << "Found value 200 at position: " << pos << std::endl;

		pos = easyfind(lst, 400);
		std::cout << "Found value 400 at position: " << pos << std::endl;
	}
	catch(const NotFoundException& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
