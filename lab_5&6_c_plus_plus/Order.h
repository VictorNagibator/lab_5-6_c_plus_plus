#pragma once
#include <iostream>
#include <istream>
#include "Laptop.h"
#include "StatusType.h"

class Order
{
public:
	Order(Laptop laptop);
	Order(Laptop laptop, StatusType status);
	~Order() = default;

	friend std::ostream& operator << (std::ostream& out, Order& order);

	static int getNumOfLastOrder();
	int getNumOfOrder() const;
	const Laptop& getLaptop() const;
	StatusType getStatus() const;
	void input();
	void setStatus(StatusType status);
	void setLaptop(Laptop laptop);
	std::string toString() const;
private:
	static inline int numOfLastOrder{};

	int numOfOrder;
	Laptop laptop = Laptop();
	StatusType status = StatusType::ONHOLD;

	void setArguments(StatusType status);
};