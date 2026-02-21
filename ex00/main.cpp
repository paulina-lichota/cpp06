/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:32:18 by plichota          #+#    #+#             */
/*   Updated: 2026/02/21 20:10:06 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}

/*

> ./convert 0.0
char: Non displayable
int: 0
float: 0.0f
double: 0.0

> char
./convert a
char: 'a'
int: 97
float: 97.0f
double: 97.0

> char non rappresentabile (non displayable)
./convert as
char: impossible
int: impossible
float: impossible
double: impossible

> limite int compreso (stessa cosa per -2147483648)
./convert 2147483647
char: impossible
int: 2147483647
float: 2147483648.0f
double: 2147483647.0

> limite int (stessa cosa per -2147483649)
./convert 2147483647
char: impossible
int: impossible
float: impossible
double: impossible

> int generico
./convert 6325
char: impossible
int: 6325
float: 6325.0f
double: 6325.0

> non rappresentabile da float (±3.4e+38)
./convert 63259203242342340870890980986289707898903.3242343234
char: impossible
int: impossible
float: impossible
double: 63259203242342336133803798555905761476608.0

> perdita di precisione sia per float che per double
./convert 6325920324234234087089098098.3242343234
char: impossible
int: impossible
float: 6325920303641788416.0f
double: 6325920324234234880.0
*/