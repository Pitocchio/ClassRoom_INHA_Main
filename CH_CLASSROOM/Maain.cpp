#include <iostream>
#include "Link.h"
using namespace std;

int main(void)
{
	Link Link;
	string strNameTemp;
	char chIndex;
	int iNumberTemp;

	while (1)
	{
		system("cls");
		cout << "A. 학생 추가\t\tB. 학생 삭제\t\tC. 학생 출력\t\tD. 학생 검색\t\tE. 종료\n\n";
		cout << "원하시는 메뉴를 번호로 입력해주세요 => _\b";
		cin >> chIndex;
		rewind(stdin);

		switch (chIndex)
		{
			case ('A'):
			{
				cout << "\n=========================================================\n\n";
				cout << "학생 <추가>를 선택하셨습니다.\n\n";
				cout << "학생 이름 => ";
				cin >> strNameTemp;
				cout << "\n학생 번호 => ";
				cin >> iNumberTemp;
				Link.Add_Student(strNameTemp, iNumberTemp);
				break;
			}
			case ('B'):
			{
				cout << "\n=========================================================\n\n";
				cout << "학생 <삭제>를 선택하셨습니다.\n\n";
				cout << "학생 이름 => ";
				cin >> strNameTemp;
				Link.Delete_Student(strNameTemp);
				break;
			}
			case ('C'):
			{
				cout << "\n=========================================================\n\n";
				cout << "학생 <출력>을 선택하셨습니다.\n\n";
				Link.Print_Student();
				break; 
			}
			case ('D'): 
			{
				cout << "\n=========================================================\n\n";
				cout << "학생 <검색>을 선택하셨습니다.\n\n";
				cout << "학생 이름 => ";
				cin >> strNameTemp;
				Link.Search_Student(strNameTemp);
				break;
			}
			case ('E'): 
			{
				cout << "\n=========================================================\n\n";
				printf("시스템을 종료하겠습니다.\n");
				// delete 필요!
				exit(1);
			}
		}
	}
	return 0;
}