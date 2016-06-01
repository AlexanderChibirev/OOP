#include "stdafx.h"
#include "StringList.h"
#include <cassert>
#include "ListIterators.h"

using namespace std;


CStringList::CStringList()
{

}

CStringList::CStringList(initializer_list<string> const &list)
{
	for (auto &it :list)
	{
		PushBack(it);
	}
}

size_t CStringList::GetSize() const
{
	return m_size;
}

void CStringList::PushBack(const string & data)
{
	auto newNode = make_unique<Node>(data, m_lastNode, nullptr);
	Node *newLastNode = newNode.get();
	if (m_lastNode)
	{
		m_lastNode->next = move(newNode);
	}
	else
	{
		m_firstNode = move(newNode);
	}
	m_lastNode = newLastNode;
	m_lastNode->next = nullptr;
	++m_size;
}

void CStringList::PushFront(const string & data)
{
	auto newNode = make_unique<Node>(data, nullptr, move(m_firstNode));
	if (newNode->next)
	{
		newNode->next->prev = newNode.get();
	}
	else
	{
		m_lastNode = newNode.get();
	}
	m_firstNode = move(newNode);
	m_firstNode->prev = nullptr;
	m_size++;
}

CListIterator CStringList::begin()
{
	return CListIterator(m_firstNode.get());
}

CListIterator CStringList::end()
{
	return CListIterator(m_lastNode->next.get());
}

const CListIterator CStringList::begin() const
{
	return CListIterator(m_firstNode.get());
}

const CListIterator CStringList::end() const
{
	return CListIterator(m_lastNode->next.get());
}

CListIterator CStringList::rbegin()
{
	return CListIterator(m_lastNode, true);
}

CListIterator CStringList::rend()
{
	return CListIterator(m_firstNode->prev, true);
}

const CListIterator CStringList::rbegin() const
{
	return CListIterator(m_lastNode, true);
}

const CListIterator CStringList::rend() const
{
	return CListIterator(m_firstNode->prev, true);
}

void CStringList::Insert(const CListIterator & it, const string & data)
{
	if (it == begin())
	{
		PushFront(data);
	}
	else if (it == end())
	{
		PushBack(data);
	}
	else
	{
		auto node = make_unique<Node>(data, it->prev, move(it->prev->next));
		it->prev = move(node.get());
		node->prev->next = move(node);
	}
}

void CStringList::Erase(const CListIterator & it)
{
	if (m_size == 1)
	{
		Clear();
		return;
	}
	if (it == begin())
	{
		it->next->prev = nullptr;
		m_firstNode = move(it->next);
	}
	else if (it->data == GetBackElement())
	{
		it->prev->next = nullptr;
		m_lastNode = move(it->prev);
	}
	else
	{
		it->next->prev = move(it->prev);
		it->prev->next = move(it->next);
	}

	m_size == 0 ? m_size : m_size--;
}

void CStringList::Clear()
{
	while (m_lastNode)
	{
		m_lastNode->next = nullptr;
		m_lastNode = m_lastNode->prev;
	}
	m_firstNode = nullptr;
	m_size = 0;
}

bool CStringList::IsEmpty() const
{
	return m_size == 0u;
}

string & CStringList::GetBackElement()
{
	assert(m_lastNode);
	return m_lastNode->data;
}

const string & CStringList::GetBackElement() const
{
	assert(m_lastNode);
	return m_lastNode->data;
}

string & CStringList::GetFrontElement()
{
	assert(m_firstNode);
	return m_firstNode->data;
}
const string & CStringList::GetFrontElement() const
{
	assert(m_firstNode);
	return m_firstNode->data;
}
