#ifndef TEMP_HPP
#define TEMP_HPP
// template <class T> void iter(T &array, size_t length, typename iter(T array));
#include <cstdio>
template <typename T, typename Func>
void iter(T* array, size_t length, Func func);
#endif // !TEMP_HPP
