#include "StopWatch.h"
#include <iostream>
using namespace std;

void Sort_Shell(int arr[], int iSize);

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
	Sort_Shell(arr, iSize);
	t1.Stop();
	cout << "\n���� ���� : Shell_Sort\n";
	cout << "\n�ҿ� �ð� : " << t1.Get_ElapsedTime() << "ms\n";
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
		for (int h = 0; h < iPivot; ++h) // n-���� (n�� ���� Pivot�� ���� ����)
		{
			for (int i = iPivot+h; i < iSize; i += iPivot) // �� �ε���(Pivot), ��������
			{
				iMin = arr[i];
				for (int j = i; j >= 0; j -= iPivot) // �� �ε��� �� ��ҵ��� ���ʷ� �� �ε����� ��
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
	cout << "\n���ĵ� ������ : ";
	for (int i = 0; i < iSize; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}