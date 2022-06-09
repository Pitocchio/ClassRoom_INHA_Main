#include <iostream>
#include "string1.h"
const int ArSIze = 10;
const int MaxLen = 81;

int main(void)
{	
	using std::cin;
	using std::cout;
	using std::endl;
	String name;

	cout << "�ȳ��Ͻʴϱ�? ������ ��� �ǽʴϱ�?\n => ";
	cin >> name;
	cout << name << " ��! ������ ���� �Ӵ� " << ArSIze << " ���� �Է����ֽʽÿ� (�������� Enter):\n";

	String sayings[ArSIze];					// ��ü���� �迭
	char temp[MaxLen];						// ���ڿ� ������ ���� �ӽ� ����

	int i;
	for (i = 0; i < ArSIze; ++i)
	{
		cout << i + 1 << ": ";
		cin.get(temp, MaxLen);
		while (cin && cin.get() != '\n')	// �Է½��� or �����Է� => i ����X
			continue;
		if (!cin || temp[0] == '\0')
			break;
		else
			sayings[i] = temp;				// �����ε� ���� ������
	}

	int total = i;							// �о� ���� �� �� ��
	if (total > 0)
	{
		cout << "(������ ���� �Ӵ���� �Է��ϼ̽��ϴ�.)\n";

		int i;
		for (i = 0; i < total; ++i)
		{
			cout << sayings[i][0] << ": " << sayings[i] << endl;
		}

		int shortest = 0;
		int first = 0;

		for (i = 1; i < total; ++i)
		{
			if (sayings[i].length() < sayings[shortest].length())
				shortest = i;
			if (sayings[i] < sayings[first])
				first = i;
		}

		cout << "���� ª�� �Ӵ�: \n" << sayings[shortest] << endl;
		cout << "���������� ���� �տ� ������ �Ӵ� :\n" << sayings[first] << endl;
		cout << "�� ���α׷��� " << String::HowMany() << "���� String ��ü�� ����Ͽ����ϴ�. �̻�!\n";
	}
	else
		cout << "�Է� ����! �̻�.\n";

	return 0;
}