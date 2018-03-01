// main.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cstring>
// #include <fstream> // NO FILE I/O. 

using namespace std;

void reverseNames(int &numNames, char ** &names, char ** &temp) // No use upon return. Not required to be ref type or passed. Ref is more expensive if the type is either small or movable. Don't think like Java programmer. This technique is slow. Java uses references everywhere. C++ programmers use copy unless required or there is a known speed issue. 
{
	// get names from user, put names in ragged array
	names = new char * [numNames] {};
	const int maxLength = 257; //256 + null char
	int i = 0;
	while (i < numNames) { // Inconsistent bracing. Either same line or next line.
		// add name to ragged array
		if (cin.peek() == '\n' && i != 0) break; // make sure there are names
		if (!cin.good()) break; //end of file or errors 

		names[i] = new char[maxLength];
		cin >> setw(maxLength) >> names[i];

		// test if length is max
		if (std::strlen(names[i]) >= maxLength)
		{	//move point to next name if current name is super long // wouldn't actually point to the next name, but nice idea and good effort. 
			while (true)
			{
				const char next = cin.get();
				// if (isspace(next) || !cin.good()) break; // Same as below but simplfied. 
				if (!isspace(next) && cin.good()) continue;
				else break;
			}
		}

		i++;
		if (i == numNames) {
			// need a bigger array, reallocation
			numNames *= 2;

			temp = new char *[numNames] {};
			for (int j = 0; j < i; j++) // TODO: Not DRY (Don't Repeat Yourself). The division is a maintenance problem. Just double it once. 
			{
				temp[j] = names[j];
			}

			delete[] names;
			names = temp;
		}
	}

	// output names in reverse order
	for (int i = numNames - 1; i >= 0; i--)
	{
		if (names != nullptr && names[i] != nullptr) // Good work being safe with pointers. Almost fully checked, but serious points for the attempt. You were the only student to do this. 
		{
			cout << names[i] << " ";
			delete[] names[i]; // Can be null, that's okay but slower since you already checked. 
		}
	}
	delete[] names;
	cout << endl;

	if (cin.good()) { //not end of file
					  //recursion // Recursion is expensive and dangerous, especially in this case. This isn't a good case to use it as a loop is clearer, easy, and more efficient. 
		numNames = 1;
		reverseNames(numNames, names, temp);
	}
}

int main()
{
	int numNames = 1;
	char ** names;
	char ** temp;

	//recursive function, runs until user ends file
	reverseNames(numNames, names, temp);

	return 0;
}
