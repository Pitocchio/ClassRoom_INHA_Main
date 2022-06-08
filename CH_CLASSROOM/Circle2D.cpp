#include "Circle2D.h"
#include <iostream>
using namespace std;

int main(void)
{
	Circle2D c1(2, 2, 5.5);
	Circle2D c2(2, 2, 5.5);
	Circle2D c3(4, 5, 10.5);

	cout << c1.Get_Area() << "\n";
	cout << c1.Get_Perimeter() << "\n";

	cout << c1.Contains(3, 3) << "\n";
	cout << c1.Contains(c2) << "\n";
	cout << c1.Overlaps(c3) << "\n";

}