// CST126SRS02.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <iomanip>

#include <ostream>
#include <string>

using namespace std;
int counting_words(string Names);
int main()
{
	string names[257];
	string Names;
	char array[] = { 0 };
	int size = 0;
	int w = 1;
	cout << "What are the names you wish to input?" << endl;
	cin >> setw(256) >> Names;
	getline(cin, Names);
	int counting_words = w; // You seem confused? Local name wipes out function. 
	for (int x = 0; x < w; x++)
	{
		for (int i = 0; i < x; i++)
		{
			cin >> array[i];
			for (i = x; x >= 0; i--)
			{
				cout << "Names in reverse order" << endl;
				cout << array[i];
			}
		}
	}
	system("PAUSE");
	return 0;
}
int counting_words(string Names) // This appears to count spaces, not words. Should be a noun, like word_count since it calculates an answer from an input that doesn't change state. 
{
	int w = 1;
	for (std::size_t i = 0; i < Names.length(); i++)
	{
		if (Names[i] == ' ')
		{
			w++;
		}
	}
	return w;
}