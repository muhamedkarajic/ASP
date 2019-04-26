#include <iostream>
using namespace std;

void BubbleDown(int arr[], int n, int i)
{
	int largest = i;
	int l = i * 2 + 1;
	int r = i * 2 + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (i != largest)
	{
		swap(arr[i], arr[largest]);
		BubbleDown(arr, n, largest);
	}
}

void HeapSort(int arr[], int n)
{

	for (int i = n/2-1; i >= 0; i--)
		BubbleDown(arr, n, i);

	for (int i = n-1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		n--;
		BubbleDown(arr, n, 0);
	}
}

void PrintArray(int arr[], int n)
{
	cout << "[ ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << ", "; 
	cout << "]" << endl;
}

int main()
{
	const int n = 7;
	int arr[n] = { 6,4,1,7,5,2,3 };

	HeapSort(arr, n);
	PrintArray(arr, n);

	system("PAUSE>0");
}