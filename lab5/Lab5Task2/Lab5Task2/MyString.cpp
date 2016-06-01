#include "stdafx.h"
#include "MyString.h"
#include <algorithm>
#include <stdlib.h>

CMyString::CMyString()
	: m_chars(CreateString(0))
	, m_length(0)
{
}

CMyString::CMyString(size_t size, const CMyString &leftString, const CMyString &rightString)
	: m_length(size)
	, m_chars(CreateString(size))

{
	memcpy(m_chars.get(), leftString.GetStringData(), leftString.GetLength());
	memcpy(m_chars.get() + leftString.GetLength(), rightString.GetStringData(), rightString.GetLength());
}

CMyString::CMyString(const char * pString)
	: CMyString(pString, strlen(pString))
{
}

CMyString::CMyString(const char * pString, size_t length)
	: m_chars(CreateString(length))
	, m_length(length)
{
	memcpy(m_chars.get(), pString, length);
}

CMyString::CMyString(std::string const& stlString)
	: m_chars(CreateString(stlString.length()))
	, m_length(stlString.length())
{
	memcpy(m_chars.get(), stlString.c_str(), m_length);
}

CMyString::CMyString(CMyString const& other)
{
	auto len = other.GetLength();
	m_chars = CreateString(len);
	m_length = len;
	memcpy(m_chars.get(), other.GetStringData(), m_length);
}

CMyString::CMyString(CMyString && other)
{
	*this = move(other);
	other.m_chars = nullptr;
	other.m_length = 0;
}

size_t CMyString::GetLength()const
{
	return m_length;
}

const char*  CMyString::GetStringData() const
{
	if (!m_chars.get())
	{
		return "";
	}
	return m_chars.get();
}

CMyString  CMyString::SubString(size_t start, size_t length) const
{
	if (start > m_length)
	{
		throw out_of_range("invalid argument");
	}
	if (start + length > m_length)
	{
		return CMyString(m_chars.get() + start, m_length - start);
	}
	return CMyString(m_chars.get() + start, length);
}



CMyString& CMyString::operator=(const CMyString &other)
{
	if (this != &other)
	{
		CMyString tmp(other);
		swap(m_chars, tmp.m_chars);
		swap(m_length, tmp.m_length);
	}
	return *this;
}

CMyString& CMyString::operator=(CMyString &&other)
{
	if (this != &other)
	{
		m_chars = move(other.m_chars);
		m_length = other.m_length;
		other.Clear();
	}
	return *this;
}

unique_ptr<char[]> CMyString::CreateString(size_t length)
{
	auto tmp = make_unique<char[]>(length + 1);
	tmp[length] = '\0';
	return move(tmp);
}


CMyString& CMyString::operator+=(const CMyString &other)
{
	if (other.m_length > 0)
	{
		auto tempStr = make_unique<char[]>(other.GetLength() + m_length + 1);
		memcpy(tempStr.get(), m_chars.get(), m_length);
		memcpy(&tempStr[m_length], other.m_chars.get(), other.m_length);
		m_length = m_length + other.m_length;
		m_chars = move(tempStr);
	}
	return *this;
}

void CMyString::Clear()
{
	if (m_chars)
	{
		m_chars.reset();
	}
	m_length = 0;
}

char& CMyString::operator[](size_t index)
{
	if (index > m_length)
	{
		throw out_of_range("index out of range");
	}
	else if (!m_chars) 
	{
		return *const_cast<char*>(GetStringData());
	}
	return m_chars.get()[index];
}

const char& CMyString::operator[](size_t index) const
{
	if (index > m_length)
	{
		throw out_of_range("index out of range");
	}
	else if (!m_chars)
	{
		return *const_cast<char*>(GetStringData());
	}
	return m_chars.get()[index];
}

int CMyString::Compare(CMyString const & str) const
{
	auto cmp = (memcmp(GetStringData(), str.GetStringData(), min(m_length, str.m_length)));
	return cmp != 0 ? cmp : static_cast<int>(m_length - str.m_length);
}

bool operator ==(const CMyString &leftString, const CMyString &rightString)
{
	return leftString.Compare(rightString) == 0;
}

bool operator !=(const CMyString &leftString, const CMyString &rightString)
{
	return !(leftString == rightString);
}

CMyString operator +(const CMyString &leftString, const CMyString &rightString)
{
	CMyString tmp(leftString.GetLength() + rightString.GetLength(), leftString, rightString);
	return tmp;
}

CMyString operator+(const string & leftString, CMyString const & rightString)
{
	CMyString tmp(leftString.size() + rightString.GetLength(), leftString, rightString);
	return tmp;
}

CMyString operator+(const char * leftString, CMyString const & rightString)
{
	CMyString tmp(strlen(leftString) + rightString.GetLength(), leftString, rightString);
	return tmp;
}

std::ostream & operator<<(std::ostream & ostrm, CMyString const & str)
{
	auto string = str.GetStringData();
	for (size_t i = 0; i < str.GetLength(); i++)
	{
		ostrm << string[i];
	}
	return ostrm;
}

std::istream & operator>>(std::istream & strm, CMyString & str)
{
	std::string string;
	if (strm >> string) 
	{
		str = string;
	}
	return strm;
}

bool operator <(const CMyString &leftString, const CMyString &rightString)
{
	return leftString.Compare(rightString) < 0;
}

bool operator >(const CMyString &leftString, const CMyString &rightString)
{
	return leftString.Compare(rightString) > 0;
}


bool operator <=(const CMyString &leftString, const CMyString &rightString)
{
	return leftString.Compare(rightString) <= 0;
}

bool operator >=(const CMyString &leftString, const CMyString &rightString) 
{
	return leftString.Compare(rightString) >= 0;
}


/////////////////////////////////////////////////////////////////////////////////
CMyString::iterator CMyString::begin()
{
	return iterator(m_chars.get());
}

CMyString::iterator CMyString::end()
{
	return iterator(m_chars.get() + m_length);
}

CMyString::const_iterator CMyString::begin() const
{
	return const_iterator(m_chars.get());
}

CMyString::const_iterator CMyString::end() const
{
	return const_iterator(m_chars.get() + m_length);
}

///////////////////////////////////////////////////////////////////////////////

CMyString::iterator CMyString::rbegin()
{
	return iterator( (m_chars.get() + m_length - 1), true);
}

CMyString::iterator CMyString::rend()
{
	return iterator( (m_chars.get() - 1), true);
}

CMyString::const_iterator CMyString::rbegin() const
{
	return const_iterator( (m_chars.get() + m_length - 1), true);
}

CMyString::const_iterator CMyString::rend() const
{
	return const_iterator( (m_chars.get() - 1), true);
}