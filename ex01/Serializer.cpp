/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 20:21:55 by plichota          #+#    #+#             */
/*   Updated: 2026/02/21 20:35:08 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {};
Serializer::Serializer(const Serializer &other)
{
    (void) other;
    return;
}
Serializer &Serializer::operator=(const Serializer &other)
{
    (void) other;
    return *this;
}
Serializer::~Serializer() {};
