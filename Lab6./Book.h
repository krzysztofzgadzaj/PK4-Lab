#pragma once
#include <string>
#include <memory>
#include <iostream>

class book
{
	std::string title;
	int pages;

public:
	book(std::string text, int number);
	book();
	void DisplayBook();
};

