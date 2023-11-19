#include "Laptop.h"

void Laptop::operator=(Laptop other) {
    this->modelName = other.getModelName();
    this->cpu = other.getCPU();
    this->gpu = other.getGPU();
    this->motherboard = other.getMotherboard();
    this->ram = other.getRAM();
    this->display = other.getDisplay();
    this->dataStorage = other.getDataStorage();
}

std::ostream& operator << (std::ostream& out, const Laptop& laptop) {
    out << laptop.toString();
    return out;
}

Laptop::Laptop(std::string modelName, CPU cpu, GPU gpu, RAM ram, Motherboard motherboard, Display display, DataStorage* dataStorage) {
    tryToSetArguments(modelName, cpu, gpu, ram, motherboard, display, dataStorage);
}

std::string Laptop::getModelName() const {
    return modelName;
}

const CPU& Laptop::getCPU() const {
    return cpu;
}

const GPU& Laptop::getGPU() const {
    return gpu;
}

const RAM& Laptop::getRAM() const {
    return ram;
}

const Motherboard& Laptop::getMotherboard() const {
    return motherboard;
}

const Display& Laptop::getDisplay() const {
    return display;
}

DataStorage* Laptop::getDataStorage() const {
    return dataStorage;
}

void Laptop::setModelName(std::string modelName) {
    this->modelName = modelName;
}

void Laptop::setCPU(CPU cpu) {
    if (checkArguments(this->modelName, cpu, this->gpu, this->ram, this->motherboard, this->display, this->dataStorage)) {
        this->cpu = cpu;
    }
    else throw std::invalid_argument("Неподходящий сокет!");
}

void Laptop::setGPU(GPU gpu) {
    this->gpu = gpu;
}

void Laptop::setRAM(RAM ram) {
    if (checkArguments(this->modelName, this->cpu, this->gpu, ram, this->motherboard, this->display, this->dataStorage)) {
        this->ram = ram;
    }
    else throw std::invalid_argument("Неподходящий тип памяти!");
}

void Laptop::setMotherboard(Motherboard motherboard) {
    this->motherboard = motherboard;

    if (this->cpu.getSocket() != motherboard.getSocket()) { this->cpu = CPU(); }
    if (this->ram.getRAMType() != motherboard.getSupportedRAMType()) { this->ram = RAM(motherboard.getSupportedRAMType()); }
}

void Laptop::setDisplay(Display display) {
    this->display = display;
}

void Laptop::setDataStorage(DataStorage* dataStorage) {
    DataStorage* newDataStorage = dataStorage;
    this->dataStorage = newDataStorage;
}

void Laptop::input() {
    std::cout << "Введите название ноутбука: ";
    std::getline(std::cin, modelName);
    std::cout << "\tВвод параметров процессора\n";
    cpu.input();
    std::cout << "\tВвод параметров видеокарты\n";
    gpu.input();
    std::cout << "\tВвод параметров RAM\n";
    ram.input();
    std::cout << "\tВвод параметров материнской платы\n";
    motherboard.input();
    std::cout << "\tВвод параметров экрана\n";
    display.input();
    std::cout << "\tВвод параметров хранилища\n";
    std::cout << "Введите тип хранилища (0 - HDD, 1 - SSD): ";
    int choice;
    do
    {
        std::cin >> choice;
        if (choice != 0 && choice != 1) std::cout << "Некорректный ввод!\nПопробуйте еще раз: ";
    } while (choice != 0 && choice != 1);
    dataStorage = createDataStorage(choice);
    dataStorage->input();
}

std::string Laptop::toString() const {
    std::string name =
        "Название модели: " + this->modelName + "\n" +
        "CPU: " + this->cpu.toString() + "\n" +
        "GPU: " + this->gpu.toString() + "\n" +
        "RAM: " + this->ram.toString() + "\n" +
        "Материнская плата: " + this->motherboard.toString() + "\n" +
        "Экран: " + this->display.toString() + "\n" +
        this->dataStorage->getComponentName() + ": " + dataStorage->toString() + "\n";
    return name;
}


bool Laptop::checkArguments(std::string modelName, CPU cpu, GPU gpu, RAM ram, Motherboard motherboard, Display display, DataStorage* dataStorage) {
    return (cpu.getSocket() == motherboard.getSocket()) && (ram.getRAMType() == motherboard.getSupportedRAMType());
}

void Laptop::tryToSetArguments(std::string modelName, CPU cpu, GPU gpu, RAM ram, Motherboard motherboard, Display display, DataStorage* dataStorage) {
    if (checkArguments(modelName, cpu, gpu, ram, motherboard, display, dataStorage)) {
        this->modelName = modelName;
        this->cpu = cpu;
        this->gpu = gpu;
        this->ram = ram;
        this->motherboard = motherboard;
        this->display = display;
        this->dataStorage = dataStorage;
    }
    else throw std::invalid_argument("Неподходящие комплектующие!");
}

DataStorage* Laptop::createDataStorage(int choice) {
    DataStorage* dataStorage;
    if (choice == 0) dataStorage = new HDD();
    else dataStorage = new SSD();
    return dataStorage;
}



void Laptop::boostCPU() {
    try
    {
        cpu++;
    }
    catch (const std::invalid_argument&)
    {
        std::cout << "Разгон CPU больше невозможен!\n";
    }
}

void Laptop::boostCPU(float addable) {
    try
    {
        cpu = cpu + addable;
    }
    catch (const std::invalid_argument&)
    {
        std::cout << "Разгон CPU больше невозможен!\n";
    }
}


void Laptop::boostRAM() {
    try
    {
        ram++;
    }
    catch (const std::invalid_argument&)
    {
        std::cout << "Разгон RAM больше невозможен!\n";
    }
}

void Laptop::boostRAM(float addable) {
    try
    {
        ram = ram + addable;
    }
    catch (const std::invalid_argument&)
    {
        std::cout << "Разгон RAM больше невозможен!\n";
    }
}