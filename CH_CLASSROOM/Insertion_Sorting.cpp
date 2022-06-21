#include "StopWatch.h"
#include <iostream>
using namespace std;

void Sort_Insertion(int arr[], int iSize);

void Print_SortedData(int arr[], int iSize);

int main(void)
{
	StopWatch t1;
	int iSize(0);

	cout << "�������� ������ �Է����ּ��� => ";
	cin >> iSize;

	int* arr = new int[iSize];
	//cout << "\n�����͸� �Է����ּ���. (�������� ����, �Է� ����� ����) => ";
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
	cout << "\n���� ���� : Insertion_Sort\n";
	cout << "\n�ҿ� �ð� : " << t1.Get_ElapsedTime() << "ms\n";
	//Print_SortedData(arr, iSize);

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