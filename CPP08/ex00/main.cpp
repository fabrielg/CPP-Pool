#include <iostream>
#include <vector>
#include <list>
#include <deque>

#include "easyfind.hpp"

int main()
{
	std::cout << "=== VECTOR ===" << std::endl;

	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 30);
		std::cout << "Found in vector: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	int target_error = 99;
	try
	{
		easyfind(vec, target_error);
		std::cout << target_error <<" found" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << target_error << " " << e.what() << std::endl;
	}

	std::cout << "\n=== LIST ===" << std::endl;

	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);

	try
	{
		std::list<int>::iterator it = easyfind(lst, 2);
		std::cout << "Found in list: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	target_error = 42;
	try
	{
		easyfind(lst, target_error);
		std::cout << target_error <<" found" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << target_error << " " << e.what() << std::endl;
	}

	std::cout << "\n=== DEQUE ===" << std::endl;

	std::deque<int> deq;
	deq.push_back(100);
	deq.push_back(200);
	deq.push_back(300);

	try
	{
		std::deque<int>::iterator it = easyfind(deq, 200);
		std::cout << "Found in deque: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	target_error = -1;
	try
	{
		easyfind(deq, target_error);
		std::cout << target_error <<" found" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << target_error << " " << e.what() << std::endl;
	}

	return 0;
}