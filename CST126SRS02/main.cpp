// CST126SRS02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iomanip>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{

	char ** nameList = nullptr;

	int capacity{};

	nameList = new char*[capacity];

	cout << "Feed me strings, Seymour! \n";

	//Do stuff until you reach the end of the file.
	while (cin.good())
	{
		const auto nl = cin.peek(); //checking ahead for newline feed
		int size{}; //number of names read in
		if (nl != '\n')
		{
			while (size <= capacity)
			{
				char * currentName = nullptr;
				char buffer[256]; // should that be 257?

				cin >> setw(257) >> buffer;

				// Makes room for more names and copies over the old list to temp
				if(size == capacity)
				{
					//Add space and allocate to heap
					capacity = (capacity * 2) + 1;
					auto temp = new char*[capacity];

					for (int copy{}; copy <= size; copy++)
					{
						//copy nameList into temp
						temp[copy] = nameList[copy];
						delete[] nameList;
						nameList = temp;
					}
				}

				currentName = new char[strlen(buffer) + 1];

				strcpy(currentName, buffer);

				// placing names into names array.
				nameList[size] = currentName;
				
				size++;
			}
		}
		else
		{
			// Output data
			while(size)
			{
				cout << nameList[--size];
				delete[] nameList[size];
			}
		}
	}

	delete[] nameList;
    return 0;
}

