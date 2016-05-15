#include "stdafx.h"
#include "ListIterators.h"

CListIterator::CListIterator(CStringList::Node *value, bool isReverse)
	: m_node(value)
	, m_isReverse(isReverse)
{
}

CListIterator::CListIterator(const CListIterator& it)
	: m_node(it.m_node)
{
}

bool CListIterator::operator!=(const CListIterator & other)const
{
	return m_node != other.m_node;
}

bool CListIterator::operator==(const CListIterator & other)const
{
	return m_node == other.m_node;
}

string & CListIterator::operator*() const
{
	return m_node->data;
}

CListIterator & CListIterator::operator++()
{
	m_isReverse ? m_node = m_node->prev : m_node = m_node->next.get();
	return *this;
}

CListIterator & CListIterator::operator--()
{
	m_isReverse ? m_node = m_node->next.get() : m_node = m_node->prev;
	return *this;
}

CStringList::Node * CListIterator::operator->() const
{
	return m_node;
}