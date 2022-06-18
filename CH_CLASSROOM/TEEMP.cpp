#include <iostream>
using namespace std;

void Swap(int arr[], int& a, int& b) { int t = arr[a]; arr[a] = arr[b]; arr[b] = t; }

void Sort(int arr[], int iSize);

void Print(int *arr, int iSize);

int main(void)
{
	int iSize(0);
	cout << "입력할 데이터의 갯수를 입력해주세요 => ";
	cin >> iSize;

	int* arr = new int[iSize];
	cout << "\n데이터를 입력해주세요 (데이터 간 공백으로 구분) => ";
	for (int i = 0; i < iSize; ++i)
	{
		cin >> arr[i];
	}

	Sort(arr, iSize);

	return 0;
}

void Sort(int arr[], int iSize)
{
	int iIndex(0);
	cout << "\n===============\n\n";
	for (int i = 1; i < iSize; ++i)
	{
		iIndex = i;
		for (int j = i - 1; j >= 0; --j)
		{
			if (arr[j] > arr[iIndex])
			{
				Swap(arr, j, iIndex);

				iIndex--;
			}
		}
		Print(arr, iSize);
	}
	cout << "===============\n\n";

}

void Print(int* arr, int iSize)
{

	for (int i = 0; i < iSize; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << "\n\n";
}