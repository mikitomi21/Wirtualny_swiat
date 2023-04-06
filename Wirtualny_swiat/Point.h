#pragma once

using namespace std;

class Point {
private:
	int x, y;
public:
	Point(int x, int y);
	int GetX();
	int GetY();
	void SetX(int x);
	void SetY(int y);
	~Point();
};