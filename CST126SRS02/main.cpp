﻿#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <memory>

int main()
{
	const int MAX_NAME_LENGTH = 258;
	int arrayLength = 5;
	char name[MAX_NAME_LENGTH];
	char ** arrayOfNames = new char*[arrayLength] {nullptr};

	while (std::cin.good())
	{
		bool improperName = false;
		int numberOfNames = 0;
		for (;;)
		{
			const int checker = std::cin.peek();
			if (checker == ' ')
			{
				std::cin.ignore();
			}
			else if (checker != '\n' && !std::cin.eof())
			{
				if (numberOfNames == arrayLength)
				{
					char ** const temp = new char*[arrayLength];
					std::memcpy(temp, arrayOfNames, sizeof(temp[0]) * arrayLength);
					delete[] arrayOfNames;
					arrayLength *= 2;
					arrayOfNames = new char*[arrayLength];
					std::memcpy(arrayOfNames, temp, sizeof(arrayOfNames[0]) * arrayLength);
					delete[] temp;
				}
				std::cin >> std::setw(MAX_NAME_LENGTH) >> name;

				if (strlen(name) > 256) // (name[257] == '\0') The name is not initialized, so name[257] could be anything. 
				{
					improperName = true;
					name[256] = '\0';
					// name[257] = ' '; // Dead code. 
				}

				char * const copyName = new char[strlen(name) + 1];
				strcpy(copyName, name);

				arrayOfNames[numberOfNames] = copyName;

				numberOfNames++;
			}
			else
			{
				std::cin.ignore();
				break;
			}
		}

		int numberOfNamesPrint = numberOfNames;

		if (improperName)
		{
			std::cout << "A name in the list was greater than the allowed characters. The following line may not display as you expect" << std::endl;
		}

		while (numberOfNamesPrint > 0)
		{
			--numberOfNamesPrint;
			std::cout << arrayOfNames[numberOfNamesPrint];
			if (numberOfNamesPrint != 0)
			{
				std::cout << ' ';
			}
		}
		std::cout << std::endl;

		while (numberOfNames > 0)
		{
			--numberOfNames;
			delete[] arrayOfNames[numberOfNames];
		}
	}

	delete[] arrayOfNames;

	new char;
	_CrtDumpMemoryLeaks();

	return 0;
}
