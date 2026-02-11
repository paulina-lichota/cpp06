/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:26:18 by plichota          #+#    #+#             */
/*   Updated: 2026/02/11 15:10:22 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

// inf, +inf, and nan

bool ScalarConverter::isChar(const std::string& literal)
{
    if (literal.length() == 1 && !std::isdigit(literal[0])
            && std::isprint(literal[0]))
        return true;
}

bool ScalarConverter::isInt(const std::string& literal)
{
    std::string temp = literal;
    size_t i = 0;
    // no longer than 11 digits (sign included)
    if (temp.length() > 11)
        return false;
    // can start with + or - or a number
    if (temp[0] == '+' || temp[0] == '-')
        temp = temp.substr(1);
    // all digits
    while (i < temp.length())
    {
        if (!std::isdigit(temp[i]))
            return false;
        i++;
    }
    // limit overflow
    double d = strtod(literal.c_str(), NULL);
    double max = std::numeric_limits<double>::max();
    double min = std::numeric_limits<double>::min();
    
    if (d > max || d < min)
        return false;
}

bool ScalarConverter::isFloat(const std::string& literal)
{
    // can start with + or -
    // some numbers
    // one dot
    // some numbers
    // f at the end
    // nothing else
}

bool ScalarConverter::isDouble(const std::string& literal)
{
    
}


void ScalarConverter::printChar(const std::string& literal)
{
    
}

void ScalarConverter::printInt(const std::string& literal)
{
    
}

void ScalarConverter::printFloat(const std::string& literal)
{
    
}


void ScalarConverter::printDouble(const std::string& literal)
{
    
}

void ScalarConverter::convert(const std::string& literal)
{
    std::cout << "literal: " << literal << std::endl;

    char* end = NULL;
    double d = strtod(literal.c_str(), &end);

    printChar(literal);
    printInt(literal);
    printFloat(literal);
    printDouble(literal);
}