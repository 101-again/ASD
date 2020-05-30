#include <iostream>
using namespace std;

static long ProdTree(int l, int r)
{
	if (l > r)
		return 1;
	if (l == r)
		return l;
	if (r - l == 1)
		return (long)(l * r);
	int m = (l + r) / 2;
	return ProdTree(l, m) * ProdTree(m + 1, r);
}

static long FactTree(int n)
{
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	if (n == 1 || n == 2)
		return n;
	return ProdTree(2, n);
}

int main()
{
	int factorial=1;
	int N;
	setlocale(0, ""); 
	cout << "Input number: ";
	cin >> N;
	if (N < 0)
	{
		cout << "Factorial doesn't exist" << endl;
	}
	if (N == 0 || N == 1)
	{
		factorial = 1;
	}
	else if (N > 2) {
		for (int i = 2; i <= N; i++)
		{
			factorial *= i;
		}
	}
	cout << "Factorial by recurtion " << FactTree(N) << endl;
	cout << "Factorial by loop " << factorial << endl;
	system("pause");
	return 0;
}