#include "StopWatch.h"
#include <iostream>
using namespace std;

void Swap(int arr[], int a, int b) { int t = arr[a]; arr[a] = arr[b]; arr[b] = t; }

void Sort_Quick(int arr[], int iPl, int iPr);

int main(void)
{
	StopWatch t1;
	int iSize(0);

	cout << "데이터의 개수를 입력해주세요 => ";
	cin >> iSize;

	int* arr = new int[iSize];
	/*cout << "\n데이터를 입력해주세요. (공백으로 구분, 입력 종료시 엔터) => ";
	for (int i = 0; i < iSize; ++i)
	{
		cin >> arr[i];
	}*/
	srand(time(NULL));
	for (int i = 0; i < iSize; ++i)
	{
		int random = rand() % iSize + 1;
		arr[i] = random;
	}

	t1.Start();
	Sort_Quick(arr, 0, iSize - 1);
	t1.Stop();
	cout << "\n정렬 종류 : Quick_Sort\n";
	cout << "\n소요 시간 : " << t1.Get_ElapsedTime() << "ms\n";

	delete[] arr;
}

void Sort_Quick(int arr[], int iPl, int iPr)
{
	if (iPl >= iPr)
		return;

	int i = iPl;
	int j = iPr;
	int iPivot = arr[(i + j) / 2];

	while (i <= j)
	{
		while(arr[i] <iPivot)
			i++;
		
		while(arr[j] > iPivot)
			j--;
		
		if (i <= j)
		{
			Swap(arr, i, j);
			i++;
			j--;
		}
	}
	Sort_Quick(arr, iPl, j);
	Sort_Quick(arr, i, iPr);
}
