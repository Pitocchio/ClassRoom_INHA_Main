#include "cVector.h"
#include <iostream>
using namespace std;

int main()
{
	cVector3 u(-1, 3, 2);
	cVector3 v(3, -4, 1);

	cout << "Q1.(a)    u + v = " << u + v << "\n\n";
	cout << "Q1.(b)    u - v = " << u - v << "\n\n";

	cout << "Q1.(c)    3u + 2v = " << (u * 3) + (v * 2) << "\n\n";
	cout << "Q1.(d)    -2u + v = " << (u * -2) + v << "\n\n";

	cout << "============================================================\n\n";

	cout << "Q2.(a) u의 정규화 : " << u.Normalize() << "\n\n";
	cout << "Q2.(b) v의 정규화 : " << v.Normalize() << "\n\n";

	cout << "============================================================\n\n";

	cVector3 u1(1, 1, 1), v1(2, 3, 4);
	cout << "Q3.(a)    u = (1, 1, 1), v = (2, 3, 4)의 사이각 = " << cVector3::Angle(u1, v1) << "\n\n";

	cVector3 u2(1, 1, 0), v2(-2, 2, 0);
	cout << "Q3.(b)    u = (1, 1, 0), v = (-2, 2, 0)의 사이각 = " << cVector3::Angle(u2, v2) << "\n\n";

	cVector3 u3(-1, -1, -1), v3(3, 1, 0);
	cout << "Q3.(c)    u = (-1, -1, -1), v = (3, 1, 0)의 사이각 = " << cVector3::Angle(u3, v3) << "\n\n";

	cout << "============================================================\n\n";

	cout << "Q4.      ";
	cVector3 A(0, 0, 0), B(0, 1, 3), C(5, 1, 0);
	cout << cVector3::Cross((B - A), (C - A));

	return 0;
}
