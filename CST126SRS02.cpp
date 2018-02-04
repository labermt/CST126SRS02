// CST126SRS02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void reverse(char *begin, char *end);

void reverse_words(char *s)
{
	char *word_begin = s;
	char *temp = s;

	while (*temp)
	{
		temp++;
		if (*temp == '\0')
		{
			reverse(word_begin, temp - 1);
		}
		else if (*temp == ' ')
		{
			reverse(word_begin, temp - 1);
			word_begin = temp + 1;
		}
	}
	reverse(s, temp - 1);
}

void reverse(char *begin, char *end)
{
	char temp;
	while (begin < end)
	{
		temp = *begin;
		*begin++ = *end;
		*end-- = temp;
	}
}

int main()
{
	ifstream infile("myfile.txt");
	string line;
	char * array;

	if (infile.is_open())
	{
		cout << "File opened\n";

		while (getline(infile, line))
		{
			array = new char[line.length() + 1];

			for (int i = 0; i < line.length() + 1; i++)
			{
				array[i] = line[i];
			}
			cout << endl;

			char *temp = array;
			reverse_words(array);
			cout << array;
		}
		cout << endl;

		infile.close();
	}
	else cout << "Unable to open file\n";

	if (infile.is_open())
	{
		cout << "File still opened\n";
	}
	else cout << "File closed\n";
	
	return 0;
}

