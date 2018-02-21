//main.cpp the entry point for the application

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <iomanip>

int main()
{
	int intName = 5;
	int i = 0;
	char ** nameList;
	char ** temp;

	nameList = new char *[intName];
	const int MAXlen = 257;

	while (std::cin.good() && std::cin.peek() != '\n')
	{
		nameList[i] = new char[MAXlen];
		std::cin >> std::setw(MAXlen) >> nameList[i];

		i++;

		if (i == intName)
		{
			intName *= 2;
			temp = new char *[intName];
			for (int j = 0; j < intName / 2; j++)
			{
				temp[j] = nameList[j];
			}

			delete[] nameList;
			nameList = temp;
		}
	}

	for (int i = intName - 1; i >= 0; i--) {
		if (nameList[i] != nullptr)
		{
			std::cout << nameList[i] << " ";
			delete[] nameList[i];
		}
	}
	return 0;
}