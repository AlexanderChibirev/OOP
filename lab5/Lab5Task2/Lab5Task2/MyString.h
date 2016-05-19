#pragma once
using namespace std;
class CMyString
{
public:
	
	CMyString(); // ����������� �� ��������� 
	CMyString(const char * pString); // �����������, ���������������� ������ ������� ������. � ����������� ������� ��������
	CMyString(const char * pString, size_t length);// �����������, ���������������� ������ ������� �� ����������� ������� �������� �����
	CMyString(CMyString const& other);// ����������� �����������
	CMyString(CMyString && other);// ������������ ����������� (��� ������������, ����������� � C++11) ����������� ��������� � ������������ ���������� ������������ 
	CMyString(string const& stlString);// �����������, ���������������� ������ ������� �� ������ ����������� ���������� C++
	size_t GetLength() const;
	const char* GetStringData() const;
	CMyString SubString(size_t start, size_t length = SIZE_MAX) const;// ���������� ��������� � �������� ������� ������ �� ������ length ��������
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