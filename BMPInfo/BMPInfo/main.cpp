
#include <iostream>
#include "MyBMP.h"

using namespace std;

int main(int argc, char *argv[])
{
	MyBMP *myBmp = new MyBMP();

	CHAR dirPath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, dirPath);

	string bmpPath;
	bmpPath.append(dirPath);

	myBmp->readFile(bmpPath + "\\MyBMP.bmp");

	delete myBmp;
	myBmp = nullptr;

	return 0;
}