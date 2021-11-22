#include <iostream>
using namespace std;

float sum(float num, float diff, int n)
{
	return n > 1 ? num + sum(num + diff, diff, --n) : num;
}

int main() {
	float num, diff; int n;
	cout << "Enter the first number: "; cin >> num;	
	cout << "Enter the difference: "; cin >> diff;	
	cout << "Enter the number of members: "; cin >> n;		
	float result = sum(num, diff, n);
	cout << "Result: " << result << endl;
	system("pause");
}

