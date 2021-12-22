#include <iostream>
#include <iomanip>
using namespace std;
//основні функції
void arrayRand(float**, int, int);
float average(float**, int, int);
float findX(float**, int, int);
void check(float, float);
//допоміжні функції
int inputSize();
float** arrayDecl(int, int);
void arrayDelete(float**, int, int);

int main() 
{
	//введення розмірності масиву
	int m = inputSize();
	int n = m;
	//генерація масиву
	float** arr = arrayDecl(m, n);
	arrayRand(arr, m, n);
	//визначення середнього значення 
	float av = average(arr, m, n);
	cout << "Average: " << av << endl;
	//визначення першого додатнього елементу
	float X = findX(arr, m, n);
	cout << "X: " << X << endl;
	//порівняння X та av
	check(X, av);
	//допоміжні операції
	arrayDelete(arr, m, n);
	system("pause");
}

void arrayRand(float** arr, int m, int n)
{
	srand(time(NULL));
	cout << "Generated array:" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int k = 0; k < n; k++)
		{
			arr[i][k] = float(rand() % 199 - 99) / 10;
			cout << setw(5) << arr[i][k];
		}
		cout << endl;
	}
}

float average(float** arr, int m, int n)
{
	int num = 0;
	float sum = 0;
	for (int i = 0; i < m - 1; i++)
	{
		for (int k = 0; k < n - i - 1; k++)
		{
			sum += arr[i][k];
			num++;
		}
	}
	return sum / num;
}

float findX(float** arr, int m, int n)
{
	for (int i = 0; i < n; i++)
	{
		if(i % 2 == 0)
		{
			for (int k = 0; k < m; k++)
			{
				if (arr[k][i] > 0)
				{
					return arr[k][i];
				}
			}
		}
		else 
		{
			for (int k = m - 1; k > -1; k--)
			{
				if (arr[k][i] > 0)
				{
					return arr[k][i];
				}
			}
		}		
	}
	return NULL;
}

void check(float X, float av)
{
	if (X > av)
		cout << "X > av" << endl;
	else if (X == av)
		cout << "X = av" << endl;
	else
		cout << "X < av" << endl;
}

int inputSize()
{
	int n;
	cout << "Enter the size of array: ";
	cin >> n;
	return n;
}

float** arrayDecl(int m, int n)
{
	float** arr = new float* [m];
	for (int i = 0; i < m; i++)
		arr[i] = new float[n];
	return arr;
}

void arrayDelete(float** arr, int m, int n)
{
	for (int i = 0; i < m; i++)
		delete[] arr[i];
	delete[] arr;
}