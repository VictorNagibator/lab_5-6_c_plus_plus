#pragma once
#include <iostream>
#include "CPU.h"
#include "Display.h"
#include "GPU.h"
#include "Motherboard.h"
#include "RAM.h"
#include "HDD.h"
#include "SSD.h"

class Laptop
{
public:
	Laptop() = default;
	Laptop(std::string modelName, CPU cpu, GPU gpu, RAM ram, Motherboard motherboard, Display display, DataStorage* dataStorage);
	~Laptop() = default;

	void operator=(Laptop other);
	friend std::ostream& operator << (std::ostream& out, const Laptop& laptop);

	std::string getModelName() const;
	const CPU& getCPU() const;
	const GPU& getGPU() const;
	const RAM& getRAM() const;
	const Motherboard& getMotherboard() const;
	const Display& getDisplay() const;
	DataStorage* getDataStorage() const;
	void setModelName(std::string modelName);
	void setCPU(CPU cpu);
	void setGPU(GPU gpu);
	void setRAM(RAM ram);
	void setMotherboard(Motherboard motherboard);
	void setDisplay(Display display);
	void setDataStorage(DataStorage* dataStorage);
	void input();
	void boostCPU();
	void boostRAM();
	void boostCPU(float addable);
	void boostRAM(float addable);
	std::string toString() const;
private:
	std::string modelName;
	CPU cpu = CPU();
	GPU gpu = GPU();
	RAM ram = RAM();
	Motherboard motherboard = Motherboard();
	Display display = Display();
	DataStorage* dataStorage = new HDD(); //По умолчанию в ноутбуке стоит HDD

	bool checkArguments(std::string modelName, CPU cpu, GPU gpu, RAM ram, Motherboard motherboard, Display display, DataStorage* dataStorage);
	void tryToSetArguments(std::string modelName, CPU cpu, GPU gpu, RAM ram, Motherboard motherboard, Display display, DataStorage* dataStorage);
	DataStorage* createDataStorage(int choice);
};