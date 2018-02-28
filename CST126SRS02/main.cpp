// CST126SRS02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std; 

int main()
{
	// char name[258];

	// auto num_names = 4;
	int size{};
	int capacity{};

	auto nameList = new const char*[capacity];

	while (cin.good())
	{
		const auto nl = cin.peek();
		if (nl == '\n' || nl == EOF)
		{
			cin.ignore();
			while (size != 0)
			{
				size--;
				cout << nameList[size] << " ";
				delete[] nameList[size];
			}
			cout << endl;
		}
		else if (isspace(nl))
		{
			cin.ignore();
		}
		else
		{
			if (size == capacity)
			{
				int i{};
				capacity = (capacity * 2) + 1;
				const auto tmp = new const char*[capacity];

				while (i < size)
				{
					tmp[i] = nameList[i];
					i++;
				}
				delete[] nameList;
				nameList = tmp;
			}
			char buffer[258];

			cin >> setw(257) >> buffer; // I think you mean 257?

			const auto currentName = new char[strlen(buffer) + 1];
			strcpy(currentName, buffer);

			nameList[size] = currentName;

			size++;
		}
	}

	delete[] nameList;

    return 0;
}
