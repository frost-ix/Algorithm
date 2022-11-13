#include "header.h"

// Bubble Sort
int bubble(int* arr, int size, int cycle)
{
	for (int i = 0; i < size; i++)
	{
		int temp = 0;
		for (int j = 1; j < i; j++)
		{
			if (arr[0] > arr[1])
			{
				CHANGE(arr[0], arr[1], temp);
				cycle++;
			}
			if (arr[i] < arr[j])
			{
				CHANGE(arr[i], arr[j], temp);
				cycle++;
			}
			getArrData(arr, size, cycle);
		}
	}
	std::cout << std::endl << "< Bubble sort Clear >" << std::endl << std::endl;
	return cycle;
}

// Selection Sort
int selection(int* arr, int size, int cycle)
{
	int index_check, temp = 0;
	for (int i = 0; i < size - 1; i++)
	{
		index_check = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[index_check])
			{
				index_check = j;
				cycle++;
			}
			CHANGE(arr[index_check], arr[i], temp);
		}
		getArrData(arr, size, cycle);
	}
	std::cout << std::endl << "< Selection sort Clear >" << std::endl << std::endl;
	return cycle;
}

// Insertion Sort
int insertion(int* arr, int size, int cycle)
{
	int j, key_tempValue;
	for (int i = 1; i < size; i++)
	{
		key_tempValue = arr[i];
		j = i - 1;
		while (j >= 0 && key_tempValue <= arr[j])
		{
			arr[j + 1] = arr[j];
			j = j - 1;
			cycle++;
		}
		arr[j + 1] = key_tempValue;
		getArrData(arr, size, cycle);
	}
	std::cout << std::endl << "< Insertion sort Clear >" << std::endl << std::endl;
	return cycle;
}