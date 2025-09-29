// SimpleCompositionDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<array> 
#include <vector>




struct ColorRGB
{
    unsigned int R, G, B;  // 0 to 255

    /*Look at my fancy documentation!*/
    ColorRGB() = default; 
};

struct Point
{
    int x, y; 
};

/*A `Line` is composed of a `Color` object*/
class LineSegment
{
private: 
    //Point p1, p2; 

    int x1{}, x2{}, y1{}, y2{};

public: 
    ColorRGB lineColor{};
    LineSegment(const int x1, const int y1, const int x2, const int y2, const ColorRGB& lineColor)
        :
        x1(x1), y1(y1), x2(x2), y2(y2), lineColor(lineColor)
    {
    };

    void printLineSegmentAttributes() const 
    {
        std::cout << "First point is: " << x1 << " , " << y1 << "\n";
        std::cout << "Second point is: " << x2 << " , " << y2 << "\n";
        std::cout << "Line color has RGB values = " << lineColor.R << "," << lineColor.G << "," << lineColor.B
            << "\n";
    }
};

/*A `Polygon` is composed of Line objects*/
class Polygon
{
    std::vector<LineSegment> lines; //SHOULD this be a dynamic array?  
    //int numberOfLines; 
    //insert other attributes or functions (area, perimeter, etc.)

    void printPolygonAttribs()
    {
        std::cout << "THe lines in the polygon can be described as follows: " << "\n";
        std::cout << "Blue channel of line number 0 is " << lines.at(0).lineColor.B << "\n";


    }

public: 
    Polygon(const std::vector<LineSegment>& lines)
        :lines(lines)
    {

    }

    void printPolygonAttributes()
    {
        int currentLineNumberInPolygon = 1;

        for (const auto& line : lines)
        {
            std::cout << "\n\nFor line number: " << currentLineNumberInPolygon << "\n";
            line.printLineSegmentAttributes(); 

            currentLineNumberInPolygon++;
        }
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
    ColorRGB blue = { 0, 0, 255 };

    LineSegment leftLineOfSquare(0, 0, 0, 100, black);
    LineSegment rightLineOfSquare(100, 0, 100, 100, blue);
    LineSegment topLineOfSquare(0, 100, 100, 100, white);
    LineSegment bottomLineOfSquare(0, 0, 100, 0, red);


    std::vector<LineSegment> theLinesComposingTheSquare =
    {
        leftLineOfSquare, 
        rightLineOfSquare, 
        topLineOfSquare,
        bottomLineOfSquare
    };

    Polygon square(theLinesComposingTheSquare);

    square.printPolygonAttributes(); 

}

