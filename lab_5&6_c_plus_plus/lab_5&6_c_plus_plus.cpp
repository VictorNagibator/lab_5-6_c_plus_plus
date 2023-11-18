#include <iostream>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include "Order.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//5-ая лабораторная
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
		for (int j = 0; j < 2; j++)
			//boxOfSSDs[i][j].input();
	std::cout << boxOfSSDs[0][1] << std::endl << std::endl;

	//6-ая лабораторная
	//1. Пример работы с базовыми и производными классами, а также с виртуальными методами
	HDD hdd = HDD();
	SSD ssd = SSD();
	DataStorage* storage;
	storage = &hdd;
	std::cout << storage->getComponentName() << std::endl;
	storage = &ssd;
	std::cout << storage->getComponentName() << std::endl;
	storage = new SSD(DataTransferInterface::NVME);
	std::cout << storage->toString() << std::endl;
	delete storage;
	//2. Перегрузка операторов = и <<
	Display display1 = Display(1920, 1080, 60);
	Display display2 = display1;
	std::cout << display1 << std::endl << display2 << std::endl;
	//3. Пример работы с шаблонным классом
	std::string t = "Client is annoying";
	Order order = Order(Laptop(), StatusType::FINISHED, t);
	std::cout << order << std::endl;
}