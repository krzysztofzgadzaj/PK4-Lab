#pragma once

#include <typeinfo>
#include <iostream>

template<typename type1, typename type2>
class Pair
{
	type1 var1;
	type2 var2;
public:
	Pair(type1 _var1, type2 _var2)
	{
		var1 = _var1;
		var2 = _var2;
	}

	void checkType()
	{
		std::cout << typeid(var1).name() << std::endl;
		std::cout << typeid(var2).name() << std::endl;
	}
};