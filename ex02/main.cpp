/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 22:06:28 by plichota          #+#    #+#             */
/*   Updated: 2026/02/21 22:32:40 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib> // rand
#include <ctime> // time
#include <iostream>

int main ()
{
    std::srand(std::time(0)); // uso current time come seed per gen numeri diversi ad ogni esecuzione
    Base *p = generate();
    Base *q = generate();
    Base *r = generate();
    std::cout << "p: " << p << std::endl;
    std::cout << "q: " << q << std::endl;
    std::cout << "r: " << r << std::endl;
    delete p;
    delete q;
    delete r;
}