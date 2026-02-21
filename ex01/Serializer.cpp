/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 20:21:55 by plichota          #+#    #+#             */
/*   Updated: 2026/02/21 21:37:14 by plichota         ###   ########.fr       */
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

// reinterpret_cast converte solo un tipo in un altro
// reinterpreta bit senza modificarli
uintptr_t Serializer::serialize(Data* ptr)
{
    if (ptr == NULL)
    {
        std::cout << "invalid ptr" << std::endl;
        return (uintptr_t)-1;
    }
    // salviamo l'indirizzo come un intero
    uintptr_t p = reinterpret_cast<uintptr_t>(ptr);
    // std::cout << ptr << std::endl;
    // std::cout << p << std::endl;
    return p;
}

Data* Serializer::deserialize(uintptr_t raw)
{
    if (raw == 0 || raw == (uintptr_t)-1)
    {
        std::cout << "invalid raw" << std::endl;
        return (NULL);
    }
    Data *p = reinterpret_cast<Data*>(raw);
    // std::cout << raw << std::endl;
    // std::cout << p << std::endl;
    return p;
}