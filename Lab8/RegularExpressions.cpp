#include "RegularExpressions.h"


//Constructors and destructors
RegularExpressions::RegularExpressions()
{
}

RegularExpressions::~RegularExpressions()
{
}


//Methods
void RegularExpressions::print_matchtes(const std::string & str, std::regex reg)
{
	std::string _str = str;
	std::smatch sm;
	while (regex_search(_str, sm, reg))
	{
		std::cout << sm.str() << std::endl;
		_str = sm.suffix();
	}
}

void RegularExpressions::print_matchtes_with_iterator(const std::string & str, std::regex reg)
{
	auto words_begin = std::sregex_iterator(str.begin(), str.end(), reg);
	auto words_end = std::sregex_iterator();

	for (std::sregex_iterator i = words_begin; i != words_end; ++i) 
	{
		std::smatch match = *i;
		std::string match_str = match.str();
		std::cout << match_str << std::endl;
	}
}

int RegularExpressions::count_matches(const std::string & str, std::regex reg)
{
	int counter = 0;
	std::string _str = str;
	std::smatch sm;
	while (regex_search(_str, sm, reg))
	{
		counter++;
		_str = sm.suffix();
	}

	return counter;
}

void RegularExpressions::replace(std::string & str1, std::regex reg, std::string & str2)
{
	str1 = std::regex_replace(str1, reg, str2);
}

bool RegularExpressions::name_surname_date(const std::string & str)
{
	std::regex reg("[A-Z][a-z]+ [A-Z][a-z]+ [0-9]{2}-[0-9]{2}-[0-9]{4}");

	if (regex_match(str, reg)) 
		return true;

	return false;
}

bool RegularExpressions::name_surname_gender(const std::string & str)
{
	std::regex reg("[A-Z][a-z]+ [A-Z][a-z]+ (K|M)");

	if (regex_match(str, reg))
		return true;

	return false;
}




