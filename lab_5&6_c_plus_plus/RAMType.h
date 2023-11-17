#pragma once

enum RAMType { DDR, DDR2, DDR3, DDR4, DDR5 };

static std::string RAMTypeToString(RAMType type) {
	std::string result;
	switch (type)
	{
	case DDR:
		result = "DDR";
		break;
	case DDR2:
		result = "DDR2";
		break;
	case DDR3:
		result = "DDR3";
		break;
	case DDR4:
		result = "DDR4";
		break;
	case DDR5:
		result = "DDR5";
		break;
	default:
		break;
	}
	return result;
}

static std::istream& operator >> (std::istream& in, RAMType& type) {
	int choice;
	in >> choice;
	switch (choice)
	{
	case 0:
		type = DDR;
		break;
	case 1:
		type = DDR2;
		break;
	case 2:
		type = DDR3;
		break;
	case 3:
		type = DDR4;
		break;
	case 4:
		type = DDR5;
		break;
	default:
		break;
	}
	return in;
};
static std::ostream& operator << (std::ostream& out, RAMType& type) {
	out << RAMTypeToString(type);
	return out;
};
