#include "StopWatch.h"
#include <iostream>
using namespace std;

void Swap(int arr[], int a, int b) { int t = arr[a]; arr[a] = arr[b]; arr[b] = t; }

void Sort_Bubble(int arr[], int iSize);

void Print_SortedData(int arr[], int iSize);

int main(void)
{
	StopWatch t1;
	int iSize(0);

	cout << "데이터의 개수를 입력해주세요 => ";
	cin >> iSize;

	int* arr = new int[iSize];
	//cout << "\n데이터를 입력해주세요. (공백으로 구분, 입력 종료시 엔터) => ";
	/*for (int i = 0; i < iSize; ++i)
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
	Sort_Bubble(arr, iSize);
	t1.Stop();
	cout << "\n정렬 종류 : Bubble_Sort\n";
	cout << "\n소요 시간 : " << t1.Get_ElapsedTime() << "ms\n";
	//Print_SortedData(arr, iSize);

	delete[] arr;
}

void Sort_Bubble(int arr[], int iSize)
{
	for (int i = 0; i < iSize; ++i)
	{
		for (int j = 1; j < iSize; ++j)
		{
			if (arr[j - 1] > arr[j])
			{
				Swap(arr, j - 1, j);
			}
		}
	}
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