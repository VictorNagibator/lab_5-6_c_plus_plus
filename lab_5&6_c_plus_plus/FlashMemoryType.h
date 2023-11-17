#pragma once
#include <iostream>

enum FlashMemoryType { SLC, MLC, NOR, NAND, NAND3D };

static std::string FlashMemoryTypeToString(FlashMemoryType type) {
	std::string result;
	switch (type)
	{
	case SLC:
		result = "SLC";
		break;
	case MLC:
		result = "MLC";
		break;
	case NOR:
		result = "NOR";
		break;
	case NAND:
		result = "NAND";
		break;
	case NAND3D:
		result = "3D NAND";
		break;
	default:
		break;
	}
	return result;
}

static std::istream& operator >> (std::istream& in, FlashMemoryType& type) {
	int choice;
	in >> choice;
	switch (choice)
	{
	case 0:
		type = SLC;
		break;
	case 1:
		type = MLC;
		break;
	case 2:
		type = NOR;
		break;
	case 3:
		type = NAND;
		break;
	case 4:
		type = NAND3D;
		break;
	default:
		break;
	}
	return in;
};
static std::ostream& operator << (std::ostream& out, FlashMemoryType& type) {
	out << FlashMemoryTypeToString(type);
	return out;
};