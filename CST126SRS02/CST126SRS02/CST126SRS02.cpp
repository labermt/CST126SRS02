// CST126SRS02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cassert>

using std::cin;
using std::cout;
using std::setw;

int main()
{
	auto namelist = new char*[5];
	char name[258];
	auto length = 5;
	auto i = 0;

	while (cin.good())
	{
		const auto check = cin.peek();
		if (check == EOF || check == '\n' || check == '\t')
		{
			while (i > 0)
			{
				cout << namelist[--i] << " ";
				delete[] namelist[i];
			}
			cout << std::endl;
		}
		cin >> setw(257) >> name;
		const auto heap_name = new char[strlen(name)+ 1];
		strcpy(heap_name, name);
		namelist[i] = heap_name;
		assert(i < length);
		++i;
		if (i == length)
		{
			auto const temp = new char*[length * 2];
			for (auto i2 = 0; i2 < length; ++i2)
			{
				temp[i2] = namelist[i2];
			}
			length *= 2;
			delete[] namelist;
			namelist = temp;
		}
	}
	delete[] namelist;
    return 0;
}

