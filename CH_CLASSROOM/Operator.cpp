#include <iostream>
#include "Operator.h"

int main(void)
{
	using std::cout;
	Stonewt poppins(9, 2.8);
	double p_wt = poppins;

	cout << "double������ ��ȯ => ";
	cout << "Poppins: " << p_wt << "�Ŀ��\n";
	cout << "int������ ��ȯ => ";
	cout << "Poppins: " << int(poppins) << "�Ŀ��\n";
	return 0;
}