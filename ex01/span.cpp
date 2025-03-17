#include "span.hpp"

Span::Span(unsigned int max_numbers) : N(max_numbers)
{}

Span::Span(const Span& other) : N(other.N), _vct(other._vct)
{}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		N = other.N;
		_vct = other._vct;
	}
	return (*this);
}

void	Span::addNumber(int nb)
{
	if (_vct.size() < N)
		_vct.push_back(nb);
	else
		throw MaxNumbersReached();
}

int		Span::shortestSpan()
{
	if (_vct.size() < 1)
		throw NotEnoughNumbers();

	std::vector<int> sortedvct = _vct;
	std::sort(sortedvct.begin(), sortedvct.end());

	int min_diff = INT_MAX;
	size_t i = 1;
	while (i < sortedvct.size())
	{
		int diff = sortedvct[i] - sortedvct[i - 1];
		if (diff < min_diff)
			min_diff = diff;
		i++;
	}

	return (min_diff);
}


int		Span::longestSpan()
{
	int biggestnb = *std::max_element(_vct.begin(), _vct.end());
	int smallestnb = *std::min_element(_vct.begin(), _vct.end());

	return (biggestnb - smallestnb);
}

const char* Span::MaxNumbersReached::what() const throw()
{
	return ("Error : Cannot add number (Maximum numbers reached)");
}

const char* Span::NotEnoughNumbers::what() const throw()
{
	return ("Error : Cannot find longest or shortest span (Not enough numbers)");
}
