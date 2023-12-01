#include "Day01.hpp"

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <iterator>
#include <algorithm>

bool NotDigit(char c)
{
	return '0' <= c && c <= '9';
}

std::string Day01Part1()
{
	std::vector<std::string> input = {
		{"1abc2"},
		{"pqr3stu8vwx"},
		{"a1b2c3d4e5f"},
		{"treb7uchet"}
	};

	int total = 0;

	for (auto line : input)
	{
		std::string number;
		std::copy_if(line.begin(), line.end(), std::back_inserter(number), NotDigit);

		total += ((int)number[0] - 48) * 10;
		total += ((int)number[number.length() - 1]) - 48;
	}

	return std::to_string(total);
}

std::string Day01Part2()
{
	return std::string();
}
