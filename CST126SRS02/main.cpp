#include "stdafx.h"

#include <iostream>
#include <iomanip>
#include <cassert>

// C++ statements are like sentences, use blank lines to separate paragraphs. 

using namespace std;

int main()
{
	auto capacity = 0U;
	auto nameList = new char *[capacity];
	auto size = 0U; // a literal unsigned 0, it cannot go to negative with U 

	while (cin.good())
	{
		const auto nl = cin.peek(); // nl stands for newline 

		if (nl == '\n') // Tabs don't end the input. 
		{
			assert(size <= capacity);
			while (size != 0)
			{
				size--;
				cout << nameList[size] << " ";
				delete[] nameList[size];
			}
			cout << endl;
		}

		if (size == capacity)
		{
			capacity = 2 * capacity + 1;
			auto const temp = new char*[capacity];
			unsigned i{}; // Should be std::size_t.
			while (i < size)
			{
				temp[i] = nameList[i];
				i++;
			}
			delete[] nameList;
			nameList = temp;
		}
		else
		{
			char name[258]; // Keep data as local as possible. 

			cin >> setw(sizeof(name) - 1) >> name; // this is a static compiler knows about it 
			const auto heapName = new char[strlen(name) + 1];
			strcpy(heapName, name);
			nameList[size] = heapName;
			size++;
		}
	}

	return 0;
}
