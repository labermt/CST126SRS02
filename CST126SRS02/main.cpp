// CST126SRS02.cpp : Defines the entry point for the console application.
// Lyndsay Melodee Oda Latarsha Aletha Risa Corie Myron Jerica Ji Laverne Lai Lucinda Angelena Ai Kate Noe Enedina Adeline Enriqueta


#include "stdafx.h"
#include <iostream>
#include <iomanip>



//Start main method
int main()
{
	char ** names = nullptr; 
		names = new char*[1];
	char * nameRow = nullptr;
	char nameInput[257];
	int numNames = 0;

	//Fill array with information and output reverse
	for (int i;;)
	{
		i = numNames;
		
		if (std::cin.eof())
		{
			break;
		}
		else if (std::cin.peek() == '\n') //Exits loop at end of line
		{
			std::cin.ignore();

			std::cout << std::endl;

			for (int i = numNames - 1; i >= 0; --i)
			{
				std::cout << names[i] << " ";
			}

			std::cout << std::endl;
			std::cout << std::endl;

			//Clean up counters and arrays
			i = 0;
			numNames = 0;
			delete[] names;
			names = new char*[1];
		}
		else 
		{
			++numNames;

			if (numNames > 1)
			{	//Create Scratchpad for names array.
				char ** namesCopy = nullptr;
				namesCopy = new char*[i + 1];

				//Move names array to scratch pad
				for (int x = 0; x < i; ++x)
				{
					namesCopy[x] = names[x];
				}

				//Create new instance of names array, increasing number of rows.
				delete[] names;
				names = new char*[i + 1];

				//Moves scratch pad back to names array.
				for (int x = 0; x < i; ++x)
				{
					names[x] = namesCopy[x];
				}

				delete[] namesCopy;
			}
				
			{	
				//Stores names into ragged array
				std::cin >> std::setw(256) >> nameInput;
				size_t nameSize = strlen(nameInput) + 1;
				nameRow = new char[nameSize];
				strcpy(nameRow, nameInput);
				names[i] = nameRow;
			}
				
		}
	}

	delete[] names;
	delete[] nameRow;
	
	return 0;
}



