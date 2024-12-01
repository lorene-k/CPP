/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:09:17 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/11/22 14:59:03 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sys/stat.h>

void output_content(std::string content, std::string filename)
{
	filename.append(".replace");
	std::ofstream outfile(filename.c_str());
	if (!outfile)
	{
		std::cout << "Error: could not create file" << std::endl;
		return ;
	}
	outfile << content;
	outfile.close();
}

std::string	modify_content(std::string old_content, std::string s1, std::string s2)
{
	std::string				new_content;
	std::string::size_type	pos = 0;
	std::string::size_type	start_pos = 0;
	
	if (s1 == "")
		return (std::cout << "s1 is empty: .replace file not created.\n", "");
	while ((pos = old_content.find(s1, start_pos)) != std::string::npos)
	{
		new_content.append(old_content, start_pos, pos - start_pos);
		new_content.append(s2);
		start_pos = pos + s1.size();
	}
	new_content.append(old_content, start_pos, old_content.size() - start_pos);
	return (new_content);
}

int check_file(const char* file)
{
    struct stat		fileStat;

    if (stat(file, &fileStat) != 0)
        {return (std::cout << "Error: file doesn't exist\n", 1);}
    if (S_ISDIR(fileStat.st_mode))
        {return (std::cout << "Error: path refers to a directory\n", 1);}
	return (0);
}

std::string	get_content(const char* file)
{
	std::string		content;
	std::string		line;
	
	std::ifstream	infile(file);
	if (check_file(file))
		return ("");
	if (!infile)
		return (std::cout << "Error: file can't be opened\n", "");
	while (std::getline(infile, line))
	{
		content += line;
		content += '\n';
		if (infile.eof())
			break ;
	}
	infile.close();
	if (content == "")
		std::cout << "Error: file is empty\n";
	return (content);
}

int	main(int ac, char **av)
{
	if (ac != 4)
		return (std::cout << "3 arguments required: filename, s1, s2\n", 1);
	std::string curr_content = get_content(av[1]);
	if (curr_content == "")
		return (1);
	std::string new_content = modify_content(curr_content, av[2], av[3]);
	if (new_content != "")
		output_content(new_content, av[1]);
	return (0);
}
