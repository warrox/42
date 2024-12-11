#include "../includes/easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T& container, int to_find) {
    // Correctly declare the iterator type
    typename T::iterator it = std::find(container.begin(), container.end(), to_find);
    if (it == container.end()) {
        throw std::runtime_error("Number not found");
    }
    return it;
}
