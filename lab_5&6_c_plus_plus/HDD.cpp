#include "HDD.h"

void HDD::operator=(HDD other) {
	this->capacity = other.capacity;
	this->transferInterface = other.transferInterface;
	this->brand = other.brand;
	this->spindleSpeed = other.spindleSpeed;
	this->formFactor = other.formFactor;
}

std::ostream& operator << (std::ostream& out, const HDD& hdd) {
	out << hdd.toString();
	return out;
}

HDD::HDD(DataTransferInterface transferInterface)
	: DataStorage(transferInterface) {

}

HDD::HDD(int capacity, DataTransferInterface transferInterface, std::string brand, float formFactor, int spindleSpeed)
	: DataStorage(capacity, transferInterface, brand, formFactor) {
	tryToSetArguments(spindleSpeed);
}

std::string HDD::getComponentName() const {
	return "HDD";
}

int HDD::getSpindleSpeed() const {
	return spindleSpeed;
}

void HDD::input() {
	DataStorage::input();
	int spindleSpeed;

	std::cout << "Введите cкорость вращения шпинделя: ";
	std::cin >> spindleSpeed;
	while (getchar() != '\n');

	tryToSetArguments(spindleSpeed);
}

std::string HDD::toString() const {
	std::string name = DataStorage::toString() + ", " + std::to_string(this->getSpindleSpeed());
	return name;
}


bool HDD::checkArguments(int spindleSpeed) const {
	return spindleSpeed >= 0;
}

void HDD::tryToSetArguments(int spindleSpeed) {
	if (checkArguments(spindleSpeed)) {
		this->spindleSpeed = spindleSpeed;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}