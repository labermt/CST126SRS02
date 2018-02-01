// CST126SRS02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

int main()
{
	int numNames = 0;
	char * names = nullptr;
	char nameInput[257];
	
	for (int i = 0;;++i)
	{
		if (std::cin.peek() == '\n') { break; }  //Exits loop at end of line
		
		std::cin >> std::setw(256) >> nameInput;
		
		int nameSize = size_t(nameInput);
		names = new char[nameSize];
		
		++numNames;
	}

	for (int i = numNames; i >= 0; --i)
	{
		std::cout << names[i] << " ";
	}


	return 0;
}

