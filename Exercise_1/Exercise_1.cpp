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
	ifstream file("test.txt");
	string content((std::istreambuf_iterator<char>(file)),
		(istreambuf_iterator<char>()));
	return content;
}

int main()
{
	return 0;
}

