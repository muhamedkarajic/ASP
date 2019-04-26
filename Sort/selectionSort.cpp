#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
	int l;

	for (int i = 0; i < n - 1; i++)
	{
		l = i;
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[l])
				l = j;

		swap(&arr[l], &arr[i]);
	}
}