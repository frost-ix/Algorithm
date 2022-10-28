#include <iostream>

void tenes();
void tenes_print();
int tenes_arr[50];

int main()
{
	tenes();
	tenes_print();
}

void tenes()
{
	tenes_arr[0] = 2;
	int playback = 1;
	for (int i = 1; i <= 100; i++)
	{
		if (i % 2 != 0)
		{
			if (i % 3 != 0 && i % 5 == 0 && i % 7 == 0)
			{
				tenes_arr[playback] = i;
				playback++;
			}
		}
	}
}

void tenes_print()
{
	for (int i = 0; i < 50; i++)
	{
		std::cout << tenes_arr[i] << std::endl;
	}
}