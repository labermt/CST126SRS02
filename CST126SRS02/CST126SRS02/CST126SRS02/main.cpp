//main.cpp the entry point for the application

#include "stdafx.h"
#include <iostream>
// #include <sstream>
#include <iomanip>

int main()
{
	int intName = 5;
	int i = 0;

	char ** nameList = new char *[intName];
	const int MAXlen = 257;

	while (std::cin.good() && std::cin.peek() != '\n')
	{
		nameList[i] = new char[MAXlen];
		std::cin >> std::setw(MAXlen) >> nameList[i];

		i++;

		if (i == intName)
		{
			intName *= 2;
			char ** temp = new char *[intName];
			for (int j = 0; j < intName / 2; j++)
			{
				temp[j] = nameList[j];
			}

			delete[] nameList;
			nameList = temp;
		}
	}

	while (i--)// for (int i = intName - 1; i >= 0; i--) // intName is the capacity, not the size. 
	{
		if (nameList[i] != nullptr)
		{
			std::cout << nameList[i] << " ";
			delete[] nameList[i];
		}
	}

	delete[] nameList;

	return 0;
}