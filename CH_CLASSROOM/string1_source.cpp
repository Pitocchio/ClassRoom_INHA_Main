#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <string>
#include <cctype>
#include "string1.h"
using std::cin;
using std::cout;

int String::num_strings = 0;

// ����ƽ �޼���
int String::HowMany()
{
	return num_strings;
}

// Ŭ���� �޼���
String::String(const char* s)		// C��Ÿ�� ���ڿ��κ��� String�� ����
{
	len = std::strlen(s);			// ���ڿ��� ũ�� ����
	str = new char[len + 1];		// ������ ����
	std::strcpy(str, s);			// ������ �ʱ�ȭ
	num_strings++;					// ��ü ī��Ʈ
}
String::String()
{
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}
String::String(const String& st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
}
String::~String()
{
	--num_strings;
	delete[] str;
}


// �����ε� ������ �޼���
String& String::operator = (const String& st)	// String�� String�� ����
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}
String& String::operator = (const char* s)		// C��Ÿ�� ���ڿ��� String�� ����
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}
char& String::operator [] (int i)				// const�� �ƴ� String�� �б�-���� ���� ���� ����
{
	return str[i];
}
const char& String::operator[] (int i) const	// const String�� �б�-���� ���� ���� ����
{
	return str[i];
}

// �����ε� ������ ������
bool operator<(const String& st1, const String& st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String& st1, const String& st2)
{
	return st2 < st1;
}
bool operator==(const String& st1, const String& st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}
ostream& operator<<(ostream& os, const String& st)
{
	os << st.str;
	return os;
 }
istream& operator>>(istream& is, String& st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}

// ���α׷��� ����2
String operator+(const String& st1, const String& st2)
{
	char* temp = new char[st1.length() + st2.length() + 1];

	strcpy(temp, st1.str);
	strcat(temp, st2.str);
	String strTemp(temp);

	return strTemp;
}
void String::StringUp()
{
	for (int i = 0; i < len; ++i)
	{
		str[i] = toupper(str[i]);
	}
}
void String::StringLow()
{
	for (int i = 0; i < len; ++i)
	{
		str[i] = tolower(str[i]);
	}
}
int String::has(const char ch)
{
	int iCount(0);

	for (int i = 0; i < len; ++i)
	{
		if (str[i] == ch)
			iCount++;
	}

	return iCount;
}