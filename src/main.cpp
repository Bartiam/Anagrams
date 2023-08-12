#include <iostream>
#include <string>
#include <Windows.h>
#include <map>

bool is_correct_input_data(const std::string& line)
{
	for (int i = 0; i < line.length(); ++i)
		if ((line[i] < 'a' || line[i] > 'z') && (line[i] < 'à' || line[i] > 'ÿ')) return false;

	return true;
}

bool is_anagram(const std::string& firstLine, const std::string& secondLine,
	std::map<char, char>& anagram)
{
	int currentSize;

	if (firstLine.length() != secondLine.length()) return false;

	for (int i = 0; i < firstLine.length(); ++i)
		anagram.emplace(firstLine[i], firstLine[i]);

	currentSize = anagram.size();

	for (int i = 0; i < secondLine.length(); ++i)
		anagram.emplace(secondLine[i], secondLine[i]);

	if (anagram.size() == currentSize) return true;
	else return false;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	std::string firstLine;
	std::string secondLine;
	std::map<char, char> anagram;

	std::cout << "Enter the first word: ";
	std::getline(std::cin, firstLine);
		
	std::cout << "Enter the second word: ";
	std::getline(std::cin, secondLine);

	if (is_correct_input_data(firstLine) &&
		is_correct_input_data(secondLine))
	{
		std::cout << is_anagram(firstLine, secondLine, anagram) << std::endl;
	}
	else std::cerr << "Error! Incorrect input data. " << std::endl;

	return 0;
}
