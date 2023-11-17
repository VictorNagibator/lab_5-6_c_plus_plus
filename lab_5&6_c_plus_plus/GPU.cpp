#include "GPU.h"

void GPU::operator=(GPU other) {
	this->modelName = other.getModelName();
	this->frequency = other.getFrequency();
	this->vram = other.getVRAM();
}

std::ostream& operator << (std::ostream& out, const GPU& gpu) {
	out << gpu.toString();
	return out;
}

GPU::GPU(std::string modelName) {
	this->modelName = modelName;
}

GPU::GPU(std::string modelName, float frequency, int vram) {
	tryToSetArguments(modelName, frequency, vram);
}

std::string GPU::getComponentName() const {
	return "GPU";
}

std::string GPU::getModelName() const {
	return modelName;
}

float GPU::getFrequency() const {
	return frequency;
}

int GPU::getVRAM() const {
	return vram;
}

void GPU::input() {
	std::string modelName;
	float frequency;
	int vram;

	std::cout << "Введите название видеокарты: ";
	std::getline(std::cin, modelName);
	std::cout << "Введите тактовую частоту графического процессора (в МГц): ";
	std::cin >> frequency;
	std::cout << "Введите объем видеопамяти (в ГБ): ";
	std::cin >> vram;
	while (getchar() != '\n');

	tryToSetArguments(modelName, frequency, vram);
}

std::string GPU::toString() const {
	std::string name = this->getModelName() + ", " + std::format("{:.1f}", this->getFrequency()) + " МГц, " + std::to_string(this->getVRAM()) + " ГБ";
	return name;
}


bool GPU::checkArguments(std::string modelName, float frequency, int vram) const {
	return frequency >= 0 && vram >= 0;
}

void GPU::tryToSetArguments(std::string modelName, float frequency, int vram) {
	if (checkArguments(modelName, frequency, vram)) {
		this->modelName = modelName;
		this->frequency = frequency;
		this->vram = vram;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}