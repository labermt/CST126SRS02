// CST126SRS02.cpp : Defines the entry point for the console application.
// Lyndsay Melodee Oda Latarsha Aletha Risa Corie Myron Jerica Ji Laverne Lai Lucinda Angelena Ai Kate Noe Enedina Adeline Enriqueta
// Read pages 456 & 457

#include "stdafx.h"
#include <iostream>
#include <iomanip>




int main()
{
	
	char ** names = nullptr;
	names = new char*[100];

	char ** namesCopy = nullptr;
	namesCopy = new char*[0];

	char * nameRow = nullptr;
	
	char nameInput[257];

	char numNamesString[257];

	int numNames = 0;
		
	bool sizeFlag = false;
	
	


	for (int i = 0;;++i)
	{
		if (std::cin.peek() == '\n' || std::cin.eof()) //Exits loop at end of line
		{ 
			break; 
		}  
		else // Increases number of rows in names array.
		{
			if (numNames > 0)
			{
				delete[] namesCopy;
				namesCopy = new char*[i];
				for (int x = 0; x < i; ++x)
				{
					namesCopy[x] = names[x];
				}

				delete[] names;
				names = new char*[i + 1];

				for (int x = 0; x < i; ++x)
				{
					names[x] = namesCopy[x];
				}
			}
		}

		std::cin >> std::setw(256) >> nameInput;
		
		
		size_t nameSize = strlen(nameInput) + 1;
		nameRow = new char[nameSize];
		strcpy(nameRow, nameInput);
		names[i] = nameRow;
		
		++numNames;
	}

	std::cout << std::endl;

	for (int i = numNames - 1; i >= 0; --i)
	{
		std::cout << names[i] << " ";
	}


	return 0;
}



