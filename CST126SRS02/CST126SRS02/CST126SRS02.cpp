// CST126SRS02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>


int main()
{
	char* walker{};
	char* nameList;
	nameList = new char[240];
	char* spacer = nameList;
	std::cin.get(nameList, 240);
	while (*spacer != '\0') {
		if (iswspace(*spacer)) {
			walker = spacer;
		};
		++spacer;
	};
	*walker = '\0';
	walker++;
	std::cout << nameList;
	std::cout << '\n';
	std::cout << walker;
    return 0;
}

