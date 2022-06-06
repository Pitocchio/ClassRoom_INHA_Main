#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
using namespace std;

// 백준 문자열 알파벳찾기

#define SIZE 101

void Calculate_Datas(char* arr[]);

int main(void)
{
	char arr[SIZE]{ 0 };
	int i(0);

	// 사용자로부터 문자열을 입력받음
	scanf("%c", &arr[i]);
	while ((97 <= arr[i]) && (arr[i] <= 122))
	{
		scanf("%c", &arr[++i]);
	}

	// 입력받은 문자열 계산
	void Calculate_Datas(&arr);




	return 0;
}

void Calculate_Datas(char* arr[])
{

	bool bFlag = false;

	for (int i = 'a'; i <= 'z'; ++i) // a to z
	{
		for (int j = 0; j < SIZE; ++j) // 여기를 효율적으로 바꾸어야 함
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