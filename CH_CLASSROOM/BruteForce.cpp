#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

void BruteForce(char txt1[], char txt2[]);

int main(void)
{
	int iOriginNum, iSearchNum;

	cout << "원본에 입력할 문자의 개수를 입력해주세요 => ";
	cin >> iOriginNum;
	cin.get();
	char* OriginTxt = new char[iOriginNum + 1];
	cout << "원본 문자열을 입력해주세요 => ";
	scanf("%s", OriginTxt);
	cout << "\n\n";

	cout << "검색할 문자열의 개수를 입력해주세요 => ";
	cin >> iSearchNum;
	cin.get();
	char* SearchTxt = new char[iSearchNum + 1];
	cout << "검색할 문자열을 입력해주세요 => ";
	scanf("%s", SearchTxt);

	BruteForce(OriginTxt, SearchTxt);
	
	delete[] OriginTxt;
	delete[] SearchTxt;
	
	return 0;
}

void BruteForce(char txt1[], char txt2[])
{
	int iSearchIndex = 0;

	for (int i = 0; i < sizeof(txt1); ++i)
	{
		for (int j = i; j <= sizeof(txt2); ++j)
		{
			if (txt1[j] != txt2[iSearchIndex])
			{
				iSearchIndex = 0;
				break;
			}
			iSearchIndex++;
			if (j == sizeof(txt2))
				break;
		}
	}
}