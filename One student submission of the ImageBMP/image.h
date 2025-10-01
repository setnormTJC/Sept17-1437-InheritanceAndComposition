#pragma once

#include <vector>

using namespace std;

struct Color {

	float r, g, b;

	Color();
	Color(float, float, float);
	~Color();

};
class image
{
public:
	image(int width, int height);
	~image();

	Color GetColor(int, int) const;
	void SetColor(const Color& color, int x, int y);

	void Export(const char* path) const;

private:
	int m_width;
	int m_height;
	vector<Color> m_colors;

};


