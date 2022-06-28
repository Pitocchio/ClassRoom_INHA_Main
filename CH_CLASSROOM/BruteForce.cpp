#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

void BruteForce(char txt1[], char txt2[]);

int main(void)
{
	int iOriginNum, iSearchNum;

	cout << "������ �Է��� ������ ������ �Է����ּ��� => ";
	cin >> iOriginNum;
	cin.get();
	char* OriginTxt = new char[iOriginNum + 1];
	cout << "���� ���ڿ��� �Է����ּ��� => ";
	scanf("%s", OriginTxt);
	cout << "\n\n";

	cout << "�˻��� ���ڿ��� ������ �Է����ּ��� => ";
	cin >> iSearchNum;
	cin.get();
	char* SearchTxt = new char[iSearchNum + 1];
	cout << "�˻��� ���ڿ��� �Է����ּ��� => ";
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