#include <iostream>
using namespace std;

void Merge(int Temp[], int Element[], int lista1, int size1, int lista2, int size2)
{
	int i = lista1, j = lista2, k = lista1;
	while (i < lista1 + size1 && j < lista2 + size2)
		if (Temp[i] < Temp[j])
			Element[k++] = Temp[i++];
		else
			Element[k++] = Temp[j++];

	while (i < lista1 + size1)
		Element[k++] = Temp[i++];
	while (j < lista2 + size2)
		Element[k++] = Temp[j++];

	for (k = lista1; k < lista1 + size1 + size2; k++)
		Temp[k] = Element[k];
}

void MergeSort(int Temp[], int Element[], int lista1, int size)
{
	if (size > 1)
	{
		int lista2, size1, size2;
		
		lista2 = lista1 + size / 2;
		size1 = lista2 - lista1;
		size2 = size - size1;
		
		MergeSort(Temp, Element, lista1, size1);
		MergeSort(Temp, Element, lista2, size2);
		Merge(Temp, Element, lista1, size1, lista2, size2);
	}
}

int main()
{
	const int n = 7;
	int A[n] = { 8,3,2,11,5,7,1 };
	int B[n]{0};
	
	cout << "Unsorted: ";
	for (int i = 0; i < n; i++)
		cout << A[i] << ", ";
	cout << endl;

	MergeSort(A, B, 0, n);

	cout << "Sorted: ";
	for (int i = 0; i < n; i++)
		cout << B[i] << ", ";
	cout << endl;

	system("PAUSE>0");
}