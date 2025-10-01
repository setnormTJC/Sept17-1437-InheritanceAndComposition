#include <iostream>

#include<chrono> 
#include<thread> //a "thread" of execution 

#include "image.h"

using namespace std;

int main() {

	const int width = 640;
	const int height = 480;

	image Image(width, height);

	for (int y = 0; y < height; y++) {

		for (int x = 0; x < width; x++) {
			Image.SetColor(Color(255, 255, 255), x, y);
		}
	}
	Image.Export("image.bmp");

	std::system("image.bmp"); //nice way to automatically open the image on program execution


	std::this_thread::sleep_for(std::chrono::seconds(1));  //"animation"


	std::system("image.bmp"); //nice way to automatically open the image on program execution

}