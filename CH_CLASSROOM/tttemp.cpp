#include <iostream>
using namespace std;

void Swap(int arr[], int& a, int& b) { int t = arr[a]; arr[a] = arr[b]; arr[b] = t; }

void Print(int arr[], int& a, int& b, int iSize);

int main(void)
{
	int arr[7] = { 6, 4, 8, 3, 1, 9, 7 };
	int iSize = sizeof(arr) / sizeof(arr[0]);
	int iMinIndex(0);


	for (int i = 0; i < iSize; ++i)
	{
		iMinIndex = i;
		for (int j = i + 1; j < iSize; ++j)
		{

			if (arr[iMinIndex] > arr[j])
			{
				iMinIndex = j;
			}
		}

		Print(arr, i, iMinIndex, iSize);
		Swap(arr, i, iMinIndex);
		cout << endl;
	}
}

void Print(int arr[], int& a, int& b, int iSize)
{
	if (a != 6)
	{
		for (int i = 0; i < iSize; ++i)
		{
			if (i == b)
				cout << "\t+";
			else if (i == a)
				cout << "*";
			else
				cout << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < iSize; ++i)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;

}