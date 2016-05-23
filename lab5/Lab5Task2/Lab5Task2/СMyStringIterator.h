template<typename T>
class ÑMyStringIterator : public std::iterator<std::input_iterator_tag, T>
{
	friend class CMyString;
private:
	ÑMyStringIterator(T* p);
public:
	ÑMyStringIterator(const ÑMyStringIterator &it);

	bool operator!=(ÑMyStringIterator const& other) const;
	bool operator==(ÑMyStringIterator const& other) const; //need for BOOST_FOREACH
	typename ÑMyStringIterator::reference operator*() const;
	ÑMyStringIterator& operator++();
	ÑMyStringIterator& operator--();
private:
	T* p;
};

template<typename T>
ÑMyStringIterator<T>::ÑMyStringIterator(T *p) :
	p(p)
{

}

template<typename T>
ÑMyStringIterator<T>::ÑMyStringIterator(const ÑMyStringIterator& it) :
	p(it.p)
{

}

template<typename T>
bool ÑMyStringIterator<T>::operator!=(ÑMyStringIterator const& other) const
{
	return p != other.p;
}

template<typename T>
bool ÑMyStringIterator<T>::operator==(ÑMyStringIterator const& other) const
{
	return p == other.p;
}

template<typename T>
typename ÑMyStringIterator<T>::reference ÑMyStringIterator<T>::operator*() const
{
	return *p;
}

template<typename T>
ÑMyStringIterator<T> &ÑMyStringIterator<T>::operator++()
{
	++p;
	return *this;
}

template<typename T>
ÑMyStringIterator<T> &ÑMyStringIterator<T>::operator--()
{
	--p;
	return *this;
}