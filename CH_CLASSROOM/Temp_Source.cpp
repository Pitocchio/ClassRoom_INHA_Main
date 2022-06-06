#include "Temp.h"
#include <iostream>;

Account::Account(std::string Name, int AccountNumber)
{
	m_Name = Name;
	m_Balance = 0;
	m_AccountNumber = AccountNumber;

	std::cout << "계좌 개설 완료\n" << "예금주 : " << m_Name
		<< "\t계좌번호 : " << m_AccountNumber << "\t현재잔액 : " << m_Balance << "\n\n";
}

void Account::Deposit(int money)
{
	if (money < 1000)
		std::cout << "입금 실패 (입금 가능 금액 : 1,000원 이상)\n\n";
	else
	{
		m_Balance += money;

		std::cout << "입금액 : " << money << "\t현재 잔액 : " << m_Balance << "\n\n";
	}
}

void Account::WithDrawal(int money)
{
	if (m_Balance < money)
		std::cout << "출금 실패 (출금 가능 금액 : " << m_Balance << ")\n\n";
	else
	{
		m_Balance -= money;

		std::cout << "출금액 : " << money << "\t현재 잔액 : " << m_Balance << "\n\n";
	}
}

Account::~Account()
{
	std::cout << "시스템을 종료합니다.\n";
}
