template<typename T>
class ÑMyStringIterator : public std::iterator<std::input_iterator_tag, T>
{
	friend class CMyString;
private:
	ÑMyStringIterator(T* p);
	ÑMyStringIterator(T* p, bool m_wasRevers);
public:
	ÑMyStringIterator(const ÑMyStringIterator &it);
	bool operator!=(ÑMyStringIterator const& other) const;
	bool operator==(ÑMyStringIterator const& other) const;
	typename ÑMyStringIterator::reference operator*() const;
	ÑMyStringIterator& operator++();
	ÑMyStringIterator& operator--();
	ÑMyStringIterator& operator+=(size_t value);
	ÑMyStringIterator& operator-=(size_t value);
	T operator[](size_t index)const;
private:
	T* m_iterValue;
	bool m_wasRevers = false;
};

template<typename T>
ÑMyStringIterator<T>::ÑMyStringIterator(T *p) :
	m_iterValue(p)
{

}

template<typename T>
ÑMyStringIterator<T>::ÑMyStringIterator(T* p, bool wasRevers)
	: m_iterValue(p)
	, m_wasRevers(wasRevers)
{

}

template<typename T>
ÑMyStringIterator<T>::ÑMyStringIterator(const ÑMyStringIterator& it)
	: m_iterValue(it.m_iterValue)
{

}

template<typename T>
bool ÑMyStringIterator<T>::operator!=(ÑMyStringIterator const& other) const
{
	return m_iterValue != other.m_iterValue;
}

template<typename T>
bool ÑMyStringIterator<T>::operator==(ÑMyStringIterator const& other) const
{
	return m_iterValue == other.m_iterValue;
}

template<typename T>
typename ÑMyStringIterator<T>::reference ÑMyStringIterator<T>::operator*() const
{
	return *m_iterValue;
}

template<typename T>
ÑMyStringIterator<T> &ÑMyStringIterator<T>::operator++()
{
	m_wasRevers  ? --m_iterValue : ++m_iterValue;
	return *this;
}

template<typename T>
ÑMyStringIterator<T> &ÑMyStringIterator<T>::operator--()
{
	m_wasRevers ? ++m_iterValue : --m_iterValue;
	return *this;
}


template<typename T>
ÑMyStringIterator<T>& ÑMyStringIterator<T>::operator+=(size_t value)
{

	m_wasRevers ? m_iterValue-= value : m_iterValue+= value;
	return *this;
}


template<typename T>
ÑMyStringIterator<T>& ÑMyStringIterator<T>::operator-=(size_t value)
{
	m_wasRevers ? m_iterValue += value : m_iterValue -= value;
	return *this;
}

template<typename T>
ÑMyStringIterator<T> operator +(ÑMyStringIterator<T> it, size_t value)
{
	return it += value;
}

template<typename T>
ÑMyStringIterator<T> operator +(size_t value, ÑMyStringIterator<T> it)
{
	return it += value;
}

template<typename T>
T ÑMyStringIterator<T>::operator[](size_t index)const
{
	return m_iterValue[index];
}

template<typename T>
size_t const operator -(ÑMyStringIterator<T> const &iter1, ÑMyStringIterator<T> const &iter2)
{
	if (&*iter1 < &*iter2)
	{
		return 0;
	}
	return (&*iter1 - &*iter2);
} 