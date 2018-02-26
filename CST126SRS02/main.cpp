/***********************************************************
* Class ID:			Mespirit
* Date Created:		1/25/18
* Updated:			2/3/18
* Assignment:		CST126SRS02
* Filename:			main.cpp
***********************************************************/

#include <cctype>
#include <cstring> // string.h is for 'C' programs. C++ provided headers have no extension. 
#include <string>
#include <iostream>
#include <iomanip>

#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h> 
#endif _DEBUG


const int name_len = 256;

void read(char ** names, char *name);
void discern(char ** names, char *name, char * temp);
void populate(char **names, char *name, int k, int j);
void output(char ** names, int k);
void purge(char ** names, int k);
bool another();

int main()
{
	char ** names = new char*[10];
	char name[name_len];
	bool reprompt = true;

	do
	{ 
		read(names, name);

		reprompt = another();

	} while (reprompt); // Testing a bool for == true can be simply the bool. 

	// system("pause"); // No prompts allowed. See class policy. 

	return 0;
}
//pulls in line of text from user
void read(char ** names, char *name) 
{
	std::string text_line;
	std::size_t string_len = 0;

	std::cout << "Enter line of names: ";

	std::getline(std::cin, text_line);

	string_len = text_line.length();

	const auto temp = new char [string_len + 1];

	strcpy_s(temp, string_len+1, text_line.c_str());

	discern(names, name, temp);

	delete[] temp;
}
//finds beginning and end of each name in line
void discern(char ** names, char *name, char * temp)
{
	if (temp != nullptr)
	{
		int i = 0, k = 0;
		char ch = '0';

		while (ch != '\0') //checks for \0 (end of string) if found escapes loop
		{
			ch = temp[i];

			if (std::isspace(ch)) //checks if ch == whitespace
			{
				i++;
			}
			else
			{
				int j = 0;

				while (std::isspace(ch) == 0 && j != 255 && ch != '\0')
				{
					name[j] = temp[i];
					j++;
					i++;
					ch = temp[i];
				}

				populate(names, name, k, j);

				k++;
			}
		}

		output(names, k);

		purge(names, k);
	}
	else
	{
		std::cerr << "\nLine is nullptr\n";
	}
}
//fill array with names
void populate(char **names, char * name, int k, int j)
{
	for (int i = 0; i < j + 1; i++)
	{
		for (int l = 0; l < j + 1; l++)
		{
			names[k][i] = name[l]; // names is a pointer to an array of char*, NOT a 2D array. 
		}
	}
}
//outputs names in reverse of input
void output(char ** names, int k)
{
	for (int i = k; i > 0; i--)
	{
		std::cout << names[i] << ' ';
	}
}
//clears memory
void purge(char ** names, int k)
{
	for (int i = 0; i < k; ++i)
	{
		delete[]  names[i];
	}
	delete []names;
}
//another line of names?
bool another()
{
	char answ[3];
	static const auto yes = "yes";
	static const auto no = "no";
	static const auto char_no = "n";
	static const auto char_yes = "y";

	bool eq;
	bool reprompt; // RANDOM results. Not all paths initialize. Consider while loops please!

	std::cout << "Enter Another Line of Names? (y/n): ";

	do
	{
		int i = 0;

		std::cin >> answ;

		while (answ[i])
		{
			char c = answ[i];
			c = tolower(c);
			answ[i] = c;
			i++;
		}

		if (strcmp(answ, yes) == 0 || strcmp(answ, char_yes) == 0)
		{
			eq = true;
			reprompt = true;
		}
		else if (strcmp(answ, no) == 0 || strcmp(answ, char_no) == 0)
		{
			eq = true;
			reprompt = false;
		}
		else
		{
			eq = false;
			std::cerr << "\nInvalid Input. Enter Another Line of Names? (y/n): ";
		}
	} while (!eq);

	std::cout << std::endl;

	return reprompt;
}

//pull in lines of text (one line at a time) with max name length of 256 characters.

//check for char or continuous chars, in the line of text. Also check for '\0' escape operator. 

//If escape operator is found, short circuit.

//If found insert chars into a char array (name), check for end (white space separator) up until 256 character cap is reached.

//If end is found, insert name into a array of names. Check for chars again, looping steps until '\0' is found.

//Output the initial inputs in reverse to the console (cout).