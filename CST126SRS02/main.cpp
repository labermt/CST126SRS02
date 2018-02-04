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
	int size{}; 

	nameList = new char*[capacity];

	cout << "Feed me strings, Seymour! \n";

	//Do stuff until you reach the end of the file.
	while (cin.good())
	{
		const auto nl = cin.peek(); //checking ahead for newline feed

		if (nl != '\n')
		{
			if(size == capacity)
			{
				//Add space and allocate to heap
				capacity = (capacity * 2) + 1;
				auto const temp = new char*[capacity];

				for (int copy{}; copy < size; copy++) temp[copy] = nameList[copy];

				delete[] nameList;
				nameList = temp;
			}
			while (size < capacity && cin.peek() != '\n')
			{
				char * currentName = nullptr;
				char buffer[258]; // should that be 257?

				cin >> setw(sizeof(buffer) - 1) >> buffer;

				currentName = new char[strlen(buffer) + 1];

				strcpy(currentName, buffer);

				nameList[size] = currentName;
				size++;
				
			}
		}
		else
		{
			// Output data
			while(size)
			{
				cout << nameList[--size] << " ";
				delete[] nameList[size];
			}
			cin.ignore();
			cout << endl;
			cout << "Feed me strings, Seymour! \n";
		}
	}

	delete[] nameList;
    return 0;
}

