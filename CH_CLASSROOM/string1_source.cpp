#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <string>
#include <cctype>
#include "string1.h"
using std::cin;
using std::cout;

int String::num_strings = 0;

// 스태틱 메서드
int String::HowMany()
{
	return num_strings;
}

// 클래스 메서드
String::String(const char* s)		// C스타일 문자열로부터 String을 생성
{
	len = std::strlen(s);			// 문자열의 크기 설정
	str = new char[len + 1];		// 기억공간 대입
	std::strcpy(str, s);			// 포인터 초기화
	num_strings++;					// 객체 카운트
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


// 오버로딩 연산자 메서드
String& String::operator = (const String& st)	// String을 String에 대입
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}
String& String::operator = (const char* s)		// C스타일 문자열을 String에 대입
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}
char& String::operator [] (int i)				// const가 아닌 String에 읽기-쓰기 개별 문자 접근
{
	return str[i];
}
const char& String::operator[] (int i) const	// const String에 읽기-쓰기 개별 문자 접근
{
	return str[i];
}

// 오버로딩 연산자 프렌드
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

// 프로그래밍 연습2
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