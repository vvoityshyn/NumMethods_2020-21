#include <iostream>

using namespace std;

double TrapezoidSquare(double x1, double x2, double f1, double f2);
double F(double x);

int main()
{
	cout << "Numerical Methods: Practice Task #03 / Example A (trapezoid rule)" << endl;

	double a = 0;
	double b = 1;
	int n = 100;
	double h = (b - a) / n;

	double I = 0;
	for (int i = 0; i < n; i++)
	{
		double x1 = i * h;
		double x2 = i * h + h;		
		double s = TrapezoidSquare(x1, x2, F(x1), F(x2));

		printf("x1 = %lf; x2 = %lf\n", x1, x2);

		I += s;
	}

	printf("Result: %lf\n", I);

	system("pause");
	return 0;
}

double TrapezoidSquare(double x1, double x2, double f1, double f2)
{
	return 0.5 * (x2 - x1) * (f1 + f2);
}

double F(double x)
{
	return x * (1 - x * x);
}