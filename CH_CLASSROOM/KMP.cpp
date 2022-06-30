#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

void Set_arrTable(int arrTable[], char arrSearchTxt[], int iSearchNum);
void Compare_arr(int arrTable[], char arrOriginTxt[], char arrSearchTxt[], int iSearchNum);

int main(void)
{
	int iOriginNum, iSearchNum;
	
	cout << "������ �Է��� ������ ������ �Է����ּ��� => ";
	cin >> iOriginNum;
	char* arrOriginTxt = new char[iOriginNum + 1];
	cin.ignore();
	cout << "���� ���ڿ��� �Է����ּ��� => ";
	fgets(arrOriginTxt, iOriginNum + 1, stdin);
	cin.ignore();

	cout << "�˻��� ���ڿ��� ������ �Է����ּ��� => ";
	cin >> iSearchNum;
	cin.ignore();
	char* arrSearchTxt = new char[iSearchNum + 1];
	cout << "�˻��� ���ڿ��� �Է����ּ��� => ";
	fgets(arrSearchTxt, iSearchNum + 1, stdin);

	int*arrTable = new int[iSearchNum] {0};

	Set_arrTable(arrTable, arrSearchTxt, iSearchNum);
	Compare_arr(arrTable, arrOriginTxt, arrSearchTxt, iSearchNum);

	delete[] arrOriginTxt;
	delete[] arrSearchTxt;
	delete[] arrTable;

	return 0;
}



void Set_arrTable(int arrTable[], char arrSearchTxt[], int iSearchNum)
{
	int i = 0;
	int j = 1;

	while (j < iSearchNum)
	{
		if (i != 0)
		{
			if (arrSearchTxt[i] == arrSearchTxt[j])
			{
				arrTable[j] = i + 1;
				i++;
				j++;
			}
			else
			{
				i = arrTable[i - 1];
			}
			continue;
		}

		if (arrSearchTxt[i] == arrSearchTxt[j])
		{
			arrTable[j]++;
			i++;
			j++;
		}
		else
		{
			arrTable[j] = 0;
			j++;
		}
	}
}

void Compare_arr(int arrTable[], char arrOriginTxt[], char arrSearchTxt[], int iSearchNum)
{
	int i = 0;
	int j = 0;
	while (j < iSearchNum)
	{
		if (j != 0)
		{
			if (arrOriginTxt[i] == arrSearchTxt[j])
			{
				i++;
				j++;
			}
			else
			{
				j = arrTable[j - 1];
			}
			continue;
		}

		if (arrOriginTxt[i] == arrSearchTxt[j])
		{
			i++;
			j++;
		}
		else
		{
			i++;
		}
	}
}
