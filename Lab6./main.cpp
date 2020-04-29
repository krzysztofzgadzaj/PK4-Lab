#include <iostream>
#include <string>
#include <memory>
#include "Book.h"

void fibonacciNumber(int size)
{
	if (size < 1)
	{
		std::cout << "Zle dane";
	}

	else if ((size == 1) || (size == 2))
	{
		std::cout << "1";
	}

	else
	{
		std::unique_ptr<int[]> tab{ new int[size] };
		tab[0] = 1;
		tab[1] = 1;
		if (size > 2)
		{
			for (int i = 2; i < size; ++i)
			{
				tab[i] = tab[i - 1] + tab[i - 2];
			}
		}
		for (int i = 0; i < size; ++i)
		{
			std::cout << tab[i] << std::endl;
		}
	}
}

int main()
{
	std::string bookName = "BookOne";
	{
		std::shared_ptr<book> sp(new book(bookName, 100));
		std::cout << sp.use_count() << std::endl;
		{
			auto sp2 = sp;
			std::cout << sp.use_count() << std::endl;
			{
				auto sp3 = sp;
				std::cout << sp.use_count() << std::endl;
			}
			std::cout << sp.use_count() << std::endl;
		}
		std::cout << sp.use_count() << std::endl;
	}

	fibonacciNumber(5);
	system("pause");
	return 0;
}