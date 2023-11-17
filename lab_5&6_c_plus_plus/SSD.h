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
	FlashMemoryType typeOfFlashMemory = NAND3D;

	bool checkArguments(FlashMemoryType typeOfFlashMemory) const;
	void tryToSetArguments(FlashMemoryType typeOfFlashMemory);
};