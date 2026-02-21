/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 22:11:15 by plichota          #+#    #+#             */
/*   Updated: 2026/02/21 22:49:59 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib> // rand
#include <ctime> // time

// puntatori a funzione
typedef Base* (*create)();

Base *createA() { return new A; }
Base *createB() { return new B; }
Base *createC() { return new C; }

Base *generate(void)
{
    create c[3] = { createA, createB, createC };
    int r = std::rand() % 3;
    Base *p = c[r]();
    return p;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "unknown type" << std::endl;
}

// dynamic cast non restituisce null con le reference come coi puntatori
// ma lancia exception std::bad_cast
void identify(Base& p)
{
    try
    {
        (void) dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch(...) {}

    try
    {
        (void) dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch(...) {}

    try
    {
        (void) dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch(...) {}
    
    std::cout << "unknown type" << std::endl;
}