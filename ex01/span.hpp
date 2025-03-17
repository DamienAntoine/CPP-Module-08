#ifndef __SPAN_H__
#define __SPAN_H__

#include <iostream>
#include <algorithm>
#include <climits>
#include <stdexcept>
#include <vector>

class Span
{
	private:
		unsigned int N;
		std::vector<int> _vct;

	public:
		Span() : N(0) {}
		Span(unsigned int max_numbers);
		Span(const Span& other);
		~Span(){}

		Span& operator=(const Span& other);

		class MaxNumbersReached : public std::exception{
			public:
				virtual const char* what() const throw();
		};

		class NotEnoughNumbers : public std::exception{
			public:
				virtual const char* what() const throw();
		};

		void	addNumber(int nb);
		int		shortestSpan();
		int		longestSpan();

		template <typename Iterator>
		void addNumbers(Iterator begin, Iterator end)
		{
			unsigned int toAdd = std::distance(begin, end);

			if (_vct.size() + toAdd > N)
				throw MaxNumbersReached();

			_vct.insert(_vct.end(), begin, end);
		}
};

#endif
