// CST126SRS02.cpp : Defines the entry point for the console application.
// Lyndsay Melodee Oda Latarsha Aletha Risa Corie Myron Jerica Ji Laverne Lai Lucinda Angelena Ai Kate Noe Enedina Adeline Enriqueta
// Read pages 456 & 457

#include "stdafx.h"
#include <iostream>
#include <iomanip>




int main()
{
	
	char ** names = nullptr;
	char * nameRow = nullptr;
	int numNames = 0;
	char nameInput[257];
	
	names = new char*[20];
	


	for (int i = 0;;++i)
	{
		if (std::cin.peek() == '\n') { break; }  //Exits loop at end of line
		
		std::cin >> std::setw(256) >> nameInput;
		size_t nameSize = strlen(nameInput) + 1;

		nameRow = new char[nameSize];
		strcpy(nameRow, nameInput);
		names[i] = nameRow;
		
		
		//std::cout << std::endl;
		//for (int j{}; j <= i; j++)
		//{
		//	
		//	std::cout << names[j] << std::endl;
		//}
		++numNames;
	}

	std::cout << std::endl;

	for (int i = numNames - 1; i >= 0; --i)
	{
		std::cout << names[i] << " ";
	}


	return 0;
}



