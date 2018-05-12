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
#include <vector>

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

int Int8_t2Int(int8_t data)
{
	if (atoi(to_string(data).c_str()) < 0)
	{
		return 256 + atoi(to_string(data).c_str());
	}
	else
		return atoi(to_string(data).c_str());
}

string Dec2Bin(int n)
{
	string bin;
	int binaryNum[8];
	int i = 0;
	while (n > 0) {
		binaryNum[i] = n % 2;
		n = n / 2;
		i++;
	}
	for (int j = i - 1; j >= 0; j--)
		bin += to_string(binaryNum[j]);
	string copy(bin);
	reverse(copy.begin(), copy.end());
	return bin;
}

int Hex2Dec(string number)
{
	stringstream ss;
	ss << hex << number;
	int x;
	ss >> x;
	return x;
}

string Dec2Hex(int number)
{
	stringstream ss;
	ss << hex << number;
	return  upper(ss.str());
}

int Bin2Dec(string number)
{
	int decimalNumber = 0, i = 0, remainder,n;
	n = atoi(number.c_str());
	while (n != 0)
	{
		remainder = n % 10;
		n /= 10;
		decimalNumber += remainder * pow(2, i);
		++i;
	}
	return decimalNumber;
}

int BitCount(string number)
{
	int count = 0;
	for (int i = 0; i < number.size(); i++)
	{
		if (number[i] == '1')
		{
			count++;
		}
	}
	return count;
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

	vector<int> Even, Odd;

	for (int i = 0; i < ArrayLenght; i++)
	{
		if ( BitCount(Dec2Bin(Int8_t2Int(Array[i]))) % 2 == 0)
		{
			Even.push_back(Int8_t2Int(Array[i]));
		}
		else
		{
			Odd.push_back(Int8_t2Int( Array[i]));
		}
	}

	sort(Even.begin(), Even.end());
	//TODO Descending order for ODD

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
	OddFile << upper(OddResult.str());
	EvenFile << upper(EvenResult.str());
	OddFile.close();
	EvenFile.close();

	cout << "Done";
	_getch();

	delete[] Array;
	return 0;
}