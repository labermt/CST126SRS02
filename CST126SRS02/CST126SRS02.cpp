#include "stdafx.h"   //help from chegg website and leak test book page 462
#include <crtdbg.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <array>
using namespace std;
using std::ifstream;
using std::ofstream;
using std::array;


int main()   //tried fixing the d_scl_secure_no_warnings, could not figure out
{ //first attempt at solving the problem

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);  

	string ** firstcheck;

	ifstream cin("names.txt");

	string line;

	int len = 0;

	int wid = 0;

	while (getline(cin, line))
	{
		cout << "Configuring" << (len + 1) << "\n";

		istringstream iss(line);

		string word;

		wid = 0;

		if (len == 0)
		{
			firstcheck = new string *[1];
		}
		else
		{
			string ** a = new string *[len + 1];
			copy(firstcheck, firstcheck + min(len, len + 1), a);

			delete[] firstcheck;

			firstcheck = a;
		}

		while (getline(iss, word, ' '))
		{
			if (wid == 0)
			{
				firstcheck[len] = new string[1];
				firstcheck[len][wid] = word;
			}
			else
			{
				string * a = new string[wid + 1];
				copy(firstcheck[len], firstcheck[len] + min(wid, wid + 1), a);
				delete[]firstcheck[len];
				firstcheck[len] = a;
				firstcheck[len][wid] = word;
			}
			wid++;
		}
		cout << "Words in line " << (len + 1) << "\n";
		for (int i = 0; i < wid; i++)
		{
			cout << firstcheck[len][i] << "";
		}
		cout << "\n";
		len++;
	}
	cin.close();

	return 0;
}

// second attempt at solving the problem

const int bufferLength = 258;

void getString ( char *& str );

int main()
{
	char * str = nullptr;

	getString (str);

	cout << '\n' << str << endl;

	delete [] str;

	return 0;

}

void getString (char *& str)
{
	char buffer [bufferLength];

	cout << "Please enter a name: ";

	cin.ignore (cin.rdbuf() -> in_avail() );
	cin.getline (buffer, bufferLength);
	cin.clear();
	cin.ignore (cin.rdbuf() -> in_avail() );

	str = new char [strlen (buffer) +1];
	strcpy (str,buffer);
}
