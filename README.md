# CST126SRS02
Reverse
open file using relative path and go back to relative path


Class ID: Tangela	

SRS ID: CST126SRS02

Unresolved Issues:  
	1. If there is whitespace after the last word then the reversed line
	   will begin with whitespace.
	2. 

Notes:  
	1. Compiled with Visual Studio 2017 on Windows 10
	2. Reads in from "myfile.txt"
	3. Got help for reverse and reverse_words functions from 
	   https://www.geeksforgeeks.org/reverse-words-in-a-given-string/

---

Purpose:  

Learn to use heap memory and properly clean up your data without leaks or corruption.  
Redirect cin and cout to file i/o.

Instructions:  

Read text from std::cin into a ragged cstring array until the end of line is reached.  

Each element of the ragged array must be allocated on the heap.  

Each line can have zero, one, or multiple names.  

For example:  

Doublade Drilbur Hippopotas Inkay Jigglypuff lllumise Magcargo Mespirit  
Mudkip Ninetales  
  
Persian Phantump Seadra  
Shelmet  
Sliggoo Solrock Spearow Spheal Staryu Tangela Tentacool  

Process the data stored in the ragged array to std:cout in reverse order.

Mespirit Magcargo lllumise Jigglypuff Inkay Hippopotas Drilbur Doublade  
Mudkip Ninetales  
  
Seadra Phantump Persian  
Shelmet  
Tentacool Tangela Staryu Spheal Spearow Solrock Sliggoo  

The processing is done on a line by line basis. Each line input is echoed back in reverse order before processing the next line. 

A name can be a maximum of 256 characters.  

There is no limit on the number of lines or the number of names per line.  

Be certain to properly clean up any allocated memory. Leaks and memory corruption will be graded harshly.  

TIPS: 
- There is NO file I/O in this assignment. NONE!  Only std::cin and std::cout. 
- Be certain to read the Class Policy document on things "not expressly mentioned in an SRS". 
- You may want to redirect your input and output using the Windows command shell. ex: >out.txt <in.txt 
- Read about redirecting input and output from a Windows shell if this isn't clear. 
- When processing data directly from cin, you can generate an eof by entering Ctrl-Z on a line by itself. 


