// CST126SRS02.cpp : Defines the entry point for the console application.
// Alexander Burbank
// Spheal

#include "stdafx.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	char buffer[257];
	char** nameCollection = nullptr;
	char** tempCollection = nullptr;

	size_t nameCounter = 0;

	bool firstNameOnLine = true;

	while (true)
	{
		const char c2 = cin.peek();

		if (c2 == '\n')
		{
			// **** Empty line ****

			const char c1 = cin.get();

			cout << endl;
		}
		else
		{
			cin >> buffer;

			const char c1 = cin.get();

			if (c1 == '\n')
			{
				// **** last name on line ****

				if (firstNameOnLine)
				{
					// Only single name on line

					cout << buffer << endl;
				}
				else
				{
					// More than 1 name on line. At last name on line

					// Print last name
					cout << buffer;

					// Print other names
					for (int i = nameCounter - 1; i >= 0; i--)
					{
						cout << " " << *(nameCollection + i);

						delete[] nameCollection[i];
					}

					// Reset for next line's input
					cout << endl;

					delete[] nameCollection;
				}

				// Reset Flags and counters for next line
				firstNameOnLine = true;
				nameCounter = 0;
			}
			else
			{
				if (cin.eof())
				{
					break;
				}

				// **** More than 1 name on line. Before last name on line ****
				const size_t lengthOfNewName = strlen(buffer);

				if (firstNameOnLine)
				{
					// First name on line - Have to create name collection
					nameCollection = new char*[1];

					nameCollection[0] = new char[lengthOfNewName + 1];
					for (int i = 0; i < lengthOfNewName; i++)
					{
						*(nameCollection[0] + i) = buffer[i];
					}
					*(nameCollection[0] + lengthOfNewName) = '\0';

					firstNameOnLine = false;
				}
				else
				{
					// Extend name collection
					tempCollection = new char*[nameCounter + 1];

					for (size_t i = 0; i < nameCounter; ++i)
					{
						tempCollection[i] = nameCollection[i];
					}

					// creating new temparary array
					tempCollection[nameCounter] = new char[lengthOfNewName + 1];

					for (int i = 0; i < lengthOfNewName; i++)
					{
						*(tempCollection[nameCounter] + i) = buffer[i];
					}
					*(tempCollection[nameCounter] + lengthOfNewName) = '\0';

					delete[] nameCollection;

					nameCollection = tempCollection;
				}
				nameCounter++;
			}
		}
	}
	return 0;
}