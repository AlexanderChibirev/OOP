#include "stdafx.h"
#include "MyString.h"
#include <algorithm>
#include <stdlib.h>

CMyString::CMyString()
	: m_chars(CreateString(0))
	, m_length(0)
{
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
	if (other.m_chars)
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
	return m_chars[index];
}

const char& CMyString::operator[](size_t index) const
{
	if (index > m_length)
	{
		throw out_of_range("index out of range");
	}
	return m_chars[index];
}

int CMyString::Compare(CMyString const & str) const
{
	auto cmp = (memcmp(m_chars.get(), str.GetStringData(), min(m_length, str.m_length)));
	return cmp != 0 ? cmp : static_cast<int>(m_length - str.m_length);
	//int compare = strncmp(m_chars.get(), str.m_chars.get(), min(m_length, str.m_length));
	//return (compare != 0 ? compare : int(m_length - str.m_length));
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
	CMyString lhs(leftString);
	return lhs += rightString;
}

CMyString operator+(const string & leftString, CMyString const & rightString)
{
	CMyString lhs(leftString);
	return lhs += rightString;
}

CMyString operator+(const char * leftString, CMyString const & rightString)
{
	CMyString lhs(leftString);
	return lhs += rightString;
}

std::ostream & operator<<(std::ostream & ostrm, CMyString const & str)
{
	ostrm << str.GetStringData();
	return ostrm;
}

std::istream & operator>>(std::istream & strm, CMyString & str)
{
	std::string tmp;
	strm >> tmp;
	str = CMyString(tmp);
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
