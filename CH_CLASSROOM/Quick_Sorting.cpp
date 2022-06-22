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

	cout << "�������� ������ �Է����ּ��� => ";
	cin >> iSize;

	int* arr = new int[iSize];
	cout << "\n�����͸� �Է����ּ���. (�������� ����, �Է� ����� ����) => ";
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
	cout << "\n���� ���� : Shell_Sort\n";
	cout << "\n�ҿ� �ð� : " << t1.Get_ElapsedTime() << "ms\n";*/
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
	cout << "\n���ĵ� ������ : ";
	for (int i = 0; i < iSize; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}