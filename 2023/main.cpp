#include "Day00/Day00.hpp"

#include <iostream>
#include <chrono>
#include <functional>
#include <array>
#include <vector>

class Test
{
public:
	Test(std::string puzzleName, std::function<std::string(void)> puzzleFunction)
		: m_PuzzleName(puzzleName), m_PuzzleFunction(puzzleFunction), m_CompletionTime(0.0), m_PuzzleResult("NULL")
	{

	}

	double TestFunction()
	{
		auto t1 = std::chrono::high_resolution_clock::now();
		m_PuzzleResult = m_PuzzleFunction();
		auto t2 = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double, std::milli> completionTime = t2 - t1;

		m_CompletionTime = completionTime.count();

		return m_CompletionTime;
	}

	std::string m_PuzzleName;
	std::function<std::string(void)> m_PuzzleFunction;
	double m_CompletionTime;
	std::string m_PuzzleResult;
};

void RunTests(std::vector<Test> tests)
{
	std::cout << "| -------------- | --------------- | -------------------------------- |\n";
	std::cout << "| Puzzle Name    | Completion Time | Puzzle Result                    |\n";
	std::cout << "| -------------- | --------------- | -------------------------------- |\n";

	for (auto& test : tests)
	{
		test.TestFunction();

		std::array<char, 14> puzzleName;
		puzzleName.fill(' ');
		for (int i = 0; i < test.m_PuzzleName.length(); i++)
		{
			if (i == puzzleName.size())
				break;
			puzzleName[i] = test.m_PuzzleName[i];
		}

		std::array<char, 15> completionTime;
		completionTime.fill(' ');
		std::string completionTimeString = std::to_string(test.m_CompletionTime);
		for (int i = 0; i < completionTimeString.length(); i++)
		{
			if (i == completionTime.size())
				break;
			completionTime[i] = completionTimeString[i];
		}

		std::array<char, 32> puzzleResult;
		puzzleResult.fill(' ');
		for (int i = 0; i < test.m_PuzzleResult.length(); i++)
		{
			if (i == puzzleResult.size())
				break;
			puzzleResult[i] = test.m_PuzzleResult[i];
		}

		std::cout << "| ";
		for (int i = 0; i < puzzleName.size(); i++)
		{
			 std::cout << puzzleName[i];
		}
		std::cout << " | ";
		for (int i = 0; i < completionTime.size(); i++)
		{
			std::cout << completionTime[i];
		}
		std::cout << " | ";
		for (int i = 0; i < puzzleResult.size(); i++)
		{
			std::cout << puzzleResult[i];
		}
		std::cout << " |\n";

		std::cout << "| -------------- | --------------- | -------------------------------- |\n";
	}

	// TODO: Some final message.
}

int main()
{
	std::vector<Test> tests{};

	Test Day00Part1Test("Day 0, Part 1", Day00Part1);
	tests.push_back(Day00Part1Test);

	RunTests(tests);

	return 0;
}