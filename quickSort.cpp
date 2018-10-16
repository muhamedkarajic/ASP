#include <iostream>
using namespace std;

int partition(int *arr, const int &low, const int &high) {
	int i = low - 1;
	int pivot = arr[high];

	for (int j = low; j < high; j++)
		if (arr[j] <= pivot)
			swap(arr[j], arr[++i]);

	swap(arr[i+1], arr[high]);

	return (i + 1);
}

void quickSort(int *arr, const int &low, const int &high) {
	if (low < high) {
		int middle = partition(arr, low, high);

		quickSort(arr, low, middle - 1);
		quickSort(arr, middle +1, high);
	}
}

void Print(int *arr, const int &n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << ", ";
	cout << endl;
}


int main() {
	int arr[] = { 6,23,1,56,2,7,2 };
	int n = sizeof(arr) / sizeof(arr[0]);

	quickSort(arr, 0, n - 1);
	Print(arr, n);

	system("PAUSE>0");
}