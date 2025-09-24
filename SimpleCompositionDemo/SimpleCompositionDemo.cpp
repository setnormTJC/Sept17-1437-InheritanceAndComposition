// SimpleCompositionDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<array> 
#include <vector>




struct ColorRGB
{
    unsigned int R, G, B;  // 0 to 255
};

struct Point
{
    int x, y; 
};

/*A `Line` is composed of a `Color` object*/
struct Line
{
    //Point p1, p2; 

    int x1, x2, y1, y2; 
    //int lineLength; //calculated from x1, x2, y1, y2 -> maybe not a "great member var"
    ColorRGB lineColor; 

    Line(const int x1, const int y1, const int x2, const int y2, const ColorRGB& lineColor)
        :
        x1(x1), y1(y1), x2(x2), y2(y2)
    {
    };
};

/*A `Polygon` is composed of Line objects*/
class Polygon
{
    std::vector<Line> lines; //SHOULD this be a dynamic array?  
    //int numberOfLines; 
    //insert other attributes or functions (area, perimeter, etc.)

    void printPolygonAttribs()
    {
        std::cout << "THe lines in the polygon can be described as follows: " << "\n";
        std::cout << "Blue channel of line number 0 is " << lines.at(0).lineColor.B << "\n";


    }

public: 
    Polygon(const std::vector<Line>& lines)
        :lines(lines)
    {

    }
};


//ABANDON inheritance for now ... 
//class Triangle : public Polygon
//{
//    //a defining attribute: numberOfLines = 3; 
//};
//
//class Rectangle : public Polygon
//{
//
//};


int main()
{
    ColorRGB black = { 0, 0, 0 };
    ColorRGB white = { 255, 255, 255 };
    ColorRGB red = { 255, 0, 0 };
    ColorRGB green = { 0, 255, 0 };

    Line leftLineOfSquare(0, 0, 0, 100, red);

    Polygon square({});

}

