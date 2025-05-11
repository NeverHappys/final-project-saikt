#pragma once
class Point
{
private:
	int x, y;
public:
	Point() {};
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int getx();
	int gety();
	void setx(int x);
	void sety(int y);
};

