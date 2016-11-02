// CS 1410 Programming Project #06
// Copyright 2014, Utah Valley University
//Author: Matthew Vaughan
// Date last modified: August 2016
// Implementation file for main
// =======================================
//
// I declare that the following code was written by me or provided 
// by the instructor for this project. I understand that copying source
// code from any other source constitutes cheating, and that I will receive
// a zero on this project if I am found in violation of this policy.
// ---------------------------------------------------------------------------
// Need to #include the header file assocoiated with this .cpp file
#include "Header.h"

int main()
{
	string stringOne = "";
	string stringTwo = "";

	cout << "This program will find the occurence of one string inside another." << endl;
	cout << "Enter the string to be searched: ";

	getline(cin, stringOne);

	cout << "Now enter the string you want to search for: ";

	getline(cin, stringTwo);

	

	try
	{
		int x = 0;
		x = index_of(stringOne, stringTwo);
		cout << "It's a match at index: " << x << endl;
	}
	catch(logic_error)
	{
		cout << "Can't find the word " << stringTwo << " in " << stringOne << "\nSorry!" << endl;
	}

	system("PAUSE");
	return 0;
}

int index_of(const string& strOne, const string& strTwo)
{
	return index_of_helper(strOne, strTwo);
}

int index_of_helper(const string& strOne, const string& strTwo)
{
	int index = 0;
	int start = 0;

	if (strOne.length() == start)
	{
		if (strOne != strTwo)
		{
			throw logic_error("Can't find the word");
		}
	}

	else if (strOne.substr(start, strTwo.length()) == strTwo)
	{
		return index;
	}

	else
	{
		index++;
	}

	return index + index_of_helper(strOne.substr(1), strTwo);
}