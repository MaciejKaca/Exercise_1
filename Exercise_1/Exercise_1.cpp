// Exercise_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
#include <conio.h>
#include <regex>
#include <sstream>

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
	string content = Filter(ReadFile("test.txt"));
	int8_t *Array = new int8_t[content.length()];
	cout << content.length()/2 << endl;
	for (int i = 0; i < content.length(); i+=2)
	{
		stringstream ss;
		int x;
		ss << hex << content[i] << content[i+1];
		ss >> x;
		Array[i] = static_cast<int>(x);
		cout << static_cast<int>(x) << endl;
	}

	cout << "Size " << sizeof(Array);
	_getch();
	return 0;
}

