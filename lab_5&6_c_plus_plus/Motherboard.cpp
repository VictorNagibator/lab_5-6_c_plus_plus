#include "Motherboard.h"

void Motherboard::operator=(Motherboard other) {
    this->modelName = other.getModelName();
    this->socket = other.getSocket();
    this->chipset = other.getChipset();
    this->supportedRAMType = other.getSupportedRAMType();
}

std::ostream& operator << (std::ostream& out, const Motherboard& motherboard) {
    out << motherboard.toString();
    return out;
}

Motherboard::Motherboard(std::string modelName) {
    this->modelName = modelName;
}

Motherboard::Motherboard(std::string modelName, std::string socket, std::string chipset, RAMType supportedRAMType) {
    setArguments(modelName, socket, chipset, supportedRAMType);
}

std::string Motherboard::getComponentName() const {
    return "Motherboard";
}

std::string Motherboard::getModelName() const {
    return modelName;
}

std::string Motherboard::getSocket() const {
    return socket;
}

std::string Motherboard::getChipset() const {
    return chipset;
}

RAMType Motherboard::getSupportedRAMType() const {
    return supportedRAMType;
}

void Motherboard::input() {
    std::string modelName, socket, chipset;
    RAMType supportedRAMType;

    std::cout << "Введите название материнской платы: ";
    std::getline(std::cin, modelName);
    std::cout << "Введите сокет: ";
    std::getline(std::cin, socket);
    std::cout << "Введите чипсет: ";
    std::getline(std::cin, chipset);
    std::cout << "Введите тип поддерживаемой памяти (DDR - 0, DDR2 - 1, DDR3 - 2, DDR4 - 3, DDR5 - 4): ";
    std::cin >> supportedRAMType;
    while (getchar() != '\n');

    setArguments(modelName, socket, chipset, supportedRAMType);
}

std::string Motherboard::toString() const {
    std::string name = this->getModelName() + ", " + this->getSocket() + ", " + this->getChipset();
    return name;
}


void Motherboard::setArguments(std::string modelName, std::string socket, std::string chipset, RAMType supportedRAMType) {
    this->modelName = modelName;
    this->socket = socket;
    this->chipset = chipset;
    this->supportedRAMType = supportedRAMType;
}