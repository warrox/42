#include "../includes/temp.hpp"
template <class T> void swap(T &x, T &y)
{
	T tmp;
	tmp = x;
	x = y;
	y = tmp;
}
template <class T> T min(T x, T y)
{
	if(x < y)
	{
		return(x);
	}
	else if(x == y)
	{
		return(y);
	}
	else
	{
		return(y);
	}
}
template <class T> T max(T x, T y)
{
	if(x > y)
	{
		return(x);
	}
	else if(x == y)
	{
		return(y);
	}
	else
	{
		return(y);
	}
}
