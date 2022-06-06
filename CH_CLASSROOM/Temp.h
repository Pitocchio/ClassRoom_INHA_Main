#pragma once

#include <string>

class Account
{
	private :
		std::string m_Name;
		int m_Balance;
		int m_AccountNumber;

	public :
		//Account(); // ����Ʈ ������
		Account(std::string Name, int AccountNumber); // ����� ���� ������
		void Deposit(int money);
		void WithDrawal(int money);
		~Account(); // �Ҹ���
};