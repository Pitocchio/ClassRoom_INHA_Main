#include <iostream>
using namespace std;

int Factorial(int n);

int main(void)
{
	int iN(0);

	do
	{
		cin >> iN;
	} while (iN < 0 || 12 < iN);

	cout << Factorial(iN);

	return 0;
}

int Factorial(int n)
{
	if (n == 0)
		return 1;

	return Factorial(n - 1) * n;
}





