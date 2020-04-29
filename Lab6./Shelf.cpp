#include "Shelf.h"



Shelf::Shelf()
{
}


Shelf::~Shelf()
{
}

void Shelf::addElement(std::shared_ptr<book> el)
{
	if (pHead == nullptr)
	{
		pHead = el;
	}

	else
	{
		std::shared_ptr<list> p = pHead;

		while (p != nullptr)
		{
			p = p->pNext;
		}

		p->pNext = el;
		p->pNext->pPrev = p;
	}
}