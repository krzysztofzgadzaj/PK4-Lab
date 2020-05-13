#include <iostream>
#include <fstream>
#include "RegularExpressions.h"

bool ifFileIsGood(std::string fileName)
{
	std::ifstream file;
	file.open(fileName);

	if (file.is_open())
	{
		RegularExpressions rE;
		std::string line;

		while (!file.eof())
		{
			std::getline(file, line);
			
			if (!rE.name_surname_gender(line))
			{
				file.close();
				return false;
			}
		}
		file.close();
		return true;
	}
	else
	{
		std::cout << "Blad odczytu pliku";
	}
}

int countMen(std::string fileName)
{
	std::ifstream file;
	file.open(fileName);
	int counter = 0;

	if (file.is_open())
	{
		RegularExpressions rE;
		std::regex reg("M$");
		std::string line;

		while (!file.eof())
		{
			std::getline(file, line);

			if (std::regex_search(line, reg))
			{
				counter++;
			}
		}

		return counter;
	}
	else
	{
		std::cout << "Blad odczytu pliku";
		return 0;
	}
}

int main()
{
	//Zad 1
	RegularExpressions rE;
	std::regex reg("(Jan[^, ]*)");
	std::string str = "Jan, Janusz, Patryk, Ania, Janislaw Kowalski, Janina";
	rE.print_matchtes(str, reg);
	std::cout << std::endl;

	//Zad 2
	rE.print_matchtes_with_iterator(str, reg);
	std::cout << std::endl;

	//Zad 3
	std::cout << rE.count_matches(str, reg);
	std::cout << std::endl;

	//Zad 4
	std::string sec_str = "Pan";
	std::regex reg2("(Jan)");
	rE.replace(str, reg2, sec_str);
	std::cout << str << std::endl;

	//Zad 5
	std::string nsd = "Adam Kowalski 01-01-1111";
	std::cout << rE.name_surname_date(nsd) << std::endl;

	//Zad 6
	nsd = "Adam Kowalski M";
	std::cout << rE.name_surname_gender(nsd) << std::endl;

	if (ifFileIsGood("imiona_i_nazwiska.txt"))
	{
		std::cout << countMen("imiona_i_nazwiska.txt");
	}
	system("pause");
	return 0;
}