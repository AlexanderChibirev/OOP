template<typename T>
class �MyStringIterator : public std::iterator<std::input_iterator_tag, T>
{
	friend class CMyString;
private:
	�MyStringIterator(T* p);
	�MyStringIterator(T* p, bool m_wasRevers);
public:
	�MyStringIterator(const �MyStringIterator &it);
	bool operator!=(�MyStringIterator const& other) const;
	bool operator==(�MyStringIterator const& other) const;
	typename �MyStringIterator::reference operator*() const;
	�MyStringIterator& operator++();
	�MyStringIterator& operator--();
	�MyStringIterator& operator+=(size_t value);
	�MyStringIterator& operator-=(size_t value);
	T operator[](size_t index)const;
private:
	T* m_iterValue;
	bool m_wasRevers = false;
};

template<typename T>
�MyStringIterator<T>::�MyStringIterator(T *p) :
	m_iterValue(p)
{

}

template<typename T>
�MyStringIterator<T>::�MyStringIterator(T* p, bool wasRevers)
	: m_iterValue(p)
	, m_wasRevers(wasRevers)
{

}

template<typename T>
�MyStringIterator<T>::�MyStringIterator(const �MyStringIterator& it)
	: m_iterValue(it.m_iterValue)
{

}

template<typename T>
bool �MyStringIterator<T>::operator!=(�MyStringIterator const& other) const
{
	return m_iterValue != other.m_iterValue;
}

template<typename T>
bool �MyStringIterator<T>::operator==(�MyStringIterator const& other) const
{
	return m_iterValue == other.m_iterValue;
}

template<typename T>
typename �MyStringIterator<T>::reference �MyStringIterator<T>::operator*() const
{
	return *m_iterValue;
}

template<typename T>
�MyStringIterator<T> &�MyStringIterator<T>::operator++()
{
	m_wasRevers  ? --m_iterValue : ++m_iterValue;
	return *this;
}

template<typename T>
�MyStringIterator<T> &�MyStringIterator<T>::operator--()
{
	m_wasRevers ? ++m_iterValue : --m_iterValue;
	return *this;
}


template<typename T>
�MyStringIterator<T>& �MyStringIterator<T>::operator+=(size_t value)
{

	m_wasRevers ? m_iterValue-= value : m_iterValue+= value;
	return *this;
}


template<typename T>
�MyStringIterator<T>& �MyStringIterator<T>::operator-=(size_t value)
{
	m_wasRevers ? m_iterValue += value : m_iterValue -= value;
	return *this;
}

template<typename T>
�MyStringIterator<T> operator +(�MyStringIterator<T> it, size_t value)
{
	return it += value;
}

template<typename T>
�MyStringIterator<T> operator +(size_t value, �MyStringIterator<T> it)
{
	return it += value;
}

template<typename T>
T �MyStringIterator<T>::operator[](size_t index)const
{
	return m_iterValue[index];
}

template<typename T>
size_t const operator -(�MyStringIterator<T> const &iter1, �MyStringIterator<T> const &iter2)
{
	if (&*iter1 < &*iter2)
	{
		return 0;
	}
	return (&*iter1 - &*iter2);
} 