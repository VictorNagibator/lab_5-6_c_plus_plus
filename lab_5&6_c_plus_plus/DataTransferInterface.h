#pragma once
#include <iostream>

enum DataTransferInterface { PATA, SATA, SAS, NVME };

static std::string DataTransferInterfaceToString(DataTransferInterface transferInterface) {
	std::string result;
	switch (transferInterface)
	{
	case PATA:
		result = "PATA";
		break;
	case SATA:
		result = "SATA";
		break;
	case SAS:
		result = "SAS";
		break;
	case NVME:
		result = "NVMe";
		break;
	default:
		break;
	}
	return result;
}

static std::istream& operator >> (std::istream& in, DataTransferInterface& transferInterface) {
	int choice;
	in >> choice;
	switch (choice)
	{
	case 0:
		transferInterface = PATA;
		break;
	case 1:
		transferInterface = SATA;
		break;
	case 2:
		transferInterface = SAS;
		break;
	case 3:
		transferInterface = NVME;
		break;
	default:
		break;
	}
	return in;
}
static std::ostream& operator << (std::ostream& out, DataTransferInterface& transferInterface) {
	out << DataTransferInterfaceToString(transferInterface);
	return out;
}
