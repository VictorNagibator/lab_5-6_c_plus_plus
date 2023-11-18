#include "SSD.h"

void SSD::operator=(SSD other) {
	DataStorage::operator=(other);
	this->typeOfFlashMemory = other.typeOfFlashMemory;
}

std::ostream& operator << (std::ostream& out, const SSD& ssd) {
	out << ssd.toString();
	return out;
}

SSD::SSD(DataTransferInterface transferInterface)
	: DataStorage(transferInterface) {

}

SSD::SSD(int capacity, DataTransferInterface transferInterface, std::string brand, float formFactor, FlashMemoryType typeOfFlashMemory)
	: DataStorage(capacity, transferInterface, brand, formFactor) {
	setArguments(typeOfFlashMemory);
}

std::string SSD::getComponentName() const {
	return "SSD";
}

FlashMemoryType SSD::getTypeOfFlashMemory() const {
	return typeOfFlashMemory;
}

void SSD::input() {
	FlashMemoryType typeOfFlashMemory;
	DataStorage::input();

	std::cout << "Введите тип флеш-памяти (0 - SLC, 1 - MLC, 2 - NOR, 3 - NAND, 4 - 3DNAND): ";
	std::cin >> typeOfFlashMemory;
	while (getchar() != '\n');

	setArguments(typeOfFlashMemory);
}

std::string SSD::toString() const {
	std::string name = DataStorage::toString() + ", " + FlashMemoryTypeToString(getTypeOfFlashMemory());
	return name;
}


void SSD::setArguments(FlashMemoryType typeOfFlashMemory) {
	this->typeOfFlashMemory = typeOfFlashMemory;
}