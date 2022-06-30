#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

#define Large 65

void Set_arrTable(int arrTable[], char arrSearchTxt[], int iSearchNum);
void Compare_String(int arrTable[], char arrOriginTxt[], char arrSearchTxt[], int iSearchNum);
//void Compare_String_withPrint(int arrTable[], char arrOriginTxt[], char arrSearchTxt[], int iOriginNum, int iSearchNum);


int main(void)
{
	int iOriginNum, iSearchNum;

	// Get the Data
	cout << "원본에 입력할 문자의 개수를 입력해주세요 => ";
	cin >> iOriginNum;
	char* arrOriginTxt = new char[iOriginNum + 1];
	cin.ignore();
	cout << "원본 문자열을 입력해주세요(대문자) => ";
	fgets(arrOriginTxt, iOriginNum + 1, stdin);
	cin.ignore();

	cout << "검색할 문자열의 개수를 입력해주세요=> ";
	cin >> iSearchNum;
	cin.ignore();
	char* arrSearchTxt = new char[iSearchNum + 1];
	cout << "검색할 문자열을 입력해주세요(대문자) => ";
	fgets(arrSearchTxt, iSearchNum + 1, stdin);


	int* arrTable = new int[26]; 
	Set_arrTable(arrTable, arrSearchTxt, iSearchNum);

	Compare_String(arrTable, arrOriginTxt, arrSearchTxt, iSearchNum);
	//Compare_String_withPrint(arrTable, arrOriginTxt, arrSearchTxt, iOriginNum, iSearchNum);

	
	delete[] arrOriginTxt;
	delete[] arrSearchTxt;
	delete[] arrTable;

	return 0;
}

void Set_arrTable(int arrTable[], char arrSearchTxt[], int iSearchNum)
{
	fill_n(arrTable, 26, iSearchNum);
	for (int i = 0; i < iSearchNum; ++i)
	{
		if (i < iSearchNum - 1)
		{
			arrTable[(int)arrSearchTxt[i] - Large] = iSearchNum - i - 1;
			continue;
		}

		arrTable[(int)arrSearchTxt[i] - Large] = iSearchNum;
	}
}

void Compare_String(int arrTable[], char arrOriginTxt[], char arrSearchTxt[], int iSearchNum)
{
	int iOrgIdx(iSearchNum - 1);
	int iSrcIdx(iSearchNum - 1);
	int iFlag(0);
	while (1)
	{
		if (arrOriginTxt[iOrgIdx] == arrSearchTxt[iSrcIdx])
		{
			iOrgIdx--;
			iSrcIdx--;
			iFlag++;
			if (iFlag == iSearchNum)
				break;
		}
		else
		{
			iOrgIdx += arrTable[(int)arrOriginTxt[iOrgIdx] - Large] + iFlag;
			iSrcIdx = iSearchNum - 1;
			iFlag = 0;
		}
	}
}

// PRINT
/*
void Compare_String_withPrint(int arrTable[], char arrOriginTxt[], char arrSearchTxt[], int iOriginNum, int iSearchNum)
{
	int iOrgIdx(iSearchNum - 1);
	int iSrcIdx(iSearchNum - 1);
	int iPrintSrcIdx(iSearchNum - 1);
	int iFlag(0);

	while (1)
	{
		cout << "\n\n";
		for (int i = 0; i < iOriginNum; ++i)
		{
			cout << arrOriginTxt[i];
		}
		cout << "\n";
		for (int i = 0; i < iOrgIdx; ++i)
		{
			cout << " ";
		}
		cout << "+" << "\n";

		for (int i = 0; i < iPrintSrcIdx - iSearchNum+1; ++i)
		{
			cout << " ";
		}

		for (int i = 0; i < iSearchNum; ++i)
		{
			cout << arrSearchTxt[i];
		}
		cout << "\n";


		if (arrOriginTxt[iOrgIdx] == arrSearchTxt[iSrcIdx])
		{
			iOrgIdx--;
			iSrcIdx--;
			iFlag++;
			if (iFlag == iSearchNum)
				break;
		}
		else
		{
			iOrgIdx += arrTable[(int)arrOriginTxt[iOrgIdx] - Large] + iFlag;
			iSrcIdx = iSearchNum - 1;
			iPrintSrcIdx = iOrgIdx;
			iFlag = 0;
		}
	}
}
*/
