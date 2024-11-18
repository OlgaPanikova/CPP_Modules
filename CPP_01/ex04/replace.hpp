/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelichik <lelichik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:20:04 by lelichik          #+#    #+#             */
/*   Updated: 2024/11/18 17:57:50 by lelichik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>

class Replace {
private:
	std::string filename;
	std::string s1;
	std::string s2;
	std::string text;
public:
	Replace(const std::string& filename, const std::string& s1, const std::string& s2);
	~Replace();
	int checkArguments();
	int readFile();
	void replaceOccurrences();
	int writeFile() const;
};

#endif
