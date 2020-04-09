#pragma once
#include <iostream>

template <typename typ>
class Point {
private:
	typ x;
	typ y;
public:
	Point(typ _x, typ _y) :x(_x), y(_y) {}
	void print() {
		std::cout << "x: " << x << std::endl;
		std::cout << "y: " << y << std::endl;
	}
};