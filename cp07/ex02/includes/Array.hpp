#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>
class Array 
{
	private :
		T *_array;
		unsigned int _index;
	public:
		Array();
		Array(unsigned int elements);
		~Array();
		T & operator=(Array &);
		T & operator[](unsigned int index);
		Array(Array &);
		unsigned int size()const;	
};
#define nullptr 0
#include "../src/Array.tpp"
#endif // ARRAY_HPP

