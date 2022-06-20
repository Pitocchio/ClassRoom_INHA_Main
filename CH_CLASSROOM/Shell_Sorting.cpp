#include <iostream>
using namespace std;
/*
���� �� 

���� ������ �Ű澲������ ¦�� Ȧ�� ������� ������ 2 ��(GAP)����

GAP�� �������� ��������!


*/
void Swap(int arr[], int a, int b) { int t = arr[a]; arr[a] = arr[b]; arr[b] = t; }

void Sort_Insertion(int arr[], int iSize, int iPivot);

void Sort_Shell(int arr[], int iSize);

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
			for (int j = 0; j < iSize / iTerm; ++j) // 1h�� �ݺ���
			{
				Sort_Insertion(arr, iSize, )
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