#include <iostream>
#include "function.h"
#include "point.h"
#include "pair.h"

int main() {

	//1
	print(2);
	print(2.5);
	print("dwa kropka piec");

	//3
	Point<int> p1(1, 2);
	Point<unsigned int> p2(3, 4);
	Point<float> p3(5.6, 7.8);
	p1.print();
	p2.print();
	p3.print();

	//4
	Pair<int, std::string> p(2, "dwa");
	p.checkType();

	system("pause");
	return 0;
}

