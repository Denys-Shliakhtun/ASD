#include <iostream>
#include <iomanip>
using namespace std;

void arrRand(int arr1[][8]);
void averageNeg(int arr1[][8], float arr2[]);
void sortShell(float arr2[], int);

int main()
{
	int arr1[5][8];
	arrRand(arr1);
	float arr2[8];
	averageNeg(arr1, arr2);
	sortShell(arr2, 8);
	cout << "Sorted: ";
	for (int i = 0; i < 8; i++)
	{
		cout << setprecision(4) << arr2[i] << " ";
	}
	cout << endl << endl;
	system("pause");
}

void arrRand(int arr1[][8])
{
	srand(time(NULL));
	cout << "Matrix: " << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k < 8; k++)
		{
			arr1[i][k] = rand() % 199 - 99;
			cout << setw(4) << arr1[i][k];
		}
		cout << endl;
	}
	cout << endl;
}

void averageNeg(int arr1[][8], float arr2[])
{
	cout << "Array: ";
	int n, sum;
	for (int k = 0; k < 8; k++)
	{
		sum = 0;
		n = 0;
		for (int i = 0; i < 5; i++)
		{
			if (arr1[i][k] < 0)
			{
				sum += arr1[i][k];
				n++;
			}
		}
		if (n)
			arr2[k] = float(sum) / n;
		else
			arr2[k] = 0;
		cout << setprecision(4) << arr2[k] << " ";
	}
	cout << endl << endl;
}

void sortShell(float arr2[], int n)
{
	for (int d = n / 2; d >= 1; d /= 2)
		for (int i = d; i < n; i++)
			for (int j = i; j >= d && arr2[j - d] < arr2[j]; j -= d)
				swap(arr2[j], arr2[j - d]);
}