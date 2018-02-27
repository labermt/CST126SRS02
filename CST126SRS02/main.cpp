// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iomanip>
//#include <fstream> // NO FILE I/O as per spec. 
#include <iostream>

using namespace std;

int main()
{
	int capacity{};
	int size{}; 

	auto nameList = new const char*[capacity]; // zero allocation is technically okay, but it must be deleted. nullptr not so. 

	// Do stuff until you reach the end of the file.
	while (cin.good())
	{
		const auto nl = cin.peek(); // checking ahead for newline feed
		if (nl == EOF)
		{
			break;
		}

		if (nl != '\n')
		{
			if (isspace(nl))
			{
				cin.ignore();
			}
			else
			{
				if (size == capacity)
				{
					// Add space and allocate to heap
					capacity = (capacity * 2) + 1;
					auto const temp = new const char*[capacity];

					for (int copy{}; copy < size; copy++) temp[copy] = nameList[copy]; // Use memcpy() for faster code.

					delete[] nameList;
					nameList = temp;
				}
				char buffer[258]; // should that be 257? 258 is ideal, but you need to read the full amount and detect spec overrun. 

				cin >> setw(sizeof(buffer) - 1) >> buffer;

				const auto currentName = new char[strlen(buffer) + 1];

				strcpy(currentName, buffer);

				nameList[size] = currentName;
				size++;
			}
		}
		else
		{
			cin.ignore(); // Moving this line for clarity. 

			// Output data
			while (size)
			{
				cout << nameList[--size] << " ";
				delete[] nameList[size];
			}
			cout << endl;
		}
	}

	delete[] nameList;

    return 0;
}
