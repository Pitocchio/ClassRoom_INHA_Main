#include <iostream>
#include "Temp.h"

int main(void)
{
	Account a1("KIM", 5486132151);

	a1.Deposit(50000);

	a1.Deposit(-1);

	a1.WithDrawal(7000);

	a1.WithDrawal(100000);


	return 0;
}
