#pragma once

# include <algorithm>
# include <stdexcept>
# include <iterator>

template <typename T>
typename T::const_iterator easyfind(const T& container, int n);

#include "easyfind.tpp"