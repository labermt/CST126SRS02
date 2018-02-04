// CST126SRS02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>


int main()
{
	/*
	char* nList;
	nList = new char[240];
	char* rList;
	rList = new char[240];

	std::cin >> std::setw(256) >> nList;
	*/
	char* placer{};
	char* walker{};
	char* nameList;
	nameList = new char[240];
	char* spacer = nameList;
	char* reverseList;
	reverseList = new char[240];

	std::cin.get(nameList, 240);

	while (*spacer != '\0') {
		if (iswspace(*spacer)) {
			walker = spacer;
		};
		++spacer;
	};
	*walker = '\0';
	walker++;
	reverseList = walker;

	
	while (nameList != '\0') {
		char* walker{};
		spacer = nameList;
		while (*spacer != '\0') {
			if (iswspace(*spacer)) {
				walker = spacer;
			};
			++spacer;
		};
		*walker = '\0';
		walker++;

		placer = reverseList + strlen(reverseList);
		*placer = ' ';
		placer++;

		while(walker != '\0') {
			*placer = *walker;
			placer++;
			walker++;
		};
	};
	

	std::cout << strlen(reverseList);
	std::cout << '\n';
	std::cout << reverseList;
	

	delete[] nameList;
	delete[] reverseList;
	
    return 0;
}

