#pragma once
#include "СMyStringIterator.h"
#include <memory>
using namespace std;

class CMyString
{
public:
	using iterator = СMyStringIterator<char> ;
	using const_iterator = СMyStringIterator<const char> ;


	iterator begin();
	iterator end();

	const_iterator begin() const;
	const_iterator end() const;

	iterator rbegin();
	iterator rend();

	const_iterator rbegin()const;
	const_iterator rend()const;


	CMyString(); // конструктор по умолчанию 
	CMyString(const char * pString); // конструктор, инициализирующий строку данными строки. С завершающим нулевым символом
	CMyString(const char * pString, size_t length);// конструктор, инициализирующий строку данными из символьного массива заданной длины
	CMyString(CMyString const& other);// конструктор копирования
	CMyString(CMyString && other);// перемещающий конструктор (для компиляторов, совместимых с C++11) реализуется совместно с перемещающим оператором присваивания 
	CMyString(string const& stlString);// конструктор, инициализирующий строку данными из строки стандартной библиотеки C++
	CMyString(size_t size, const CMyString &leftString, const CMyString &rightString);
	size_t GetLength() const;
	const char* GetStringData() const;
	CMyString SubString(size_t start, size_t length = SIZE_MAX) const;// возвращает подстроку с заданной позиции длиной не больше length символов
	void Clear();
	CMyString& operator =(const CMyString &other);
	CMyString& operator =(CMyString &&other);
	char& operator [](size_t index);
	const char& operator [](size_t index) const;
	CMyString& operator +=(const CMyString &other);
	int Compare(CMyString const & str) const;
private:
	std::unique_ptr<char[]> CreateString(size_t length);
	std::unique_ptr<char[]> m_chars;
	size_t m_length;
};
CMyString operator +(const CMyString & leftString, const CMyString & rightString);
CMyString operator+(const string  & leftString, CMyString const & rightString);
CMyString operator+(const char * leftString, CMyString const & rightString);
bool operator !=(const CMyString & leftString, const CMyString & rightString);
bool operator ==(const CMyString & leftString, const CMyString & rightString);
bool operator <(const CMyString &leftString, const CMyString &rightString);
bool operator >(const CMyString &leftString, const CMyString &rightString);
bool operator <=(const CMyString &leftString, const CMyString &rightString);
bool operator >=(const CMyString &leftString, const CMyString &rightString);
std::istream & operator>>(std::istream & strm, CMyString & str);
std::ostream & operator<<(std::ostream & strm, CMyString const & str);