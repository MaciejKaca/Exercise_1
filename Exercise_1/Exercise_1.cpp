// Exercise_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
#include <conio.h>
#include <regex>

using namespace std;

string ReadFile(string path)
{
	ifstream file(path);
	string content((std::istreambuf_iterator<char>(file)),
		(istreambuf_iterator<char>()));
	return content;
}

string Filter(string text)
{
	regex range("[^A-F\\d]");
	return regex_replace(text, range, "$2"); 
}


int main()
{
	return 0;
}

