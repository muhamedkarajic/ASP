#include <iostream>
using namespace std;

const char* crt = "\n- - - - - - - - - - - - - - - - - - \n";

void insertionSort(int *array, const int &len)
{
	int value;
	for (int i = 0; i < len; i++)
	{
		value = i;
		while (value > 0 && array[value - 1] > array[value])
		{
			swap(array[value], array[value - 1]);
			value--;
		}
	}
}

void insertionSort2(int *array, const int &len)
{
	int value;
	for (int i = 1; i < len; i++)
	{
		value = array[i];
		for (int j = 0; j < i; j++)
			if (array[i] < array[j])
			{
				for (int x = i; x > j; x--)
					array[x] = array[x - 1];
				array[j] = value;
			}
	}
}

void main()
{
	const int len = 10;
	int array[len] = { 15,4,2,6,50,1,220,51,71,7 };

	insertionSort(array, len);

	for (int i = 0; i < len; i++)
		cout << array[i] << ", ";
	cout << crt;

	/*1, 2, 4, 6, 7, 15, 50, 51, 71, 220,*/

	system("PAUSE>0");
}