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
		std::cout << "�Ա� �ݾ��� �ٽ� �Է����ֽñ� �ٶ��ϴ�.(1�� �̻�)";
	
	else
		m_iBalance += iMoney;
}

void Account::WithDrawal(int iMoney)
{
	if (m_iBalance < iMoney)
		std::cout << "��� �ѵ��� �ʰ��Ͽ����ϴ�. (���� �ܾ� : " << m_iBalance << ")\n"
			<< "�ݾ��� �ٽ� �Է����ֽñ� �ٶ��ϴ�.";
	else
		m_iBalance -= iMoney;
}

void Account::Show()
{
	std::cout << "\n�����ָ� : " << m_strName
		<< "\n���¹�ȣ : " << m_iAccountnumber
		<< "\n�ܾ�     : " << m_iBalance << "\n\n";
}