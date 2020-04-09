#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "PermutatedSequence.h"
#include "RandomContainer.h"
#include "Account.h"
#include "Classroom.h"

int countIf(std::vector<int>::iterator begin, std::vector<int>::iterator end, std::function<bool(int i)> func)
{
	int counter = 0;

	while (begin != end)
	{
		if (func(*begin))
		{
			counter++;
		}
		begin++;
	}
	return counter;
}

int main (int argc, char** argv) {

	RandomContainer p(10, 1, 10);
	p.sort();
	std::cout << p;
	p.sortDesc();
	std::cout << p;

	PermutatedSequence q;
	q.allPermutations();

	std::vector<BankAccount> b;
	b.push_back(BankAccount(10));
	b.push_back(BankAccount(100));
	b.push_back(BankAccount(1000));
	b.push_back(BankAccount(10000));

	std::for_each(b.begin(), b.end(), [](BankAccount& c) { c.print(); });
	std::for_each(b.begin(), b.end(), [](BankAccount& c) { c.interest(); });
	std::for_each(b.begin(), b.end(), [](BankAccount& c) { c.print(); });

	Classroom c("students.txt");
	std::cout << c.anySurname("Pinochet") << std::endl;
	std::cout << c.noneSurname("Allende") << std::endl;
	std::cout << c.anyGender("k") << std::endl;
    
	std::vector<int> nums;

	for (int i = 0; i < 10; ++i)
		nums.push_back(i);

	std::cout << std::count_if(nums.begin(), nums.end(), [](int i) { return i % 3 == 0; }) << std::endl;
	std::cout << countIf(nums.begin(), nums.end(), [](int i) { return i % 3 == 0; });
	system("pause");
    return 0;
}