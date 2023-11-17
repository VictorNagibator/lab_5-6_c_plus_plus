#pragma once
#include <iostream>
#include <string>
#include "RAMType.h"
#include "LaptopComponent.h"

class Motherboard : public LaptopComponent
{
public:
	Motherboard() = default;
	Motherboard(std::string modelName);
	Motherboard(std::string modelName, std::string socket, std::string chipset, RAMType supportedRAMType);
	~Motherboard() = default;

	void operator=(Motherboard other);
	friend std::ostream& operator << (std::ostream& out, const Motherboard& motherboard);

	std::string getComponentName() const override;
	std::string getModelName() const;
	std::string getSocket() const;
	std::string getChipset() const;
	RAMType getSupportedRAMType() const;
	void input() override;
	std::string toString() const override;
private:
	std::string modelName;
	std::string socket;
	std::string chipset;
	RAMType supportedRAMType = RAMType::DDR;

	void setArguments(std::string modelName, std::string socket, std::string chipset, RAMType supportedRAMType);
};