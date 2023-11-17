#include "Display.h"

void Display::operator=(Display other) {
	this->width = other.getWidth();
	this->height = other.getHeight();
	this->refreshRate = other.getRefreshRate();
}

std::ostream& operator << (std::ostream& out, const Display& display) {
	out << display.toString();
	return out;
}

Display::Display(int width, int height) {
	tryToSetArguments(width, height, 0);
}

Display::Display(int width, int height, int refreshRate) {
	tryToSetArguments(width, height, refreshRate);
}

std::string Display::getComponentName() const {
	return "Display";
}

int Display::getWidth() const {
	return width;
}

int Display::getHeight() const {
	return height;
}

int Display::getRefreshRate() const {
	return refreshRate;
}

void Display::input() {
	int width, height, refreshRate;

	std::cout << "Введите ширину и высоту экрана (в пикселях): ";
	std::cin >> width >> height;
	std::cout << "Введите частоту обновления экрана (в Гц): ";
	std::cin >> refreshRate;
	while (getchar() != '\n');

	tryToSetArguments(width, height, refreshRate);
}

std::string Display::toString() const {
	std::string name = std::to_string(width) + "x" + std::to_string(height) + ", " + std::to_string(refreshRate) + " Гц";
	return name;
}


bool Display::checkArguments(int width, int height, int refreshRate) const {
	return width >= 0 && height >= 0 && refreshRate >= 0;
}

void Display::tryToSetArguments(int width, int height, int refreshRate) {
	if (checkArguments(width, height, refreshRate)) {
		this->width = width;
		this->height = height;
		this->refreshRate = refreshRate;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}