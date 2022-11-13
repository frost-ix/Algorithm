#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <random>

// Redesign change module
#define CHANGE(index_i, index_j, temp) ((temp)=(index_i), (index_i)=(index_j), (index_j)=(temp))

void sort_board();
void sort_intro();

void data_input(int* arr, int size);

void getArrData(int* arr, int size, int cycle);

int bubble(int* arr, int size, int cycle);
int selection(int* arr, int size, int cycle);
int insertion(int* arr, int size,int cycle);
