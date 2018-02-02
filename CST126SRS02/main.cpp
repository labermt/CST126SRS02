/***********************************************************
* Class ID:			Mespirit
* Date Created:		1/25/18
* Updated:			1/31/18
* Assignment:		CST126SRS02
* Filename:			main.cpp
***********************************************************/
#include <iostream>
#include <iomanip>
#include <cstring>

const int const name_len = 256;

int main()
{
	char ** names = 0;

	char name[name_len];

	read(names, name);

	populate();

	return 0;
}
//pulls in line of text from user
void read(char ** names, char name[]) 
{
	
	std::cin >> std::setw(256) >> name;
}
//fill array with names
void populate()
{

}
//pull in lines of text (one line at a time) with max name length of 256 characters.

//check for char or continuous chars, in the line of text. Also check for '\0' escape operator. 

//If escape operator is found, jump to line 28.

//If found insert chars into a char array (name), check for end (white space separator) up until 256 character cap is reached.

//If end is found, insert name into a array of names. Check for chars again, looping line 20-26 until no names are left.

//Output the initial inputs in reverse to the console (cout).