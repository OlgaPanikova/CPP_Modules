/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelichik <lelichik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:22:48 by lelichik          #+#    #+#             */
/*   Updated: 2024/11/18 19:29:14 by lelichik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <fstream>
#include <string>

class Harl {
private:
	void debug();
	void info();
	void warning();
	void error();
public:
	Harl();
	~Harl();
	void complain(std::string level);
};

#endif