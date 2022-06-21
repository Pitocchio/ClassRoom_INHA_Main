#include "StopWatch.h"
#include <iostream>
using namespace std;

void Sort_Insertion(int arr[], int iSize);

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
	Sort_Insertion(arr, iSize);
	t1.Stop();
	cout << "\n정렬 종류 : Insertion_Sort\n";
	cout << "\n소요 시간 : " << t1.Get_ElapsedTime() << "ms\n";
	//Print_SortedData(arr, iSize);

	delete[] arr;
}

void Sort_Insertion(int arr[], int iSize)
{
	int iMin(0);
	for (int i = 1; i < iSize; ++i) // 현 인덱스
	{
		iMin = arr[i];
		for (int j = i; j>=0; --j) // 현 인덱스 앞 요소들을 차례로 현 인덱스와 비교
		{
			if (iMin < arr[j-1] && (j - 1) >= 0)
				arr[j] = arr[j-1];
			else
			{
				arr[j] = iMin;
				break;
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