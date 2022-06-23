#include "StopWatch.h"
#include <iostream>
using namespace std;

void Swap(int arr[], int a, int b) { int t = arr[a]; arr[a] = arr[b]; arr[b] = t; }

void Sort_Quick(int arr[], int iPl, int iPr);

int main(void)
{
	StopWatch t1;
	int iSize(0);

	cout << "�������� ������ �Է����ּ��� => ";
	cin >> iSize;

	int* arr = new int[iSize];
	/*cout << "\n�����͸� �Է����ּ���. (�������� ����, �Է� ����� ����) => ";
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
	cout << "\n���� ���� : Quick_Sort\n";
	cout << "\n�ҿ� �ð� : " << t1.Get_ElapsedTime() << "ms\n";

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
