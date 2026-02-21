/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 22:11:15 by plichota          #+#    #+#             */
/*   Updated: 2026/02/21 22:23:05 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
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