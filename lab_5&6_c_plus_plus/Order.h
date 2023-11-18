#pragma once
#include <iostream>
#include <istream>
#include <concepts>
#include "Laptop.h"
#include "StatusType.h"


template <typename T>
concept HasIO = requires(std::ostream& os, std::istream& is, T& t) {
	{ os << t } -> std::same_as<std::ostream&>;
	{ is >> t } -> std::same_as<std::istream&>;
}; //требует перегрузку операторов ввода-вывода для типа Т

template <HasIO T = std::string> //по умолчанию дополнительная информация - строка
class Order
{
public:
	Order(Laptop laptop);
	Order(Laptop laptop, StatusType status, T additionalInfo);
	~Order() = default;

	template <HasIO U>
	friend std::ostream& operator << (std::ostream& out, Order<U>& order);

	static int getNumOfLastOrder();
	int getNumOfOrder() const;
	const Laptop& getLaptop() const;
	StatusType getStatus() const;
	T getAdditionalInfo() const;
	void input();
	void setStatus(StatusType status);
	void setLaptop(Laptop laptop);
	void setAdditionalInfo(T additionalInfo);
	std::string toString() const;
private:
	static inline int numOfLastOrder{};

	int numOfOrder;
	Laptop laptop = Laptop();
	StatusType status = StatusType::ONHOLD;
	T additionalInfo{};
};


//вся реализация была сделана в заголовочном файле, так как в ином случае возникает ошибка линкера,
//потому что компилятор ничего не знает о шаблонах в .cpp файлах

template <HasIO T>
std::ostream& operator << (std::ostream& out, Order<T>& order) {
	out << order.toString() << "\t" << order.getAdditionalInfo();
	return out;
}

template <HasIO T>
Order<T>::Order(Laptop laptop) {
	numOfOrder = ++numOfLastOrder;
	this->laptop = laptop;
}

template <HasIO T>
Order<T>::Order(Laptop laptop, StatusType status, T additionalInfo) : Order(laptop) {
	this->status = status;
	this->additionalInfo = additionalInfo;
}

template <HasIO T>
int Order<T>::getNumOfLastOrder() {
	return numOfLastOrder;
}

template <HasIO T>
int Order<T>::getNumOfOrder() const {
	return numOfOrder;
}

template <HasIO T>
const Laptop& Order<T>::getLaptop() const {
	return laptop;
}

template <HasIO T>
StatusType Order<T>::getStatus() const {
	return status;
}

template <HasIO T>
T Order<T>::getAdditionalInfo() const {
	return additionalInfo;
}

template <HasIO T>
void Order<T>::input() {
	Laptop laptop;
	StatusType type;
	T additionalInfo = T();
	numOfLastOrder++;

	std::cout << "Номер заказа: " << numOfLastOrder;
	std::cout << "Введите статус заказа (0 - в ожидании, 1 - в ремонте, 2 - отремонтирован): ";
	std::cin >> type;
	std::cout << "\tВвод параметров ноутбука\n";
	laptop.input();
	std::cout << "\tВвод дополнительной информации\n";
	std::cin >> additionalInfo;

	this->numOfOrder = this->numOfLastOrder;
	this->laptop = laptop;
	this->status = status;
	this->additionalInfo = additionalInfo;
}

template <HasIO T>
void Order<T>::setStatus(StatusType status) {
	this->status = status;
	std::cout << "Состояние заказа успешно изменено!\n";
}

template <HasIO T>
void Order<T>::setLaptop(Laptop laptop) {
	this->laptop = laptop;
}

template <HasIO T>
void Order<T>::setAdditionalInfo(T additionalInfo) {
	this->additionalInfo = additionalInfo;
}

template <HasIO T>
std::string Order<T>::toString() const {
	std::string name = std::to_string(this->getNumOfOrder()) + ". " + this->laptop.getModelName() + "\t" + StatusTypeToString(this->getStatus());
	return name;
}