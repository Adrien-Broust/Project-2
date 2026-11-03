#pragma once
struct vector2
{
	int x;
	int y;

public:
	vector2(int v) : x(v) {}
	vector2(int b) : x(b) {}

	vector2 operator+(const vector2& n)
	{
		return vector2(x + n.x);
		return vector2(y + n.y);
	}

};