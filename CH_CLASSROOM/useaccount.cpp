#include <iostream>
#include "account.h"

int main(void)
{
	Account Cus1;

	Cus1.Init("KIM", "123456789", 10000);

	Cus1.Deposit(5000);
	Cus1.Show();

	Cus1.Deposit(0);
	Cus1.Show();

	Cus1.WithDrawal(3500);
	Cus1.Show();

	Cus1.WithDrawal(25000);
	Cus1.Show();
}