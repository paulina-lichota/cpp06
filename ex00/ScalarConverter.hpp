/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:24:06 by plichota          #+#    #+#             */
/*   Updated: 2026/02/18 12:44:39 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <limits> // std::numeric_limits<double>::max();
#include <cmath> // isinf, isnan
// #include <cctype> // isprint
#include <iomanip> // std::fixed, std::setprecision

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();

        // helpers
        // statici perche' convert static puo' accedere solo ad altre static
        // cosi' posso accedere tramite ScalarConverter::method() e non istanziare
        static bool isChar(const std::string& literal);
        static bool isInt(const std::string& literal);
        static bool isFloat(const std::string& literal);
        static bool isDouble(const std::string& literal);

        static void printChar(const std::string& literal);
        static void printInt(const std::string& literal);
        static void printFloat(const std::string& literal);
        static void printDouble(const std::string& literal);

        static int getType(const std::string& literal);
    public:
        static void convert(const std::string& literal);
};

#endif