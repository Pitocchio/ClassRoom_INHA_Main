#include "Mypoint.h"
#include <iostream>
using namespace std;


int main()
{
	Mypoint p1(0, 0), p2(10, 30.5);
	Rectangle2D r1(2, 2, 5.5, 4.9), r2(4, 5, 10.5, 3.2), r3(3, 5, 2.3, 5.4);
	Circle2D c1(2, 2, 5.5), c2(2, 2, 5.5), c3(4, 5, 10.5);

	cout << "p1과 p2 사이의 거리 : " << p1.Cal_Distance(p2) << '\n';
	//cout << "r1 내부에 p1, p2가 있는지 여부 : " << contains(r1, p1) << ", " << contains(r1, p2) << '\n';
	//cout << "c1 내부에 p1, p2가 있는지 여부 : " << contains(c1, p1) << ", " << contains(c1, p2) << '\n';

	cout << "r1 내부에 p1, p2가 있는지 여부 : ";
	r1.IsContains(p1) ? cout << "TRUE" : cout << "FALSE"; cout << ", ";
	r1.IsContains(p2) ? cout << "TRUE" : cout << "FALSE"; cout << '\n';
	cout << "c1 내부에 p1, p2가 있는지 여부 : ";
	c1.IsContains(p1) ? cout << "TRUE" : cout << "FALSE"; cout << ", ";
	c1.IsContains(p2) ? cout << "TRUE" : cout << "FALSE"; cout << '\n';
	return 0;
}

