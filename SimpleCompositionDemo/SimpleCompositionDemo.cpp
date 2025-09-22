// SimpleCompositionDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>



struct ColorRGB
{
    unsigned int R, G, B;  // 0 to 255
};

struct Line
{
    int lineLength;
    ColorRGB lineColor; 
};

class Polygon
{
    std::vector<Line> lines; 

    //insert other attributes (area, perimeter, etc.)

};

class Triangle : public Polygon
{

};

class Rectangle : public Polygon
{

};


int main()
{
    std::cout << "Hello World!\n";
}

