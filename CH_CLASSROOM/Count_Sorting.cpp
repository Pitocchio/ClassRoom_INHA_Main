#include "StopWatch.h"
#include <iostream>
using namespace std;

void Swap(int arr[], int a, int b) { int t = arr[a]; arr[a] = arr[b]; arr[b] = t; }

void Sort_Count(int arr[], int iSize);


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
	Sort_Count(arr, iSize);
	t1.Stop();
	cout << "\n정렬 종류 : Count_Sort\n";
	cout << "\n소요 시간 : " << t1.Get_ElapsedTime() << "ms\n";

	delete[] arr;
}

void Sort_Count(int arr[], int iSize)
{
	int iMax = 0;
	for (int i = 0; i < iSize; ++i)
		iMax = (iMax < arr[i]) ? arr[i] : iMax;
	

	// 1. 도수 분포표 생성 (등장 횟수 카운트)
	int* arrF = new int[iMax + 1]{ 0 };
	for (int i = 0; i < iSize; ++i)
		arrF[arr[i]]++;
	

	// 2. 누적 도수 분포표 생성 (등장 횟수를 누적합으로 변환)
	for (int i = 1; i <= iMax; ++i)
		arrF[i] += arrF[i - 1];

	// 3.최종 배열 생성
	int* arrB = new int[iSize];
	for (int i = iSize-1; i >= 0; --i)
		arrB[--arrF[arr[i]]] = arr[i];
	

	delete[] arrF;
	delete[] arrB;
}
