// Exercise_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
#include <conio.h>
#include <regex>
#include <sstream>
#include <cctype>
#include <vector>
#include "Functions.h"
using namespace std;

struct greater
{
	template<class T>
	bool operator()(T const &a, T const &b) const { return a > b; }
};

int main()
{
	string FileName;
	cout << "Write file name example: ""name.txt"": ";
	cin >> FileName;
	if (Functions::ReadFile(FileName) == "!")
	{
		cout << "File not found!";
		_getch();
		return 0;
	}

	string content = Functions::Filter(Functions::ReadFile(FileName));
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

	vector<int> Even, Odd;

	for (int i = 0; i < ArrayLenght; i++)
	{
		if (Functions::BitCount(Functions::Dec2Bin(Functions::Int8_t2Int(Array[i]))) % 2 == 0)
		{
			Even.push_back(Functions::Int8_t2Int(Array[i]));
		}
		else
		{
			Odd.push_back(Functions::Int8_t2Int( Array[i]));
		}
	}

	sort(Even.begin(), Even.end());
	sort(Odd.begin(), Odd.end(), greater());

	stringstream EvenResult, OddResult;
	for (int i = 0; i < Even.size(); i++)
	{
		EvenResult << hex << Even.at(i);
		EvenResult << " ";

	}
	for (int i = 0; i < Odd.size(); i++)
	{
		OddResult << hex << Odd.at(i);
		OddResult << " ";
	}

	fstream OddFile("Odd.txt", ios::out);
	fstream EvenFile("Even.txt", ios::out);
	OddFile << Functions::upper(OddResult.str());
	EvenFile << Functions::upper(EvenResult.str());
	OddFile.close();
	EvenFile.close();

	cout << "Done";
	_getch();

	delete[] Array;
	return 0;
}