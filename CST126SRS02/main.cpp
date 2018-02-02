//Reference:
// https://www.whitman.edu/mathematics/c++_online/section04.03.html 
// 

#include "stdafx.h"
#include <iostream>
#include <crtdbg.h>
#include <cstring>

using namespace std;

int main()
{
	char option = 'y';
	int num = 5;
	char** array = new char*[num];

	for (int i = 0; i < num; ++i)
		array[i] = new char[257];

	while (option == 'y')
	{
		int count = 0;
		int i = 0;

		cout << "Please enter the text to reverse(Ctr_Z to finish):" << endl;

		while (cin >> array[i])
		{
			i++;
			if (i >= num)
			{
				char** array2 = new char*[num * 2];

				for (int i = 0; i < num * 2; ++i)
					array2[i] = new char[257];

				for (int i = 0; i<num; i++) {
					array2[i] = array[i];
				}
				num = (num * 2);
				delete[] array;
				array = array2;
			}
		}

		int length = i + 1;
		char** temporary = new char*[num];

		for (int i = 0; i < num; ++i)
		{
			temporary[i] = array[i];
		}

		for (int i = 0; i < (length / 2); i++)
		{
			array[i] = array[(length - 1) - i];
			array[(length - 1) - i] = temporary[i];
		}

		cout << "Reverse order: \n";

		for (int i = 1; i < length; i++)
			cout << array[i] << "  ";

		std::cin.clear();
		std::cin.sync();

		cout << "\nDo you want to reverse another line((y)es/(n)o):" << endl;
		cin >> option;
		cout << endl;
	}

	std::cin.clear();
	std::cin.sync();

	for (int i = 0; i < num; ++i)
		delete[] array[i];

	delete[] array;

	return 0;
}
