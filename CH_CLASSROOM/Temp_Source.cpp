#include "Temp.h"
#include <iostream>;

Account::Account(std::string Name, int AccountNumber)
{
	m_Name = Name;
	m_Balance = 0;
	m_AccountNumber = AccountNumber;

	std::cout << "���� ���� �Ϸ�\n" << "������ : " << m_Name
		<< "\t���¹�ȣ : " << m_AccountNumber << "\t�����ܾ� : " << m_Balance << "\n\n";
}

void Account::Deposit(int money)
{
	if (money < 1000)
		std::cout << "�Ա� ���� (�Ա� ���� �ݾ� : 1,000�� �̻�)\n\n";
	else
	{
		m_Balance += money;

		std::cout << "�Աݾ� : " << money << "\t���� �ܾ� : " << m_Balance << "\n\n";
	}
}

void Account::WithDrawal(int money)
{
	if (m_Balance < money)
		std::cout << "��� ���� (��� ���� �ݾ� : " << m_Balance << ")\n\n";
	else
	{
		m_Balance -= money;

		std::cout << "��ݾ� : " << money << "\t���� �ܾ� : " << m_Balance << "\n\n";
	}
}

Account::~Account()
{
	std::cout << "�ý����� �����մϴ�.\n";
}
