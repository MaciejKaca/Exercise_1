// Exercise_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
#include <conio.h>
#include <regex>
#include <sstream>
#include <stdio.h>
#include <ctype.h>

using namespace std;

string upper(string text)
{
	for (int i = 0; i < text.length(); i++)
	{
		text[i] = toupper(text[i]);
	}
	return text;
}

string ReadFile(string path)
{
	ifstream file(path);
	if (file.good() == true)
	{
		string content((std::istreambuf_iterator<char>(file)),
			(istreambuf_iterator<char>()));
		return content;
	}
	else
		return "!";
}

string Filter(string text)
{
	regex range("[^A-F\\d]");
	return regex_replace(text, range, ""); 
}

int conversionInt8_tTOint(int8_t data)
{
	if (atoi(to_string(data).c_str()) < 0)
	{
		return 256 + atoi(to_string(data).c_str());
	}
	else
		return atoi(to_string(data).c_str());
}

int main()
{
	string FileName;
	cout << "Write file name example: ""name.txt"": ";
	cin >> FileName;
	if (ReadFile(FileName) == "!")
	{
		cout << "File not found!";
		_getch();
		return 0;
	}

	string content = Filter(ReadFile(FileName));
	int8_t *Array = new int8_t[ceil(float(content.length())/2)];
	int ArrayLenght=0;

	for (int i = 0; i < content.length(); i+=2) //Putting 2 chars to Array fron content
	{
		stringstream ss;
		int x;
		ss << hex << content[i] << content[i + 1];
		ss >> x;
		Array[ArrayLenght] = x;
		ArrayLenght++;
	}

	int EvenCount = 0, OddCount = 0;
	int8_t *EvenArray = new int8_t[ceil(float(ArrayLenght) / 2)];
	int8_t *OddArray = new int8_t[ceil(float(ArrayLenght) / 2)];

	for (int i = 0; i < ArrayLenght; i++)
	{
		if (conversionInt8_tTOint(Array[i]) % 2 == 0)
		{
			EvenArray[EvenCount] = Array[i];
			EvenCount++;
		}
		else
		{
			OddArray[OddCount] = Array[i];
			OddCount++;
		}
	}

	stringstream EvenResult, OddResult;
	for (int i = 0; i < EvenCount; i++)
	{
		EvenResult  << hex << conversionInt8_tTOint(EvenArray[i]);
		EvenResult << " ";

	}
	for (int i = 0; i < OddCount; i++)
	{
		OddResult << hex << conversionInt8_tTOint(OddArray[i]);
		OddResult << " ";
	}

	fstream OddFile("Odd.txt", ios::out);
	fstream EvenFile("Even.txt", ios::out);
	OddFile << upper(OddResult.str());
	EvenFile << upper(EvenResult.str());
	OddFile.close();
	EvenFile.close();

	cout << "Done";
	_getch();

	delete[] Array;
	delete[] EvenArray;
	delete[] OddArray;
	return 0;
}