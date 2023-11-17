#pragma once
#include <iostream>
#include <string>
#include <format>
#include "LaptopComponent.h"

class GPU : public LaptopComponent
{
public:
	GPU() = default;
	GPU(std::string modelName);
	GPU(std::string modelName, float frequency, int vram);
	~GPU() = default;

	void operator=(GPU other);
	friend std::ostream& operator << (std::ostream& out, const GPU& gpu);

	std::string getComponentName() const override;
	std::string getModelName() const;
	float getFrequency() const;
	int getVRAM() const;
	void input() override;
	std::string toString() const override;
private:
	std::string modelName;
	float frequency = 0;
	int vram = 0;

	bool checkArguments(std::string modelName, float frequency, int vram) const;
	void tryToSetArguments(std::string modelName, float frequency, int vram);
};
