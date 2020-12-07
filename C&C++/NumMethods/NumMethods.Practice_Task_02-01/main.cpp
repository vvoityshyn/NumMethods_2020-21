#include <iostream>

using namespace std;

void PrintMatrix(double* m, int rows, int cols);

int main()
{
	/*
		The program below is not going to work in the following cases:
		1. If the linear system does not have a solution
		2. If the linear system has more than 1 solution
		3. If the linear system has different number of rows and columns
		4. If the Gaussian Elimination method cause to big calculation error
	*/

	cout << "Numerical Methods: Practice Task #02 / Example A" << endl;

	const int rows = 4;
	const int cols = 5;
	// Augmented matrix of the linear system
	//double C[rows][cols] = {
	//		{2, -1, 1, -1, 1},
	//		{2, -1, 0, -3, 2},
	//		{3, 0, -1, 1, -3},
	//		{2, 2, -2, 5, -6}
	//	};	
	double C[rows][cols] = {
		{1, 2, -1, 1, 0},
		{2, 5, 1, 1, 4},
		{1, 3, 2, 1, 5},
		{3, 7, -1, 3, 2}
	};

	printf("Augmented matrix of a system of linear algebraic equations:\n");
	PrintMatrix(C[0], 4, 5);

	printf("Gaussian Elimination: Direct\n");	
	for (int c = 0; c < cols - 1; c++)
	{
		double p = C[c][c];
		if (abs(p) < 1e-6)
		{
			int q = c + 1;
			for (; q < rows; q++)
			{
				if (abs(C[q][c]) > 1e-6)
				{
					break;
				}
			}
			// replace row c with row q
			double temp;
			for (int j = 0; j < cols; j++)
			{
				temp = C[c][j];
				C[c][j] = C[q][j];
				C[q][j] = temp;
			}
			PrintMatrix(C[0], rows, cols);
		}
		p = C[c][c];
		for (int k = c; k < cols; k++)
		{
			C[c][k] = C[c][k] / p;
		}

		//PrintMatrix(C[0], rows, cols);

		for (int r = c + 1; r < rows; r++)
		{
			double d = -C[r][c];

			for (int k = c; k < cols; k++)
			{
				C[r][k] += d * C[c][k];
			}
		}
		PrintMatrix(C[0], rows, cols);
	}

	printf("Gaussian Elimination: Reverse\n");
	for (int c = cols - 2; c >= 0; c--)
	{
		for (int r = c - 1; r >= 0; r--)
		{
			double d = -C[r][c];

			for (int k = c; k < cols; k++)
			{
				C[r][k] += d * C[c][k];
			}
		}
		PrintMatrix(C[0], rows, cols);
	}

	printf("Answer:\n");
	for (int i = 0; i < rows; i++)
	{
		printf("x[%d] = %lf\n", i + 1, C[i][cols - 1]);
	}

	system("pause");
	return 0;
}

void PrintMatrix(double* m, int rows, int cols)
{
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			printf("%lf\t", *m);
			/*if (abs(*m) > 1e-6)
			{ 
				printf("%lf\t", *m);
			}
			else
			{
				printf("        \t");
			}*/
			
			m++;
		}
		printf("\n");
	}
	printf("------------------------------------------\n");
}
