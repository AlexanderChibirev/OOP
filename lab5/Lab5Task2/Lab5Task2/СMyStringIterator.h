#pragma once 

template<typename ValueType>
class �MyStringIterator : public std::iterator<std::input_iterator_tag, ValueType>
{
	friend class OwnContainer;
private:
	
public:
	�MyStringIterator(ValueType* p);
	�MyStringIterator(const �MyStringIterator &it);

	bool operator!=(�MyStringIterator const& other) const;
	bool operator==(�MyStringIterator const& other) const; //need for BOOST_FOREACH
	typename �MyStringIterator::reference operator*() const;
	�MyStringIterator& operator++();
private:
	ValueType* p;
};

template<typename ValueType>
�MyStringIterator<ValueType>::�MyStringIterator(ValueType *p) :
	p(p)
{

}

template<typename ValueType>
�MyStringIterator<ValueType>::�MyStringIterator(const �MyStringIterator& it) :
	p(it.p)
{

}

template<typename ValueType>
bool �MyStringIterator<ValueType>::operator!=(�MyStringIterator const& other) const
{
	return p != other.p;
}

template<typename ValueType>
bool �MyStringIterator<ValueType>::operator==(�MyStringIterator const& other) const
{
	return p == other.p;
}

template<typename ValueType>
typename �MyStringIterator<ValueType>::reference �MyStringIterator<ValueType>::operator*() const
{
	return *p;
}

template<typename ValueType>
�MyStringIterator<ValueType> &�MyStringIterator<ValueType>::operator++()
{
	++p;
	return *this;
}
