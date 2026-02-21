/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 22:04:15 by plichota          #+#    #+#             */
/*   Updated: 2026/02/21 22:23:02 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class Base
{
    public:
        virtual ~Base() {};
};

Base *generate(void);
// It randomly instantiates A, B, or C and returns the instance as a Base pointer.

void identify(Base* p);
// It prints the actual type of the object pointed to by p: "A", "B", or "C".
void identify(Base& p);
// It prints the actual type of the ob
#endif