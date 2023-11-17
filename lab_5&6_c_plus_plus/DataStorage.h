#pragma once
#include <string>
#include <format>
#include "DataTransferInterface.h"
#include "LaptopComponent.h"

class DataStorage abstract : public LaptopComponent
{
public:
	DataStorage() = default;
	DataStorage(DataTransferInterface transferInterface);
	DataStorage(int capacity, DataTransferInterface transferInterface, std::string brand, float formFactor);
	~DataStorage() = default;

	virtual std::string getComponentName() const abstract = 0;

	virtual int getCapacity() const;
	virtual DataTransferInterface getInterface() const;
	virtual std::string getBrand() const;
	virtual float getFormFactor() const;

	virtual void input();
	virtual std::string toString() const abstract;
protected:
	int capacity = 0;
	DataTransferInterface transferInterface = DataTransferInterface::SATA;
	float formFactor = 0;
	std::string brand;

	bool checkArguments(int capacity, DataTransferInterface transferInterface, std::string brand, float formFactor) const;
	void tryToSetArguments(int capacity, DataTransferInterface transferInterface, std::string brand, float formFactor);
};
