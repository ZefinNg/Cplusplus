#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <Windows.h>

using namespace std;

class MyBMP
{
public:
	MyBMP();
	~MyBMP();

	bool readFile(const string& filePath);

private:
	int m_rows;
	int m_cols;
	int m_bitCount;
};

