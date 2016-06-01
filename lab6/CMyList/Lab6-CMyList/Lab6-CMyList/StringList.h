#pragma once
#include <string>
#include <memory>

using namespace std;

class CListIterator;

class CStringList
{
	friend class CListIterator;
	struct Node
	{
		Node(const string & data, Node * prev, unique_ptr<Node> && next)
			: data(data), prev(prev), next(move(next))
		{
		}
		string data;
		Node *prev;
		unique_ptr<Node> next;
	};
	
public:
	CStringList();
	CStringList(initializer_list<string> const &list);
	size_t GetSize() const;

	void PushBack(const string & data);
	void PushFront(const string & data);

	void Clear();
	bool IsEmpty() const;

	string & GetBackElement();
	const string & GetBackElement()const;
	string & GetFrontElement();
	const string & GetFrontElement()const;

	CListIterator begin();
	CListIterator end();
	const CListIterator begin() const;
	const CListIterator end() const;

	CListIterator rbegin();
	CListIterator rend();
	const CListIterator rbegin() const;
	const CListIterator rend() const;

	void Insert(const CListIterator & it, const string & data);
	void Erase(const CListIterator & it);

private:
	size_t m_size = 0;
	unique_ptr<Node> m_firstNode = nullptr;
	Node * m_lastNode = nullptr;
};