/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:26:18 by plichota          #+#    #+#             */
/*   Updated: 2026/02/21 20:18:36 by plichota         ###   ########.fr       */
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


// to do gestire "'0'" e "0" ?
// prende solo valori ASCII
bool ScalarConverter::isChar(const std::string& literal)
{
    if (literal.length() != 1)
        return false;
    if (literal[0] < 0 || literal[0] > 127)
        return false;
    if (!std::isprint(literal[0]))
        return false;
    return true;
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
    
    if (literal == "nanf" || literal == "+inff" || literal == "-inff" || literal == "inff")
        return true;
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
    float fl = static_cast<float>(val);
    double back = static_cast<double>(fl);

    // Il cast a float restituisce:
    // Valori troppo grandi → +inf
    // Valori troppo piccoli → -inf
    // Valori non validi → nan
    if (std::isinf(val) || std::isnan(val))
        return false; 
    // 3.4028235×10^38 massimo valore rappresentabile da float con meno precisione
    // 16.777.216 (2^24) valore massimo intero rappresentabile senza perdere precisione
    if (val > std::numeric_limits<float>::max() || val < -std::numeric_limits<float>::max())
        return false;
    if (std::isinf(fl) || std::isnan(fl))
        return false;
    // Per interi grandi, controlla se val è intero e se val == back
    if (std::floor(val) == val && val != back)
        return false;
    // controllo precisione persa
    double tolerance = std::pow(10, -std::numeric_limits<float>::digits10);
    if (std::fabs(val - back) > tolerance * std::fabs(val))
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
    if (literal == "nan" || literal == "+inf" || literal == "-inf" || literal == "inf")
        return true;
    if (temp[0] == '+' || temp[0] == '-')
        temp = temp.substr(1);
    // contiene un punto
    size_t n = temp.find('.');
    if (n == std::string::npos)
        return false;
    // gli altri sono tutti numeri
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
    char a = static_cast<char>(literal[0]);
    std::cout << "char: '" << a << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(a) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(a) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(a) << std::endl;
}

void ScalarConverter::printInt(const std::string& literal)
{
    long a = static_cast<int>(strtol(literal.c_str(), NULL , 10));
    
    if (a >= 0 && a <= 127)
    {
        if (std::isprint(a)) 
            std::cout << "char: '" << static_cast<char>(a) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else 
        std::cout << "char: impossible" << std::endl;
    std::cout << "int: " << a << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(a) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(a) << std::endl;
}

// il cast a float tronca il valore e converte a char, se va in overflow fa il wrap-around
void ScalarConverter::printFloat(const std::string& literal)
{
    if (literal == "nanf" || literal == "+inff" || literal == "-inff" || literal == "inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << std::endl;
        std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
        return;
    }
    float a = static_cast<float>(strtod(literal.c_str(), NULL));
    char c = static_cast<char>(a);
    if (a < 0 || a > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(a))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
    if (std::isnan(a) || std::isinf(a) ||
        a < static_cast<double>(std::numeric_limits<int>::min()) ||
        a > static_cast<double>(std::numeric_limits<int>::max()))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(a) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << a << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(a) << std::endl;
}

void ScalarConverter::printDouble(const std::string& literal)
{
    if (literal == "nan" || literal == "+inf" || literal == "-inf" || literal == "inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << "f" << std::endl;
        std::cout << "double: " << literal << std::endl;
        return;
    }
    double a = static_cast<double>(strtod(literal.c_str(), NULL));
    char c = static_cast<char>(a);
    if (a < 0 || a > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(a))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
    if (std::fabs(a) > std::numeric_limits<int>::max()
        || std::fabs(a) < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(a) << std::endl;
    if (std::fabs(a) > std::numeric_limits<float>::max()
        || (std::fabs(a) < std::numeric_limits<float>::min() && a != 0))
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(a) << "f" << std::endl;
    // Il tipo double ha circa 15-17 cifre decimali significative
    std::cout << "double: " << std::fixed << std::setprecision(1) << a << std::endl;
}

// ------------------------------ Get type ------------------------------ //

int ScalarConverter::getType(const std::string& literal)
{
    if (isInt(literal)) // metto prima int perche' alcuni caratteri sono anche numeri, es '0' e '1'
        return 0;
    if (isChar(literal))
        return 1;
    else if (isFloat(literal))
        return 2;
    else if (isDouble(literal))
        return 3;
    else
        return -1;
}

// ------------------------------ Convert ------------------------------ //

void ScalarConverter::convert(const std::string& literal)
{
    int type = getType(literal);
    // std::cout << "type: " << type << std::endl;

    void (*print[]) (const std::string&) =
    {
        printInt,
        printChar,
        printFloat,
        printDouble
    };

    if (type == -1)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    else
        print[type](literal);
    // es 2.3d, nan
    // se non e' nessuno dei 4 tipi, stampo "impossible" E RISPETTIVI PER TIPO
    
    // -inf , impossible char e int, controllo limiti per float e double -inff per float, DIPENDE per double se supera limite
}