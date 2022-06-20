#include <iostream>
using namespace std;

void Sort_Insertion(int arr[], int iSize);

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

	Sort_Insertion(arr, iSize);

	Print_SortedData(arr, iSize);

	delete[] arr;
}

void Sort_Insertion(int arr[], int iSize)
{
	int iMin(0);
	for (int i = 1; i < iSize; ++i) // �� �ε���
	{
		iMin = arr[i];
		for (int j = i; j>=0; --j) // �� �ε��� �� ��ҵ��� ���ʷ� �� �ε����� ��
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
	cout << "\n���ĵ� ������ : ";
	for (int i = 0; i < iSize; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";

}