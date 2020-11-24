#include <iostream>

using namespace std;


int main()
{
	cout << "Numerical Methods: Practice Task #01 / Example A" << endl;
	// x = exp(-x)
	// Fixed Point Iteration Method

	int n = 20;
	double x1 = 0.2;
	double x2;
	double delta;

	for (int i = 0; i <= n; i++)
	{
		x2 = exp(-x1);
		delta = abs(x2 - x1);

		printf("# iter. - %d\t| x[n] = %f\t| x[n+1] = %f\t| delta = %f\n", i, x1, x2, delta);

		x1 = x2;
	}

	system("pause");
	return 0;
}
