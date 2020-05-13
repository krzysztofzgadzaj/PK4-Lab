#pragma once
#include <iostream>
#include <string>
#include <regex>

class RegularExpressions
{
public:
	//Constructors and destructors
	RegularExpressions();
	~RegularExpressions();

	//Methods
	void print_matchtes(const std::string &str, std::regex reg);
	void print_matchtes_with_iterator(const std::string &str, std::regex reg);
	int count_matches(const std::string & str, std::regex reg);
	void replace(std::string & str1, std::regex reg, std::string & str2);
	bool name_surname_date(const std::string & str);
	bool name_surname_gender(const std::string & str);
};

