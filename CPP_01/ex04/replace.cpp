/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelichik <lelichik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:22:44 by lelichik          #+#    #+#             */
/*   Updated: 2024/11/18 18:18:47 by lelichik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

Replace::Replace(const std::string& filename, const std::string& s1, const std::string& s2) : filename(filename), s1(s1), s2(s2), text("") {}

Replace::~Replace() {}

int Replace::checkArguments()
{
	if(filename.empty() || s1.empty() || s2.empty())
	{
		std::cerr << "Error: one of the arguments is empty" << std::endl;
		return 1;
	}
	else
		return 0;
}

int Replace::readFile()
{
	std::ifstream inputFile(filename);
	if (!inputFile)
	{
		std::cerr << "Error: Could not open file " << filename << std::endl;
		return 1;
	}
	text.assign((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
	inputFile.close();
	if (text.empty())
	{
		std::cerr << "Error: The file is empty." << std::endl;
		return 1;
	}
	return 0;
}
bool isWordBoundary(char c)
{
	return !std::isalnum(c);
}

void Replace::replaceOccurrences()
{
	size_t pos = 0;
	while ((pos = text.find(s1, pos)) != std::string::npos)
	{
		if ((pos == 0 || isWordBoundary(text[pos - 1])) && 
			(pos + s1.length() == text.length() || isWordBoundary(text[pos + s1.length()])))
		{
			text.erase(pos, s1.length());
			text.insert(pos, s2);
			pos += s2.length();
		}
		else
			pos += s1.length();
	}
}

int Replace::writeFile() const
{
	std::ofstream outputFile(filename + ".replace");
	if (!outputFile)
	{
		std::cerr << "Error: Could not create file " << filename << ".replace" << std::endl;
		return 1;
	}
	outputFile << text;
	outputFile.close();
	return 0;
}