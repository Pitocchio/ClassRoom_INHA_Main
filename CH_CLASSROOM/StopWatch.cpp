#include <iostream>
#include <vector>
#include <ctime>
#include <numeric>
#include "StopWatch.h"

using namespace std;

#define SIZE 11
void Make_RandInt(vector<int>& VEC_ORIGIN, vector<int>& VEC_TEMP, vector<int>& VEC_RESULT, int input);
void Print_Items(vector<int>& VEC_RESULT);

int main(void)
{
	int input(0);
	vector <int> VEC_ORIGIN = { 1, 3, 3, 5, 5, 5, 10, 10, 10, 10, 38 };
	vector <int> VEC_TEMP(SIZE);
	vector <int> VEC_RESULT(SIZE);
	VEC_TEMP = VEC_ORIGIN;


	cout << "횟수를 입력해주세요 : ";
	cin >> input;

	// StopWatch 시작
	StopWatch s1;
	s1.Start();
	cout << endl << "시작 시각: " << s1.Get_StartTime() << endl;
	cout << endl << "==========================\n";


	// 확률 함수 
	Make_RandInt(VEC_ORIGIN, VEC_TEMP, VEC_RESULT, input);
	Print_Items(VEC_RESULT);


	// StopWatch 종료
	s1.Stop();
	cout << endl << endl << "==========================\n";
	cout << "종료 시각: " << s1.Get_EndTime() << endl;
	cout << "경과 시간: " << s1.Get_ElapsedTime() << "ms" << endl;
	

	return 0;
}

void Make_RandInt(vector<int>& vec1, vector<int>& vec2, vector<int>& vec3, int input)
{
	srand((unsigned int)time(NULL));
	int random(0);
	int sum(0);

	while (input > 0)
	{
		random = rand() % 100 + 1;
		if (random == 1) // 1%
		{
			random = 0;
		}
		else if ((1 < random) && (random < 5)) // 3%
		{
			random = 1;
		}
		else if ((4 < random) && (random < 8))
		{
			random = 2;
		}
		else if ((7 < random) && (random < 13)) // 5%
		{
			random = 3;
		}
		else if ((13 < random) && (random < 19))
		{
			random = 4;
		}
		else if ((18 < random) && (random < 24))
		{
			random = 5;
		}
		else if ((23 < random) && (random < 34)) // 10%
		{
			random = 6;
		}
		else if ((33 < random) && (random < 44))
		{
			random = 7;
		}
		else if ((43 < random) && (random < 54))
		{
			random = 8;
		}
		else if ((53 < random) && (random < 64))
		{
			random = 9;
		}
		else // 38%
			random = 10;

		sum = accumulate(vec2.begin(), vec2.end(), 0);
		if (sum == 0) // 100번 돌았을 경우 다시 기존 값으로 초기화
			vec2 = vec1;

		if (vec2[random] > 0)
			vec2[random]--;
		else
			continue;

		vec3[random]++;
		input--;
	}
}

void Print_Items(vector<int>& VEC_RESULT)
{
	int sum = accumulate(VEC_RESULT.begin(), VEC_RESULT.end(), 0);

	cout << "\n입력횟수: " << sum << endl << endl;
	for (int i = 0; i < SIZE; ++i)
	{
		cout << (char)('A' + i) << ": " << VEC_RESULT[i] << "\t";

		VEC_RESULT[i] = 0; // while 반복을 위해 초기화
	}
	//cout << endl << "\n=====================================================================================\n\n";
}