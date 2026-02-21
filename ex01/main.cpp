/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 20:21:22 by plichota          #+#    #+#             */
/*   Updated: 2026/02/21 20:46:19 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "data.hpp"

int main()
{
    // {
    //     // error not instantiable
    //     Serializer();
    // }
    Data *data_ptr = new Data;
    data_ptr->i = 1;
    data_ptr->text = "ciao";

    std::cout << "Data address" << &data_ptr << std::endl;
    std::cout << "Data int: " << data_ptr->i << std::endl;
    std::cout << "Data text: " << data_ptr->text << std::endl;


    // Use serialize() on the address of the Data object
    uintptr_t ptr_ser = Serializer::serialize(data_ptr);
    std::cout << ptr_ser << std::endl;
    
    // pass its return value to deserialize().
    // Then, ensure the return value of deserialize() compares equal to the
    // original pointer.
    Data *new_data_ptr = Serializer::deserialize(ptr_ser);
    std::cout << "NewData address" << &new_data_ptr << std::endl;
    std::cout << "NewData int: " << new_data_ptr->i << std::endl;
    std::cout << "NewData text: " << new_data_ptr->text << std::endl;
}