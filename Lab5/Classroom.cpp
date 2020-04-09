#include "Classroom.h"

Student::Student(std::string _name, std::string _surname, std::string _gender)
{
	name = _name;
	surname = _surname;
	gender = _gender;
}

Classroom::Classroom(const std::string fileName)
{
		std::ifstream file(fileName);
		if (file)
		{
			std::string name, surname, gender;
			while (!file.eof())
			{
				file >> name >> surname >> gender;
				vec.push_back(Student(name, surname, gender));
			}
			file.close();
		}
		else
			std::cout << "File error";
}

bool Classroom::anyNam(const std::string & value)
{
	return std::any_of(vec.begin(), vec.end(), [value](const Student& s) 
	{
		return s.name == value; 
	});
}

bool Classroom::anySurname(const std::string & value)
{
	return std::any_of(vec.begin(), vec.end(), [value](const Student& s)
	{
		return s.surname == value; 
	});
}

bool Classroom::anyGender(const std::string & value)
{
	return std::any_of(vec.begin(), vec.end(), [value](const Student& s)
	{
		return s.gender == value; 
	});
}

bool Classroom::noneName(const std::string & value)
{
	return std::any_of(vec.begin(), vec.end(), [value](const Student& s)
	{
		return !(s.name == value); 
	});
}


bool Classroom::noneGender(const std::string & value)
{
	return std::any_of(vec.begin(), vec.end(), [value](const Student& s)
	{
		return !(s.gender == value); 
	});
}

bool Classroom::allName(const std::string & value)
{
	return  std::all_of(vec.begin(), vec.end(), [value](const Student& s) 
	{
		return s.name == value; 
	});
}

bool Classroom::allSurname(const std::string & value)
{
	return  std::all_of(vec.begin(), vec.end(), [value](const Student& s)
	{
		return s.surname == value;
	});
}

bool Classroom::allGender(const std::string & value)
{
	return  std::all_of(vec.begin(), vec.end(), [value](const Student& s)
	{
		return s.gender == value;
	});
}

bool Classroom::noneSurname(const std::string & value)
{
	return std::any_of(vec.begin(), vec.end(), [value](const Student& s)
	{
		return !(s.surname == value); 
	});
}