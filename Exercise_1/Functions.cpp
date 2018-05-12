#include "stdafx.h"
#include  "Functions.h"
#include <fstream>
#include <string>
#include <regex>
#include <sstream>
#include <cctype>

using namespace std;


string Functions::upper(string text)
{
	for (int i = 0; i < text.length(); i++)
	{
		text[i] = toupper(text[i]);
	}
	return text;
}

string Functions::ReadFile(string path)
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

string Functions::Filter(string text)
{
	regex range("[^A-F\\d]");
	return regex_replace(text, range, "");
}

int Functions::Int8_t2Int(int8_t data)
{
	if (atoi(to_string(data).c_str()) < 0)
	{
		return 256 + atoi(to_string(data).c_str());
	}
	else
		return atoi(to_string(data).c_str());
}

string Functions::Dec2Bin(int n)
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

int Functions::Hex2Dec(string number)
{
	stringstream ss;
	ss << hex << number;
	int x;
	ss >> x;
	return x;
}

string Functions::Dec2Hex(int number)
{
	stringstream ss;
	ss << hex << number;
	return  upper(ss.str());
}

int Functions::Bin2Dec(string number)
{
	int decimalNumber = 0, i = 0, remainder, n;
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

int Functions::BitCount(string number)
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
