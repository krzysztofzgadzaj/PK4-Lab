#ifndef CLASSROOM_H
#define CLASSROOM_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

struct Student {
	std::string name;
	std::string surname;
	std::string gender;
public:
	Student(std::string _name, std::string _surname, std::string _gender);
};

class Classroom {
	std::vector<Student> vec;
public:
	Classroom(const std::string fileName);
	bool anyNam(const std::string& value);
	bool anySurname(const std::string& value);
	bool anyGender(const std::string& value);
	bool noneName(const std::string& value);
	bool noneSurname(const std::string& value);
	bool noneGender(const std::string& value);
	bool allName(const std::string& value);
	bool allSurname(const std::string& value);
	bool allGender(const std::string& value);
};

#endif // !CLASSROOM_H
