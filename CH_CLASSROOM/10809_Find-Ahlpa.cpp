#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
using namespace std;

// ���� ���ڿ� ���ĺ�ã��

#define SIZE 101

void Calculate_Datas(char* arr[]);

int main(void)
{
	char arr[SIZE]{ 0 };
	int i(0);

	// ����ڷκ��� ���ڿ��� �Է¹���
	scanf("%c", &arr[i]);
	while ((97 <= arr[i]) && (arr[i] <= 122))
	{
		scanf("%c", &arr[++i]);
	}

	// �Է¹��� ���ڿ� ���
	void Calculate_Datas(&arr);




	return 0;
}

void Calculate_Datas(char* arr[])
{

	bool bFlag = false;

	for (int i = 'a'; i <= 'z'; ++i) // a to z
	{
		for (int j = 0; j < SIZE; ++j) // ���⸦ ȿ�������� �ٲپ�� ��
		{

			if (i == *arr[j])
			{
				cout << j << " ";
				bFlag = true;
				break;
			}
		}
		if (!bFlag)
			cout << -1 << " ";
		bFlag = false;
	}
}