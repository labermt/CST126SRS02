// CST126SRS02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

int main()
{
	int numNames = 0;
	char ** names = nullptr;
	char ** temp = nullptr;
	char * str = nullptr;
	char nameInput[257];
	
	for (int i = 0;;++i)
	{
		if (std::cin.peek() == '\n') { break; }  //Exits loop at end of line
		
		std::cin >> std::setw(256) >> nameInput;
		temp = new char * [i + 1];
		names[i] = new char[strlen(nameInput) + 1];

		for (int i2 = 0; i2 < i + 1; ++i2)
		{
			temp[i2] = names[i2];
		}

		numNames = i;
	}

	for (int i = numNames; i >= 0; --i)
	{
		std::cout << names[i] << " ";
	}


	return 0;
}

