#pragma once
#include <iostream>

class LaptopComponent abstract
{
public:
	virtual std::string getComponentName() const abstract = 0;
	virtual void input() abstract = 0;
	virtual std::string toString() const abstract = 0;
};