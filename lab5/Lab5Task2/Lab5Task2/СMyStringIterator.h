#pragma once 

template<typename ValueType>
class ÑMyStringIterator : public std::iterator<std::input_iterator_tag, ValueType>
{
	friend class OwnContainer;
private:
	
public:
	ÑMyStringIterator(ValueType* p);
	ÑMyStringIterator(const ÑMyStringIterator &it);

	bool operator!=(ÑMyStringIterator const& other) const;
	bool operator==(ÑMyStringIterator const& other) const; //need for BOOST_FOREACH
	typename ÑMyStringIterator::reference operator*() const;
	ÑMyStringIterator& operator++();
private:
	ValueType* p;
};

template<typename ValueType>
ÑMyStringIterator<ValueType>::ÑMyStringIterator(ValueType *p) :
	p(p)
{

}

template<typename ValueType>
ÑMyStringIterator<ValueType>::ÑMyStringIterator(const ÑMyStringIterator& it) :
	p(it.p)
{

}

template<typename ValueType>
bool ÑMyStringIterator<ValueType>::operator!=(ÑMyStringIterator const& other) const
{
	return p != other.p;
}

template<typename ValueType>
bool ÑMyStringIterator<ValueType>::operator==(ÑMyStringIterator const& other) const
{
	return p == other.p;
}

template<typename ValueType>
typename ÑMyStringIterator<ValueType>::reference ÑMyStringIterator<ValueType>::operator*() const
{
	return *p;
}

template<typename ValueType>
ÑMyStringIterator<ValueType> &ÑMyStringIterator<ValueType>::operator++()
{
	++p;
	return *this;
}
