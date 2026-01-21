template <typename T>
typename T::const_iterator easyfind(const T& container, int n) {
	typename T::const_iterator ret = std::find(container.begin(), container.end(), n);
	if (ret == container.end())
		throw std::out_of_range("Value not found");
	return ret;
}
