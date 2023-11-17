#pragma once
#include <string>
#include <iostream>
#include <istream>
#include "DataStorage.h"
#include "FlashMemoryType.h"

class SSD : public DataStorage
{
public:
	SSD() = default;
	SSD(DataTransferInterface transferInterface);
	SSD(int capacity, DataTransferInterface transferInterface, std::string brand, float formFactor, FlashMemoryType typeOfFlashMemory);
	~SSD() = default;

	void operator=(SSD other);
	friend std::ostream& operator << (std::ostream& out, const SSD& ssd);

	std::string getComponentName() const override;
	FlashMemoryType getTypeOfFlashMemory() const;
	void input() override;
	std::string toString() const override;
private:
	FlashMemoryType typeOfFlashMemory = FlashMemoryType::NAND3D;

	void setArguments(FlashMemoryType typeOfFlashMemory);
};