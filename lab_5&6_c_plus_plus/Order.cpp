#include "Order.h"

std::ostream& operator << (std::ostream& out, Order& order) {
	out << order.toString();
	return out;
}

Order::Order(Laptop laptop) {
	numOfOrder = ++numOfLastOrder;
	this->laptop = laptop;
}

Order::Order(Laptop laptop, StatusType status) : Order(laptop) {
	setArguments(status);
}

int Order::getNumOfLastOrder() {
	return numOfLastOrder;
}

int Order::getNumOfOrder() const {
	return numOfOrder;
}

const Laptop& Order::getLaptop() const {
	return laptop;
}

StatusType Order::getStatus() const {
	return status;
}

void Order::input() {
	StatusType type;
	numOfLastOrder++;

	std::cout << "Номер заказа: " << numOfLastOrder;
	std::cout << "Введите статус заказа (0 - в ожидании, 1 - в ремонте, 2 - отремонтирован): ";
	std::cin >> type;
	std::cout << "\tВвод параметров ноутбука\n";
	this->laptop.input();

	this->numOfOrder = numOfLastOrder;
	this->laptop = laptop;
	setArguments(type);
}

void Order::setStatus(StatusType status) {
	this->status = status;
	std::cout << "Состояние заказа успешно изменено!\n";
}

void Order::setLaptop(Laptop laptop) {
	this->laptop = laptop;
}

std::string Order::toString() const {
	std::string name = std::to_string(this->getNumOfOrder()) + ". " + this->laptop.getModelName() + "\t" + StatusTypeToString(this->getStatus());
	return name;
}


void Order::setArguments(StatusType status) {
	this->status = status;
}