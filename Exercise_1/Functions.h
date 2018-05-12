#pragma once
#include "stdafx.h"
#include <fstream>
#include <string>
#include <regex>
#include <sstream>
#include <cctype>

using namespace std;

class Functions
{
public:
	static string upper(string text);

	static string ReadFile(string path);

	static string Filter(string text);

	static int Int8_t2Int(int8_t data);

	static string Dec2Bin(int n);

	static int Hex2Dec(string number);

	static string Dec2Hex(int number);

	static int Bin2Dec(string number);

	static int BitCount(string number);
};