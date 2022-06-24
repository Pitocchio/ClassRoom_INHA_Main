#include <iostream>
using namespace std;

void Swap(int arr[], int a, int b) { int t = arr[a]; arr[a] = arr[b]; arr[b] = t; }

void Sort_Divide(int arr[], int iStart, int iEnd);

void Sort_Merge(int arr[], int iStart, int iMid, int iEnd);

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

	Sort_Divide(arr, 0, iSize - 1);

	Print_SortedData(arr, iSize);

	delete[] arr;
}

void Sort_Divide(int arr[], int iStart, int iEnd) // ����
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

void Sort_Merge(int arr[], int iStart, int iMid, int iEnd) // �պ�
{
	int* temp = new int[iEnd - iStart + 1]; // ���ο� �ӽ� �迭

	int iS1 = iStart; // ù��° �迭 ù �ε����� �ش�
	int iS2 = iMid + 1; // �ι�° �迭 ù �ε����� �ش�
	int k(0);

	while (iS1 <= iMid && iS2 <= iEnd)
	{
		if (arr[iS1] < arr[iS2])
			temp[k++] = arr[iS1++];
		else
			temp[k++] = arr[iS2++];
	}

	if (iS1 < iMid+1)
		while (iS1 < iMid + 1)
			temp[k++] = arr[iS1++];
	else if (iS2 < iEnd)
		while (iS2 <= iEnd)
			temp[k++] = arr[iS2++];


	for (int i = iStart, j = 0; i <= iEnd; ++i, ++j) // �� ���ο� �ӽ� �迭 �տ������� �ϳ��� ������ ���� �迭�� �ٽ� ����
	{
		arr[i] = temp[j]; 
	}

	delete[] temp;
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