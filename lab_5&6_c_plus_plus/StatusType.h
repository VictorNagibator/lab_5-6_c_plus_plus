#pragma once
#include <iostream>
#include <istream>

enum class StatusType { ONHOLD, INPROCCESS, FINISHED };

static std::string StatusTypeToString(StatusType type) {
	std::string result;
	switch (type)
	{
	case StatusType::ONHOLD:
		result = "В ожидании";
		break;
	case StatusType::INPROCCESS:
		result = "В ремонте";
		break;
	case StatusType::FINISHED:
		result = "Готов";
		break;
	default:
		break;
	}
	return result;
}

static std::istream& operator >> (std::istream& in, StatusType& status) {
	int choice;
	in >> choice;
	switch (choice)
	{
	case 0:
		status = StatusType::ONHOLD;
		break;
	case 1:
		status = StatusType::INPROCCESS;
		break;
	case 2:
		status = StatusType::FINISHED;
		break;
	default:
		break;
	}
	return in;
};

static std::ostream& operator << (std::ostream& out, StatusType& status) {
	out << StatusTypeToString(status);
	return out;
};