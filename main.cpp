#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <iomanip>

// Tools from Microsoft for detecting memory leaks
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

char getCinPeek()
{
	char peek = std::cin.peek();
	while (peek != '\n' && isspace(peek))
	{
		std::cin.get();
		peek = std::cin.peek();
	}
	return peek;
}

bool reverse_names()
{
	size_t curMaxNames = 4;
	char** names = new char*[curMaxNames];
	names[0] = nullptr;
	size_t nullPosition = 0;
	char buffer[257]; // {};
	char peek = getCinPeek();
	bool ret = true;

	while (peek != '\n' && ret)
	{
		std::cin >> std::setw(sizeof(buffer)) >> buffer;
		peek = getCinPeek();
		const size_t bufferLength = std::strlen(buffer) + 1;
		names[nullPosition] = new char[bufferLength];
		std::memmove(names[nullPosition], buffer, bufferLength); // consider strcpy or the secure version of it. 

		if (std::cin.eof())
		{
			ret = false;
		}

		if (++nullPosition == curMaxNames)
		{
			curMaxNames *= 2;
			char** const doubleSizeNames = new char*[curMaxNames];
			for (auto i = 0ULL; i < nullPosition; i++)
			{
				doubleSizeNames[i] = names[i];
			}
			delete[] names;
			names = doubleSizeNames;
		}

		names[nullPosition] = nullptr;
	}
	std::cin.get();

	for (auto i = nullPosition; i-- > 0; )
	{
		std::cout << names[i] << ' ';
	}
	std::cout << std::endl;

	for (auto i = 0ULL; i < nullPosition; i++) // Tip: Heap deallocation is more efficient in reverse.
	{
		delete[] names[i];
	}
	delete[] names;

	return ret;
}

int main()
{
	while (reverse_names())
	{
		;
	}
	_CrtDumpMemoryLeaks();
	return 0;
}
