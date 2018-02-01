// CST126SRS02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iomanip>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{

	char ** names = nullptr;
	char * str = nullptr;
	char buffer[257];
	// initial value for number of names, will change dynamically as names are inputted
	auto num_names = 4;

	names = new char*[4];

	cout << "Feed me strings, Seymour! \n";

	int i{};
	while (i < num_names)
	{

		cin >> setw(256) >> buffer;

		str = new char[strlen(buffer) + 1];

		strcpy_s(str, strlen(buffer) + 1, buffer);

		names[i] = str;
		for (int a{}; a < i; a++)
		{
			cout << names[a] << endl;
		}
		i++;
	}

    return 0;
}

