#include <iostream>
using namespace std;
/*
수빈 팁 

갭은 나머지 신경쓰지말고 짝수 홀수 상관없이 나누기 2 값(GAP)으로

GAP을 기준으로 삽입정렬!


*/
void Swap(int arr[], int a, int b) { int t = arr[a]; arr[a] = arr[b]; arr[b] = t; }

void Sort_Insertion(int arr[], int iSize, int iPivot);

void Sort_Shell(int arr[], int iSize);

void Print_SortedData(int arr[], int iSize);

int main(void)
{
	int iSize(0);

	cout << "데이터의 갯수를 입력해주세요 => ";
	cin >> iSize;

	int* arr = new int[iSize];
	cout << "\n데이터를 입력해주세요. (공백으로 구분, 입력 종료시 엔터) => ";

	for (int i = 0; i < iSize; ++i)
	{
		cin >> arr[i];
	}

	Sort_Shell(arr, iSize);

	Print_SortedData(arr, iSize);

	delete[] arr;
}

void Sort_Insertion(int arr[], int iSize, int iPivot)
{
	int iMin(0);
	for (int i = 1; i < iSize; ++i) 
	{
		iMin = arr[i];
		for (int j = i; j >= 0; --j) 
		{
			if (iMin < arr[j - 1] && (j - 1) >= 0)
				arr[j] = arr[j - 1];
			else
			{
				arr[j] = iMin;
				break;
			}
		}
	}
}


void Sort_Shell(int arr[], int iSize)
{
	int iTerm = iSize;
	while (iTerm >= 1)
	{
		iTerm /= 2;
		
		for (int i = 0; i < iTerm; ++i) // h
		{
			for (int j = 0; j < iSize / iTerm; ++j) // 1h당 반복수
			{
				Sort_Insertion(arr, iSize, )
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