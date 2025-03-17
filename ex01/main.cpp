#include "span.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	try {
		std::cout << "\n=== BASIC TEST ===\n";
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		std::cout << "\n=== ADDING BEYOND CAPACITY ===\n";
		sp.addNumber(42);
	}
	catch(const Span::MaxNumbersReached& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		std::cout << "\n=== EMPTY SPAN TEST ===\n";
		Span emptySpan(5);
		std::cout << "Shortest span: " << emptySpan.shortestSpan() << std::endl;
	}
	catch(const Span::NotEnoughNumbers& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		std::cout << "\n=== ITERATOR RANGE TEST ===\n";

		Span bigSpan(10000);
		std::vector<int> numbers;

		for (int i = 0; i < 10000; i++)
		{
			if (i < 5000)
				numbers.push_back(3 * i);
			else
				numbers.push_back(3 * (i-5000) + 2);
		}

		bigSpan.addNumbers(numbers.begin(), numbers.end());

		std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
		std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;

		bigSpan.addNumber(42);
	}
	catch(const Span::MaxNumbersReached& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	return 0;
}
