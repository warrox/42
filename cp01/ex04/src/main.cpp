

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+        */
/*   Created: 2024/10/15 14:05:07 by whamdi            #+#    #+#             */
/*   Updated: 2024/10/15 15:41:33 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void sed4looser(const std::string &filename, const std::string &str1, const std::string &str2)
{
    std::ifstream inputFile(filename);
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename);
    if (!outputFile.is_open())
    {
        std::cerr << "Error: Could not create output file " << outputFilename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line))
    {
        std::string newLine;
        size_t pos = 0;
        size_t found;

        while ((found = line.find(str1, pos)) != std::string::npos)
        {
            newLine.append(line, pos, found - pos);
            newLine.append(str2);
            pos = found + str1.length();
        }
        
        newLine.append(line, pos, line.length() - pos);

        outputFile << newLine << std::endl;
    }

    inputFile.close();
    outputFile.close();
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <string_to_replace> <replacement_string>" << std::endl;
        return -1;
    }

    std::string filename = argv[1];
    std::string str1 = argv[2];
    std::string str2 = argv[3];

    sed4looser(filename, str1, str2);

    return 0;
}
