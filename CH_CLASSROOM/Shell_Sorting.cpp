#include "StopWatch.h"
#include <iostream>
using namespace std;

void Sort_Shell(int arr[], int iSize);

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
	Sort_Shell(arr, iSize);
	t1.Stop();
	cout << "\n정렬 종류 : Shell_Sort\n";
	cout << "\n소요 시간 : " << t1.Get_ElapsedTime() << "ms\n";
	//Print_SortedData(arr, iSize);

	delete[] arr;
}


void Sort_Shell(int arr[], int iSize)
{
	int iPivot(0);
	int iMin(0);

	iPivot = iSize/2;
	 
	while (iPivot >= 1)
	{
		for (int h = 0; h < iPivot; ++h) // n-정렬 (n의 값은 Pivot의 값과 같다)
		{
			for (int i = iPivot+h; i < iSize; i += iPivot) // 현 인덱스(Pivot), 삽입정렬
			{
				iMin = arr[i];
				for (int j = i; j >= 0; j -= iPivot) // 현 인덱스 앞 요소들을 차례로 현 인덱스와 비교
				{
					if (iMin < arr[j - iPivot] && (j - iPivot) >= 0) 
						arr[j] = arr[j - iPivot];
					else
					{
						arr[j] = iMin;
						break;
					}
				}
			}
		}
		iPivot /= 2;
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