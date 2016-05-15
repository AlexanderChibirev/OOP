#pragma once
#include <iterator>
#include "StringList.h"
using namespace std;

class CListIterator : public iterator <random_access_iterator_tag, CStringList::Node>
{
	friend class CStringList;
public:
	CListIterator(const CListIterator &it);
	CListIterator(CStringList::Node* value, bool isReverse = false);
public:
	bool operator!=(CListIterator const& other) const;
	bool operator==(CListIterator const& other) const;
	string & operator*() const;
	CListIterator& operator++();
	CListIterator& operator--();
private:
	CStringList::Node * operator->()const;

	CStringList::Node* m_node = nullptr;
	bool m_isReverse = false;
};