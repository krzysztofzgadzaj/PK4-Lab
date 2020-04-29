#pragma once
#include <memory>
#include "Book.h"
class Shelf
{
private:
	struct list
	{
		std::shared_ptr<list> pNext;
		std::shared_ptr<list> pPrev;
		book element;
	};
	std::shared_ptr<list> pHead;
public:
	Shelf();
	~Shelf();

	void addElement(std::shared_ptr<book> el);
};

