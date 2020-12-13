#pragma once
#include <string>
#include <iostream>

int getIntValue(std::string text, int border1, int border2) {
	double value;
	std::cout << text << std::endl;
	std::cout << "\nEnter number from " << border1 << " to " << border2 << ": ";
	while (!(std::cin >> value) || (value - floor(value)) || value < border1 || value > border2) {
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "\nError. Enter number from " << border1 << " to " << border2 << ": ";
	}
	int valueInt = (int)value;
	return valueInt;
}