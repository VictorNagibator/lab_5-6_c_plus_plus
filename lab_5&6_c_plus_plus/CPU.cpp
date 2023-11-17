#include "Cpu.h"

void CPU::operator=(const CPU other) {
	this->modelName = other.getModelName();
	this->socket = other.getSocket();
	this->frequency = other.getFrequency();
	this->numOfCores = other.getNumOfCores();
}

CPU operator+(const CPU& cpu, float addable) {
	return CPU(cpu.getModelName(), cpu.getSocket(), cpu.getFrequency() + addable, cpu.getNumOfCores());
}

CPU& operator++(CPU& cpu) {
	cpu.tryToSetArguments(cpu.getModelName(), cpu.getSocket(), cpu.getFrequency() + cpu.tryFreq, cpu.getNumOfCores());
	return cpu;
}

CPU operator++(CPU& cpu, int) {
	CPU tempCPU = cpu;
	++cpu;
	return tempCPU;
}

std::ostream& operator << (std::ostream& out, const CPU& cpu) {
	out << cpu.toString();
	return out;
}

CPU::CPU(std::string modelName) {
	this->modelName = modelName;
}

CPU::CPU(std::string modelName, std::string socket, float frequency, int numOfCores) {
	tryToSetArguments(modelName, socket, frequency, numOfCores);
}

std::string CPU::getComponentName() const {
	return "CPU";
}

std::string CPU::getModelName() const {
	return modelName;
}

std::string CPU::getSocket() const {
	return socket;
}

float CPU::getFrequency() const {
	return frequency;
}

int CPU::getNumOfCores() const {
	return numOfCores;
}

void CPU::input() {
	std::string modelName, socket;
	float frequency;
	int numOfCores;

	std::cout << "Введите название процессора: ";
	std::getline(std::cin, modelName);
	std::cout << "Введите название сокета процессора: ";
	std::getline(std::cin, socket);
	std::cout << "Введите его тактовую частоту (в ГГц): ";
	std::cin >> frequency;
	std::cout << "Введите количество ядер: ";
	std::cin >> numOfCores;
	while (getchar() != '\n'); //очистка входного потока после cin

	tryToSetArguments(modelName, socket, frequency, numOfCores);
}

std::string CPU::toString() const {
	std::string name = this->getModelName() + ", " + this->getSocket() + ", " + std::format("{:.1f}", this->getFrequency()) + " ГГц, " + std::to_string(this->getNumOfCores()) + "-ядерный";
	return name;
}


bool CPU::checkArguments(std::string modelName, std::string socket, float frequency, int numOfCores) const {
	return frequency >= 0 && frequency < maxFreq && numOfCores >= 0;
}

void CPU::tryToSetArguments(std::string modelName, std::string socket, float frequency, int numOfCores) {
	if (checkArguments(modelName, socket, frequency, numOfCores)) {
		this->modelName = modelName;
		this->socket = socket;
		this->frequency = frequency;
		this->numOfCores = numOfCores;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}