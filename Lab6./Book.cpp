#include "book.h"

book::book(std::string text, int number)
{
	title = text;
	pages = number;
}

void book::DisplayBook()
{
	std::cout << title << " (" << pages << " stron)" << std::endl;
}
