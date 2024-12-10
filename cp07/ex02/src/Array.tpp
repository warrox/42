
#include "../includes/Array.hpp"
#include <stdexcept>

template<typename T>
Array<T>::Array()
{
    this->_array = nullptr;
    this->_index = 0;
}

template<typename T>
Array<T>::Array(unsigned int elements)
{
    this->_array = new T[elements]; // Allocate memory for T objects
    this->_index = elements;
}

template<typename T>
Array<T>::~Array()
{
    delete[] this->_array; // Free the allocated memory
}

template<typename T>

T& Array<T>::operator=(Array<T>& rhs)
{
    if (this != &rhs) {
        delete[] this->_array; // Free existing memory
        this->_index = rhs._index;
        this->_array = new T[this->_index];
        for (unsigned int i = 0; i < this->_index; i++) {
            this->_array[i] = rhs._array[i];
        }
    }
    return *this;
}

template<typename T>
Array<T>::Array(Array<T>& rhs)
{
    this->_index = rhs._index;
    this->_array = new T[this->_index];
    for (unsigned int i = 0; i < this->_index; i++) {
        this->_array[i] = rhs._array[i];
    }
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= this->_index)
        throw std::out_of_range("Index out of range");
    return this->_array[index];
}

template<typename T>
unsigned int Array<T>::size() const
{
    return this->_index;
}
