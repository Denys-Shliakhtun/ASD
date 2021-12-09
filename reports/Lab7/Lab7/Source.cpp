#include <iostream>
#include <iomanip>
using namespace std;

char* arrayInit(char arr[], int add, int mult);
int arrayEqual(char A[], char B[], char C[]);
int arrayCheck(char C[], int k);
void arrayOutput(char arr[], int k);

int main() {	
	//визначення першого масиву
	char* A = new char[10];		
	cout << "A: "; 
	A = arrayInit(A, 74, -1);
	
	//визначення другого масиву
	char* B = new char[10];		
	cout << endl << "B: "; 
	B = arrayInit(B, 65, 2);
	
	//визначення третього масиву
	char C[10];		
	cout << endl << "C: ";
	int k = arrayEqual(A, B, C);
	
	//знаходження елементів менше 67
	cout << endl << "Elements under 67: ";
	int n = arrayCheck(C, k);	
	cout << endl << "n: " << setw(3) << n << endl;
	
	system("pause");
}

char* arrayInit(char arr[], int add, int mult)
{
	for (int i = 0; i < 10; i++)
	{
		arr[i] = add + mult * i;
	}
	arrayOutput(arr, 10);
	return arr;
}

int arrayEqual(char A[], char B[], char C[])
{
	int k = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int l = 0; l < 10; l++)
		{
			if (A[i] == B[l])
			{
				C[k] = A[i];
				k++;
			}
		}
	}
	arrayOutput(C, k);
	return k;
}

int arrayCheck(char C[], int k)
{
	int n = 0;
	for (int i = 0; i < k; i++)
	{
		if (C[i] < 67) 
		{
			n++;
			cout << setw(3) << C[i];
		}
	}
	return n;
}

void arrayOutput(char arr[], int k)
{
	for (int i = 0; i < k; i++)
	{
		cout << setw(3) << arr[i];
	}
}