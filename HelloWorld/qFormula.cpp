#include <iostream>
#include <cmath>
using namespace std;

void quadraticFormula()
{
	float a, b, c, x, y;
	cout << "y = ax^2+bx+c:\n";
	cout << "input a: ";
	cin >> a;
	cout << "\ninput b: ";
	cin >> b;
	cout << "\ninput c: ";
	cin >> c;
	cout << "\ninput x: ";
	cin >> x;

	y = a * pow(x, 2) + b * x + c;
	cout << "\n" << a << " * " << x << " ^2 + " << b << " * " << x << " + " << c << " = " << y << "\n";
	system("pause");
}