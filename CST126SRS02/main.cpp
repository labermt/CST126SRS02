#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;
int main()
{
	auto capacity = 0;
	auto nameList = new char *[capacity];
	auto size = 0U;//a literal unsigned 0, it cannot go to negative with U 
	char name[258];
	while (cin.good())
	{
		auto nl = cin.peek(); //nl stands for newline 
		if (nl == '\n' || nl == '\t')
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
			int i{};
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
			cin >> setw(sizeof(name) - 1) >> name;//this is a static compiler knows about it 
			auto heapName = new char[strlen(name) + 1];
			strcpy(heapName, name);
			nameList[size] = heapName;
			size++;
		}
	}
	return 0;
}