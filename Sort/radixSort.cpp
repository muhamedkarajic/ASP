#include <iostream>
using namespace std;

void sortExp(int *A, int n, int exp)
{
	int counter[10] = { 0 };

	for (int i = 0; i < n; i++)
	{
		int b = A[i];
		int c = (b / exp) % 10;
		counter[c]++;
	}

	for (int i = 1; i < 9; i++)
		counter[i] += counter[i - 1];

	int *pomocna = new int[n];
	for (int i = n-1; i>=0; i--)
	{
		int b = A[i];
		int c = (b / exp) % 10;
		int &p = counter[c];
		p--;
		pomocna[p] = b;
	}

	for (int i = 0; i < n; i++)
		A[i] = pomocna[i];
	delete[] pomocna;
}

int GetMaxV(int* A, int n)
{
	int maxV = A[0];
	for (int i = 1; i < n; i++)
		if (A[maxV] < A[i])
			maxV = i;
	return A[maxV];
}

void HeapSort(int *A, int n)
{
	int exp = 1;
	int maxV = GetMaxV(A, n);
	while (maxV > 0)
	{
		sortExp(A, n, exp);
		exp = exp * 10;
		maxV = maxV / 10;
	}
}

int main()
{
	const int n = 7;
	int A[] = { 3,81,7,1,5,10,15 };
	HeapSort(A, n);

	for (int i = 0; i < n; i++)
		cout << A[i] << ", ";
	cout << endl;

	system("PAUSE");
}