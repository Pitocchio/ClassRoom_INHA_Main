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
		cout << "A. �л� �߰�\t\tB. �л� ����\t\tC. �л� ���\t\tD. �л� �˻�\t\tE. ����\n\n";
		cout << "���Ͻô� �޴��� ��ȣ�� �Է����ּ��� => _\b";
		cin >> chIndex;
		rewind(stdin);

		switch (chIndex)
		{
			case ('A'):
			{
				cout << "\n=========================================================\n\n";
				cout << "�л� <�߰�>�� �����ϼ̽��ϴ�.\n\n";
				cout << "�л� �̸� => ";
				cin >> strNameTemp;
				cout << "\n�л� ��ȣ => ";
				cin >> iNumberTemp;
				Link.Add_Student(strNameTemp, iNumberTemp);
				break;
			}
			case ('B'):
			{
				cout << "\n=========================================================\n\n";
				cout << "�л� <����>�� �����ϼ̽��ϴ�.\n\n";
				cout << "�л� �̸� => ";
				cin >> strNameTemp;
				Link.Delete_Student(strNameTemp);
				break;
			}
			case ('C'):
			{
				cout << "\n=========================================================\n\n";
				cout << "�л� <���>�� �����ϼ̽��ϴ�.\n\n";
				Link.Print_Student();
				break; 
			}
			case ('D'): 
			{
				cout << "\n=========================================================\n\n";
				cout << "�л� <�˻�>�� �����ϼ̽��ϴ�.\n\n";
				cout << "�л� �̸� => ";
				cin >> strNameTemp;
				Link.Search_Student(strNameTemp);
				break;
			}
			case ('E'): 
			{
				cout << "\n=========================================================\n\n";
				printf("�ý����� �����ϰڽ��ϴ�.\n");
				// delete �ʿ�!
				exit(1);
			}
		}
	}
	return 0;
}