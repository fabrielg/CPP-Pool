#include "Span.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

static void testSubject()
{
	std::cout << "=== Subject Test ===" << std::endl;

	Span sp(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span : " << sp.longestSpan() << std::endl;

	std::cout << std::endl;
}

static void testFullSpan()
{
	std::cout << "=== Full Span Test ===" << std::endl;

	Span sp(2);

	try
	{
		sp.addNumber(1);
		std::cout << "Added 1: " << std::endl;
		sp.addNumber(2);
		std::cout << "Added 2: " << std::endl;
		sp.addNumber(3);
		std::cout << "Added 3: " << std::endl; // Should not be executed
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: "
				<< e.what()
				<< std::endl;
	}

	std::cout << std::endl;
}

static void testNotEnoughValues()
{
	std::cout << "=== Not Enough Values Test ===" << std::endl;

	Span sp(10);

	try
	{
		sp.shortestSpan();
	}
	catch (const std::exception &e)
	{
		std::cout << "Shortest span exception: "
				<< e.what()
				<< std::endl;
	}

	try
	{
		sp.longestSpan();
	}
	catch (const std::exception &e)
	{
		std::cout << "Longest span exception: "
				<< e.what()
				<< std::endl;
	}

	std::cout << std::endl;
}

static void test10000Values()
{
	std::cout << "=== 10000 Values Test ===" << std::endl;

	Span sp(10000);

	for (int i = 0; i < 10000; i++)
	{
		sp.addNumber(std::rand());
	}

	std::cout << "Inserted 10000 values" << std::endl;
	std::cout << "Shortest span: "
			<< sp.shortestSpan()
			<< std::endl;

	std::cout << "Longest span : "
			<< sp.longestSpan()
			<< std::endl;

	std::cout << std::endl;
}

int main()
{
	std::srand(std::time(NULL));

	testSubject();
	testFullSpan();
	testNotEnoughValues();
	test10000Values();

	return 0;
}