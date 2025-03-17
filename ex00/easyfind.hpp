#ifndef __EASYFIND_H__
#define __EASYFIND_H__

#include <algorithm>
#include <stdexcept>

class NotFoundException : public std::exception
{
	private:
		std::string _msg;
	public:
		NotFoundException(const std::string& msg = "Value not found") : _msg(msg) {}
		virtual const char* what() const throw()
		{
			return _msg.c_str();
		}
		virtual ~NotFoundException() throw() {}
};

template <typename T>
int	easyfind(T& tab, int tofind)
{
	typename T::iterator result = std::find(tab.begin(), tab.end(), tofind);

	if (result == tab.end())
		throw NotFoundException();

	return (std::distance(tab.begin(), result));
}

#endif
