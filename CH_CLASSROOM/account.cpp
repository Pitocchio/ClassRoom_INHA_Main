#include <iostream>
#include "account.h"


void Account::Init(std::string name, std::string number, int balance)
{
	Account::m_strName = name;
	Account::m_iAccountnumber = number;
	Account::m_iBalance = balance;
}


void Account::Deposit(int iMoney)
{
	if (iMoney <= 0)
		std::cout << "입금 금액을 다시 입력해주시기 바랍니다.(1원 이상)";
	
	else
		m_iBalance += iMoney;
}

void Account::WithDrawal(int iMoney)
{
	if (m_iBalance < iMoney)
		std::cout << "출금 한도를 초과하였습니다. (계좌 잔액 : " << m_iBalance << ")\n"
			<< "금액을 다시 입력해주시기 바랍니다.";
	else
		m_iBalance -= iMoney;
}

void Account::Show()
{
	std::cout << "\n예금주명 : " << m_strName
		<< "\n계좌번호 : " << m_iAccountnumber
		<< "\n잔액     : " << m_iBalance << "\n\n";
}