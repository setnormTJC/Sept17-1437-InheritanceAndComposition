// PlayingWithBitmapImageAPI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include"ImageBMP.h"

int main()
{
	ImageBMP theImage(100, 50, Color(123, 1, 123));

	const std::string filename = "mySpecialImage.bmp";

	theImage.writeImageFile(filename); 

	std::system(filename.c_str());

}

