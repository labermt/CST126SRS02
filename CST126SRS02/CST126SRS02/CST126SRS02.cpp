// CST126SRS02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>


using std::cin;
using std::cout;
using std::setw;


int main()
{
	auto namelist = new char[5];
	auto name = new char[257];
	auto length = 5;
	auto i = 0;

	while(i < length)
	{
		cin >> setw(256) >> name;
		namelist[i] = *name;
		++i;
	}

	if(i >= length)
	{
		auto temp = new char[length * 2];
		for(auto i2 =0; i2 < length; ++i2)
		{
			temp[i2] = namelist[i2];
		}
		length = length * 2;
		delete[] temp;
	}

	while(i > 0)
	{
		cout << namelist;
			--i;
	}

	delete[] name;
	delete[] namelist;
    return 0;
}

