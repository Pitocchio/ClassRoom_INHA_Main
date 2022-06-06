#pragma once

#include <string>

class Account
{
	private :
		std::string m_Name;
		int m_Balance;
		int m_AccountNumber;

	public :
		//Account(); // 디폴트 생성자
		Account(std::string Name, int AccountNumber); // 사용자 정의 생성자
		void Deposit(int money);
		void WithDrawal(int money);
		~Account(); // 소멸자
};