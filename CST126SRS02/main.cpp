// CST126SRS02.cpp : Defines the entry point for the console application.
// Lyndsay Melodee Oda Latarsha Aletha Risa Corie Myron Jerica Ji Laverne Lai Lucinda Angelena Ai Kate Noe Enedina Adeline Enriqueta
// Read pages 456 & 457

#include "stdafx.h"
#include <iostream>
#include <iomanip>




int main()
{
	
	char ** names = nullptr; 
		names = new char*[1];
	char ** namesCopy = nullptr;
	char * nameRow = nullptr;
	char nameInput[257];
	int numNames = 0;


	for (int i = 0;;++i)
	{
			
		if (std::cin.peek() == '\n' || std::cin.eof()) //Exits loop at end of line
		{ 
			std::cin.ignore();

			std::cout << std::endl;

			//starts at top of names pointer array and moves backwards, displaying each row.
			for (int i = numNames - 1; i >= 0; --i)
			{
			std::cout << names[i] << " ";
			}

			std::cout << std::endl;
			std::cout << std::endl;

			//Cleans out old array and restarts counters.
			i = 0;
			numNames = 0;
			delete[] names;
			names = new char*[1];

			break; 
		}  
		else // Increases number of rows in names array.
		{
			if (numNames > 0)
			{
				//Create Scratchpad for names array.
				  
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
		}

		
		std::cin >> std::setw(256) >> nameInput;
		
		//Find size of name and creates new row of that size.
		size_t nameSize = strlen(nameInput) + 1;
		nameRow = new char[nameSize];

		//Moves name into names pointer array.
		strcpy(nameRow, nameInput);
		names[i] = nameRow;

		std::cout << "Processed: " << nameInput << std::endl;  //Remove when finished
		++numNames;
		
	}



	return 0;
}



