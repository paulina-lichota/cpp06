/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 20:21:22 by plichota          #+#    #+#             */
/*   Updated: 2026/02/21 21:59:25 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "data.hpp"

int main()
{
    // {
    //     // error (not instantiable)
    //     Serializer();
    // }

    // Data *data_ptr = new Data;
    // if (data_ptr == NULL)
    // {
    //     std::cout << "Allocation failed!" << std::endl;
    //     return 1;
    // }
    Data *data_ptr = NULL;
    try {
        data_ptr = new Data;
        // throw std::bad_alloc(); // test exception
    } catch (std::bad_alloc& e) {
        std::cout << MAGENTA << "Allocation failed: " << e.what() << RESET << std::endl;
        return 1;
    }

    data_ptr->i = 1;
    data_ptr->text = "ciao";

    std::cout << "Ptr address: " << &data_ptr << std::endl;
    std::cout << "Data address: " << data_ptr << std::endl;
    std::cout << "Data int: " << data_ptr->i << std::endl;
    std::cout << "Data text: " << data_ptr->text << std::endl;

    // Use serialize() on the address of the Data object
    uintptr_t ptr_ser = Serializer::serialize(data_ptr);
    std::cout << GREEN << "Serialized address: " << ptr_ser << RESET << std::endl;

    // pass its return value to deserialize().
    // Then, ensure the return value of deserialize() compares equal to the
    // original pointer.
    Data *new_data_ptr = Serializer::deserialize(ptr_ser);
    if (new_data_ptr == NULL)
    {
        std::cout << MAGENTA << "Deserialization failed!" << RESET << std::endl;
        return 1;
    }
    std::cout << "Ptr address: " << &new_data_ptr << std::endl;
    std::cout << "NewData address: " << new_data_ptr << std::endl;
    std::cout << "NewData int: " << new_data_ptr->i << std::endl;
    std::cout << "NewData text: " << new_data_ptr->text << std::endl;

    if (new_data_ptr != data_ptr) {
       std::cout << MAGENTA << "Pointer mismatch!" << RESET << std::endl;
    }
    else
    {
        std::cout << GREEN << "Serialization/Deserialization successful!" << RESET << std::endl;
    }
    delete data_ptr;
}