#include <iostream>
#include "StopWatch.h"
using namespace std;


void Sort_Divide(int arr[], int iStart, int iEnd);

void Sort_Merge(int arr[], int iStart, int iMid, int iEnd);

void Print_SortedData(int arr[], int iSize);

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
	Sort_Divide(arr, 0, iSize - 1);
	t1.Stop();
	cout << "\n정렬 종류 : Merge_Sort\n";
	cout << "\n소요 시간 : " << t1.Get_ElapsedTime() << "ms\n";

	delete[] arr;
}

void Sort_Divide(int arr[], int iStart, int iEnd) // 분할
{
	int iMid(0);

	if (iStart < iEnd)
	{
		iMid = (iStart + iEnd) / 2;

		Sort_Divide(arr, iStart, iMid);

		Sort_Divide(arr, iMid + 1, iEnd);

		Sort_Merge(arr, iStart, iMid, iEnd); 
	}
}

void Sort_Merge(int arr[], int iStart, int iMid, int iEnd) // 합병
{
	int* temp = new int[iEnd - iStart + 1]; // 새로운 임시 배열

	int iS1 = iStart; // 첫번째 배열 첫 인덱스에 해당 (start ~ mid)
	int iS2 = iMid + 1; // 두번째 배열 첫 인덱스에 해당 (mid ~ end)
	int k(0);

	while (iS1 <= iMid && iS2 <= iEnd) // 두 배열 중 하나라도 끝에 도달하면 종료
	{
		if (arr[iS1] < arr[iS2])
			temp[k++] = arr[iS1++];
		else
			temp[k++] = arr[iS2++];
	}

	if (iS1 < iMid+1) // 남은 배열 처리
		while (iS1 < iMid + 1)
			temp[k++] = arr[iS1++];
	else if (iS2 <= iEnd)
		while (iS2 <= iEnd)
			temp[k++] = arr[iS2++];


	for (int i = iStart, j = 0; i <= iEnd; ++i, ++j) // 위 새로운 임시 배열 앞에서부터 하나씩 가져와 기존 배열에 다시 저장
	{
		arr[i] = temp[j]; 
	}

	delete[] temp;
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