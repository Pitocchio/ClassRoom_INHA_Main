#include <string>

class Account
{
	private: 
		std::string m_strName;
		std::string m_iAccountnumber;
		int m_iBalance;

	public:
		void Init(std::string name, std::string number, int balance);
		void Deposit(int money);
		void WithDrawal(int money);
		void Show();
};