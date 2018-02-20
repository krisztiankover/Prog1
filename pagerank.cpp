#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

void kiir (double t[], int db)
{
	for (int i = 0; i < db; i++)
	{
		cout << "Pagerank: " << t[i] << endl;
	}
}

double tavolsag (double PR[], double PRV[], int n)
{
	double osszeg = 0;
	
	for (int i = 0; i < n; i++)
	{
		osszeg += (PRV[i] - PR[i]) * (PRV[i] - PR[i]);
	}

	return sqrt(osszeg);
}

int main ()
{
	double L[4][4] = {
		{0.0, 0.0, 1.0/3.0, 0.0},
		{1.0, 1.0/2.0, 1.0/3.0, 1.0},
		{0.0, 1.0/2.0, 0.0, 0.0},
		{0.0, 0.0, 1.0/3.0, 0.0}
	};

	double PR[4] = {0.0, 0.0, 0.0, 0.0};
	double PRV[4] = {1.0/4.0, 1.0/4.0, 1.0/4.0, 1.0/4.0};

	int i, j;

	for(;;)
	{
		for (i = 0; i < 4; i++)
		{
			PR[i] = 0.0;
			for (j = 0; j < 4; j++)
			{
				PR[i] += L[i][j] * PRV[j];
			}
		}

		if (tavolsag(PR, PRV, 4) < 0.0000000001)
		{
			break;
		}

		for (i = 0; i < 4; i++)
		{
			PRV[i] = PR[i];
		}
	}

	kiir (PR, 4);
}