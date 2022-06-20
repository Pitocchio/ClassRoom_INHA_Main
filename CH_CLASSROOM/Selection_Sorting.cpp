#include <iostream>
using namespace std;

void Swap(int arr[], int a, int b) { int t = arr[a]; arr[a] = arr[b]; arr[b] = t; }

void Sort_Selection(int arr[], int iSize);

void Print_SortedData(int arr[], int iSize);

int main(void)
{
	int iSize(0);

	cout << "�������� ������ �Է����ּ��� => ";
	cin >> iSize;

	int* arr = new int[iSize];
	cout << "\n�����͸� �Է����ּ���. (�������� ����, �Է� ����� ����) => ";

	for (int i = 0; i < iSize; ++i)
	{
		cin >> arr[i];
	}

	Sort_Selection(arr, iSize);

	Print_SortedData(arr, iSize);

	delete[] arr;
}

void Sort_Selection(int arr[], int iSize)
{
	int iMinIndex(0);
	for (int i = 0; i < iSize-1; ++i)
	{
		iMinIndex = i;
		for (int j = i+1; j < iSize; ++j)
		{
			if (arr[i] > arr[j])
				iMinIndex = (arr[iMinIndex] > arr[j]) ? j : iMinIndex;
		}

		Swap(arr, i, iMinIndex);
	}
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