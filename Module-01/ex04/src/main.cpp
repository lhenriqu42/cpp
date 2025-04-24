/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:59:43 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/04/24 14:57:14 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include <iostream>
#include <fstream>

static int	print_error(char *p_name)
{
	std::cout << C_RED "[Syntax error]\n    " C_GRN "How to use: " C_RST << p_name << C_CYA " <filename>" C_YEL " <string_to_replace> <string_to_replace_with>" C_RST << std::endl;
	return (1);
}

static void my_replace(std::string &buffer, const std::string &search, const std::string &replace)
{
	size_t pos = 0;
	while ((pos = buffer.find(search, pos)) != std::string::npos)
	{
		buffer.erase(pos, search.length());
		buffer.insert(pos, replace);
		pos += replace.length();
	}
}

int	main(int ac, char *av[])
{
	if (ac != 4)
		return (print_error(av[0]));

	const std::string filename = av[1];
	const std::string search = av[2];
	const std::string replace = av[3];

	std::string			buffer;
	
	std::ifstream		infile;
	std::ofstream		outfile;

	infile.open(filename.c_str());
	if (!infile.is_open())
	{
		std::perror(("Error opening file ->" C_RED + filename + C_RST).c_str());
		return (1);
	}
	
	outfile.open((filename + ".replace").c_str(), std::ios::out | std::ios::trunc );
	if (!outfile.is_open())
	{
		std::perror(("Error creating file ->" C_RED + filename + ".replace" C_RST).c_str());
		infile.close();
		return (1);
	}

	while (std::getline(infile, buffer))
	{
		my_replace(buffer, search, replace);
		outfile << buffer;
		if (!infile.eof())
			outfile << std::endl;
	}
	outfile.close();
	infile.close();
	std::cout << C_GRN "File " C_YEL << filename + ".replace" C_GRN " created successfully!" C_RST << std::endl;
}
