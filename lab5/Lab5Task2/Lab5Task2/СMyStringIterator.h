template<typename T>
class �MyStringIterator : public std::iterator<std::input_iterator_tag, T>
{
	friend class CMyString;
private:
	�MyStringIterator(T* p);
public:
	�MyStringIterator(const �MyStringIterator &it);

	bool operator!=(�MyStringIterator const& other) const;
	bool operator==(�MyStringIterator const& other) const; //need for BOOST_FOREACH
	typename �MyStringIterator::reference operator*() const;
	�MyStringIterator& operator++();
	�MyStringIterator& operator--();
private:
	T* p;
};

template<typename T>
�MyStringIterator<T>::�MyStringIterator(T *p) :
	p(p)
{

}

template<typename T>
�MyStringIterator<T>::�MyStringIterator(const �MyStringIterator& it) :
	p(it.p)
{

}

template<typename T>
bool �MyStringIterator<T>::operator!=(�MyStringIterator const& other) const
{
	return p != other.p;
}

template<typename T>
bool �MyStringIterator<T>::operator==(�MyStringIterator const& other) const
{
	return p == other.p;
}

template<typename T>
typename �MyStringIterator<T>::reference �MyStringIterator<T>::operator*() const
{
	return *p;
}

template<typename T>
�MyStringIterator<T> &�MyStringIterator<T>::operator++()
{
	++p;
	return *this;
}

template<typename T>
�MyStringIterator<T> &�MyStringIterator<T>::operator--()
{
	--p;
	return *this;
}