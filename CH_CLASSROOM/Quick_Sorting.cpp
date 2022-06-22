#include "StopWatch.h"
#include <iostream>
using namespace std;

void Swap(int arr[], int a, int b) { int t = arr[a]; arr[a] = arr[b]; arr[b] = t; }

void Sort_Quick(int arr[], int iPl, int iPr);

void Print_SortedData(int arr[], int iSize);

int main(void)
{
	StopWatch t1;
	int iSize(0);

	cout << "데이터의 개수를 입력해주세요 => ";
	cin >> iSize;

	int* arr = new int[iSize];
	cout << "\n데이터를 입력해주세요. (공백으로 구분, 입력 종료시 엔터) => ";
	for (int i = 0; i < iSize; ++i)
	{
		cin >> arr[i];
	}
	/*srand(time(NULL));
	for (int i = 0; i < iSize; ++i)
	{
		int random = rand() % iSize + 1;
		arr[i] = random;
	}

	t1.Start();*/
	Sort_Quick(arr, 0, iSize);
	/*t1.Stop();
	cout << "\n정렬 종류 : Shell_Sort\n";
	cout << "\n소요 시간 : " << t1.Get_ElapsedTime() << "ms\n";*/
	Print_SortedData(arr, iSize);

	delete[] arr;
}

void Sort_Quick(int arr[], int iPl, int iPr)
{
	int iPivot = (iPl + iPr) / 2;

	int i = iPl;
	int j = iPr-1;

	while (i <= j)
	{
		while(arr[i] <= arr[iPivot])
			++i;
		
		while(arr[j] >= arr[iPivot])
			--j;
		
		if (i <= j)
		{
			Swap(arr, i, j);
			++i;
			--j;
		}
	}
	if (iPl < j) 
		Sort_Quick(arr, iPl, j);
	if (i < iPr)
		Sort_Quick(arr, i, iPr);
}

void Print_SortedData(int arr[], int iSize)
{
	cout << "\n정렬된 데이터 : ";
	for (int i = 0; i < iSize; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}