#include "stdafx.h"
#include "MyString.h"
#include <algorithm>
#include <stdlib.h>

CMyString::CMyString()
{
	m_chars = CreateString(0);
	m_length = 0;
}

CMyString::CMyString(const char * pString)
{
	auto length = strlen(pString);
	m_chars = CreateString(length);
	memcpy(m_chars.get(), pString, length + 1);
	m_length = length;
}

CMyString::CMyString(const char * pString, size_t length)
{
	m_chars = CreateString(length);
	m_length = length;
	memcpy(m_chars.get(), pString, length);
}

CMyString::CMyString(CMyString const& other)
{
	*this = other;
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
		return "\0";
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

CMyString::CMyString(std::string const& stlString) 
{
	m_length = stlString.length();
	m_chars = CreateString(m_length);
	memcpy(m_chars.get(), stlString.c_str(), m_length);
}

CMyString& CMyString::operator=(const CMyString &other)
{
	if (this != &other)
	{
		m_length = other.GetLength();
		m_chars = make_unique<char[]>(m_length + 1);
		memcpy(m_chars.get(), other.GetStringData(), m_length + 1);
	}
	return *this;
}

CMyString& CMyString::operator=(CMyString &&other)
{
	if (this != &other)
	{
		m_chars = move(other.m_chars);
		m_length = other.m_length;
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
	m_length = 0;
	m_chars = CreateString(0);
}

char& CMyString::operator[](size_t index)
{
	if (index > m_length || index < 0)
	{
		throw out_of_range("index out of range");
	}
	return m_chars.get()[index];
}

const char& CMyString::operator[](size_t index) const
{
	if (index > m_length || index < 0)
	{
		throw out_of_range("index out of range");
	}
	return m_chars.get()[index];
}

int CMyString::Compare(CMyString const & str) const
{
	int compare = strncmp(m_chars.get(), str.m_chars.get(), min(m_length, str.m_length));
	return (compare != 0 ? compare : int(m_length - str.m_length));
}

bool operator ==(const CMyString &leftString, const CMyString &rightString)
{
	return leftString.Compare(rightString) == 0;
}

bool operator !=(const CMyString &leftString, const CMyString &rightString)
{
	return !(leftString == rightString);
}

CMyString operator +(CMyString &leftString, const CMyString &rightString)
{
	return leftString += rightString;
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

std::ostream & operator<<(std::ostream & strm, CMyString const & str)
{
	strm << str.GetStringData();
	return strm;
}

std::istream & operator>>(std::istream & ostrm, CMyString & str)
{
	std::string tmp;
	ostrm >> tmp;
	str = tmp;
	return ostrm;
}

bool operator <(const CMyString &leftString, const CMyString &rightString)
{
	return leftString.Compare(rightString) < 0;
}

bool operator >(const CMyString &leftString, const CMyString &rightString)
{
	return !(leftString < rightString);
}


bool operator <=(const CMyString &leftString, const CMyString &rightString)
{
	return leftString.Compare(rightString) <= 0;
}

bool operator >=(const CMyString &leftString, const CMyString &rightString) 
{
	return leftString.Compare(rightString) >= 0;
}
