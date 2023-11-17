#pragma once
#include <string>
#include <iostream>
#include <istream>
#include "DataStorage.h"

class HDD : public DataStorage
{
public:
	HDD() = default;
	HDD(DataTransferInterface transferInterface);
	HDD(int capacity, DataTransferInterface transferInterface, std::string brand, float formFactor, int spindleSpeed);
	~HDD() = default;

	void operator=(HDD other);
	friend std::ostream& operator << (std::ostream& out, const HDD& hdd);

	std::string getComponentName() const override;
	int getSpindleSpeed() const;
	void input() override;
	std::string toString() const override;
private:
	int spindleSpeed = 0;

	bool checkArguments(int spindleSpeed) const;
	void tryToSetArguments(int spindleSpeed);
};