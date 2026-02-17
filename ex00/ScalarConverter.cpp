/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:26:18 by plichota          #+#    #+#             */
/*   Updated: 2026/02/17 19:32:49 by plichota         ###   ########.fr       */
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
    long val = strtol(literal.c_str(), NULL , 10);
    long max = std::numeric_limits<int>::max();
    long min = std::numeric_limits<int>::min();
    if (val > max || val < min)
        return false;
    return true;
}

// -inff, +inff, nanf
bool ScalarConverter::isFloat(const std::string& literal)
{
    if (literal.empty())
        return false;
    std::string temp = literal;

    // can start with + or -
    if (temp[0] == '+' || temp[0] == '-')
        temp = temp.substr(1);

    // contiene un digit
    bool hasDigit = false;
    size_t i = 0;
    while (i < temp.length())
    {
        if (std::isdigit(temp[i]))
        {
            hasDigit = true;
            break;
        }
        i++;
    }
    if (!hasDigit)
        return false;
    
    // termina con f
    size_t f = temp.find('f');
    if (f == std::string::npos || temp[temp.length() - 1] != 'f')
        return false;    
    
    // // contiene un punto
    size_t n = temp.find('.');
    if (n == std::string::npos)
        n = -1;

    // // gli altri sono tutti numeri
    for (size_t j = 0; j < temp.length(); j++)
    {
        if (j == n || j == f)
            continue;
        else if (!std::isdigit(temp[j]))
            return false;
    }
    
    // check overflow - min e' il valore positivo normalizzato piu' piccolo, non il valore negativo
    // ovvero il valore piu' piccolo rappresentabile senza perdere precisione
    double val = strtod(literal.c_str(), NULL);
    double max = std::numeric_limits<float>::max();
    double min = -std::numeric_limits<float>::max();

    if (val > max || val < min)
        return false;
    return true;
}

// -inf, +inf, nan
// non considero notazione scientifica
bool ScalarConverter::isDouble(const std::string& literal)
{
    if (literal.empty())
        return false;
    std::string temp = literal;
    if (temp[0] == '+' || temp[0] == '-')
        temp = temp.substr(1);
    // // contiene un punto
    size_t n = temp.find('.');
    if (n == std::string::npos)
        return false;
    // // gli altri sono tutti numeri
    for (size_t j = 0; j < temp.length(); j++)
    {
        if (j == n)
            continue;
        else if (!std::isdigit(temp[j]))
            return false;
    }
    return true;
}

// ------------------------------ Print type ------------------------------ //

void ScalarConverter::printChar(const std::string& literal)
{
    if (!isChar(literal))
    {
        std::cout << "char: impossible" << std::endl;
        return;
    } else 
    {
        char a = static_cast<char>(literal[0]);
        std::cout << "char: " << a << std::endl;
    }
}

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
    // std::cout << "isChar: " << isChar(literal) << std::endl;
    std::cout << "isInt: " << isInt(literal) << std::endl;
    std::cout << "isFloat: " << isFloat(literal) << std::endl;
    std::cout << "isDouble: " << isDouble(literal) << std::endl;
    
    // es 2.3d, nan
    // se non e' nessuno dei 4 tipi, stampo "impossible" E RISPETTIVI PER TIPO
    
    // -inf , impossible char e int, controllo limiti per float e double -inff per float, DIPENDE per double se supera limite

    printChar(literal);
    // printInt(literal);
    // printFloat(literal);
    // printDouble(literal);
}