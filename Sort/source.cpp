#include "header.h"

// Clear Sort
int main()
{
	sort_board();
}
void sort_intro()
{
	std::cout << "1. Bubble sort" << std::endl;
	std::cout << "2. Insertion sort" << std::endl;
	std::cout << "3. Selection sort" << std::endl;
	std::cout << "Other. END" << std::endl;
}
void sort_board()
{
	// size = array size
	// cycle = sort routine time
	int array_size, cycle=0 , sort_select;

	std::cout << "< sort select program >" <<std::endl;
	std::cout << "set array size >> "; std::cin >> array_size;
	
	// Dyanmic allocated Array
	int* arrData = (int*)malloc(sizeof(int) * array_size);

	data_input(arrData, array_size);
	std::cout << "Not sort array ------" << std::endl;
	getArrData(arrData, array_size, cycle);

	sort_intro();
	std::cout << "Choose sort >> "; std::cin >> sort_select;
	switch (sort_select)
	{
		case 1:
		{
			cycle = bubble(arrData, array_size, cycle);
			std::cout << "Bubble sort array ------" << std::endl;
			break;
		}
		case 2:
		{
			cycle = insertion(arrData, array_size, cycle);
			std::cout << "Insertion sort array ------" << std::endl;
			break;
		}
		case 3:
		{
			cycle = selection(arrData, array_size, cycle);
			std::cout << "Selection sort arrayy ------" << std::endl;
			break;
		}
		default:
			std::cout << "Invailed number. restart program" << std::endl;
			exit(1);
			break;
	}
	getArrData(arrData, array_size, cycle);
}

void data_input(int* arr, int size)
{
	// Push random value in array
	std::random_device rd;
	std::mt19937_64 gen(rd());
	std::uniform_int_distribution<int> dis(0, 100);
	for (int i = 0; i < size; i++)
	{
		arr[i] = dis(gen);
	}
}

void getArrData(int* arr, int size, int cycle)
{
	std::cout << "< Arr data START> " << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
		if (i > 0 && (i+1)% 10 == 0)
		{
			std::cout << std::endl;
		}
	}
	std::cout << std::endl << "cycle : " << cycle << std::endl;
	std::cout << "< Arr data END >" << std::endl;
}
