#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// 백준 함수 - 셀프넘버

#define SIZE 10000

void Get_NotSelfNums(vector <int>& vecNotSelfNums); 	// 10,000이하의 셀프넘버가 아닌 수들을 구함 (vecNotSelfNums 세팅)

int Get_NotSelfNum(int iN); // 셀프넘버가 아닌 수들을 반환 (위 함수에서 사용)

void Set_SelfNums(vector <int>& vecSelfNums, vector <int>& vecNotSelfNums); // 셀프넘버 세팅 (vecSelfNums에서 vecNotSelfNums을 빼주는 형식)

void Print_SelfNums(vector <int>& vecSelfNums); // 셀프넘버 출력

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector <int> vecSelfNums, vecNotSelfNums;
	int iTemp(0);

	for (int i = 0; i <= SIZE; ++i) // (vecSelfNums 세팅)
	{
		vecSelfNums.push_back(i);
	}

	Get_NotSelfNums(vecNotSelfNums);

	Set_SelfNums(vecSelfNums, vecNotSelfNums);

	Print_SelfNums(vecSelfNums);

	return 0;
}

void Get_NotSelfNums(vector <int>& vecNotSelfNums)
{
	int iTemp(0);

	for (int i = 0; i <= SIZE; ++i)
	{
		iTemp = Get_NotSelfNum(i);

		if (iTemp <= SIZE)
			vecNotSelfNums.push_back(iTemp);
	}
}

int Get_NotSelfNum(int iN)
{
	int iSum(iN), iTemp(0);

	for (int i = log10(SIZE); i >= 0; --i)
	{
		iSum += iN / pow(10, i);
		if (iN != iSum)
		{
			iTemp = (iN / pow(10, i));
			iN -= iTemp * pow(10, i);
		}
	}

	return iSum;
}

void Set_SelfNums(vector <int>& vecSelfNums, vector <int>& vecNotSelfNums)
{
	int iIndex(0);
	for (int i = 0; i < vecNotSelfNums.size(); ++i)
	{
		iIndex = vecNotSelfNums[i];

		vecSelfNums[iIndex] = NULL;
	}
}

void Print_SelfNums(vector <int>& vecSelfNums)
{
	for (int i = 0; i < vecSelfNums.size(); ++i)
	{
		if (vecSelfNums[i] != NULL)
			cout << vecSelfNums[i] << "\n";
	}
}
