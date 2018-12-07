#include <iostream>
using namespace std;

void BucketSort(int A[], int n)
{
	PrRedPov *X = new PrRedPov[n];

	int maxV = GetMaxV(A,n);

	for(int i = 0; i<n; i++)
	{
		int value = A[i];
		int p = value*n / (maxV+1);
		X[p].Dodaj(value);
	} 

	int brojac = 0;//n-1
	for(int i = n-1; i>=0; i--)
	{
		int x = X[i].Ukloni();
		A[brojac] = x;
		brojac++;
	}
}