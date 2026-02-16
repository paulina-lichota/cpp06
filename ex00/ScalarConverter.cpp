/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:26:18 by plichota          #+#    #+#             */
/*   Updated: 2026/02/16 19:22:13 by plichota         ###   ########.fr       */
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

// ------------------------------ Check type ------------------------------ //

bool ScalarConverter::isChar(const std::string& literal)
{
    if (literal.empty())
        return false;
    if (literal.length() == 1 && !std::isdigit(literal[0])
            && std::isprint(literal[0]))
        return true;
    return false;
}

bool ScalarConverter::isInt(const std::string& literal)
{
    if (literal.empty())
        return false;
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
    // check overflow
    double val = strtod(literal.c_str(), NULL);
    double max = std::numeric_limits<double>::max();
    double min = std::numeric_limits<double>::min();
    if (val > max || val < min)
        return false;
    return true;
}

bool ScalarConverter::isFloat(const std::string& literal)
{
    if (literal.empty())
        return false;
    std::string temp = literal;
    // can start with + or -
    if (temp[0] != '+' || temp[0] != '-')
        temp = temp.substr(1);
    // contiene un punto
    size_t n = temp.find('.');
    if (n == std::string::npos)
        return false;
    if (!(std::isdigit(temp[n + 1]) || std::isdigit(temp[n - 1])))
        return false;
    // contiene f ed e' alla fine
    size_t f = temp.find('f');
    if (f == std::string::npos || temp[temp.length() - 1] != 'f')
        return false;
    // gli altri sono tutti numeri
    for (size_t i = 0; i < temp.length(); i++)
    {
        if (i == n || i == f)
            continue;
        else if (!std::isdigit(temp[i]))
            return false;
    }
    // c'e un numero prima o dopo il punto
    // if ()
    
    return true;
}

// non considero notazione scientifica
bool ScalarConverter::isDouble(const std::string& literal)
{
    if (literal.empty())
        return false;
    
    return true;
}

// ------------------------------ Print type ------------------------------ //

// void ScalarConverter::printChar(const std::string& literal)
// {
    
// }

// void ScalarConverter::printInt(const std::string& literal)
// {
    
// }

// void ScalarConverter::printFloat(const std::string& literal)
// {
    
// }


// void ScalarConverter::printDouble(const std::string& literal)
// {
    
// }

// ------------------------------ Convert ------------------------------ //

void ScalarConverter::convert(const std::string& literal)
{
    std::cout << "isChar: " << isChar(literal) << std::endl;
    std::cout << "isInt: " << isInt(literal) << std::endl;
    std::cout << "isFloat: " << isFloat(literal) << std::endl;
    std::cout << "isDouble: " << isDouble(literal) << std::endl;
    
    // printChar(literal);
    // printInt(literal);
    // printFloat(literal);
    // printDouble(literal);
}