#include "Rectangle2D.h"
#include <iostream>
using namespace std;

int main(void)
{
	Rectangle2D r1(2, 2, 5.5, 4.9);
	Rectangle2D r2(4, 5, 10.5, 3.2);
	Rectangle2D r3(3, 5, 2.3, 5.4);

	cout << r1.Get_Area() << "\n";
	cout << r1.GetPerimeter() << "\n";

	r1.IsContains(3, 3) ? cout << "TRUE" : cout << "FALSE"; cout << '\n';
	r1.IsContains(r2) ? cout << "TRUE" : cout << "FALSE"; cout << '\n';
	r1.IsOverlaps(r3) ? cout << "TRUE" : cout << "FALSE"; cout << '\n';

	return 0;
}