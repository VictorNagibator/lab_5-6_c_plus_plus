#include <iostream>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include "Order.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//5-ая лабораторной
	//1. Пример работы с исключениями
	try
	{
		CPU example = CPU("i5 2400k", "lga1155", 22, -6); //пробуем создать процессор с отрицательным числом ядер
	}
	catch (const std::invalid_argument& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	//2. Пример работы с одномерными и двумерными массивами
	srand(time(NULL)); //чтобы правильно работал генератор случайных чисел
	Laptop devices[3];
	for (int i = 0; i < 3; i++)
	{
		int boostedFreq = rand() % 1000;
		devices[i].boostRAM(boostedFreq);
		std::cout << devices[i] << std::endl;
	}
	SSD boxOfSSDs[2][2];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			boxOfSSDs[i][j].input();
	std::cout << boxOfSSDs[0][1] << std::endl << std::endl;


}