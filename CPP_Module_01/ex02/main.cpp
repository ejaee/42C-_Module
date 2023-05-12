/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <choiejae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:32:33 by ejachoi           #+#    #+#             */
/*   Updated: 2023/05/12 11:43:49 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define RED    "\033[0;31m"
# define GREEN  "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE   "\033[0;34m"
# define RESET  "\033[0m"

#include <iostream>

int main(){
    std::string stringVAL = "HI THIS IS BRAIN";
    std::string* stringPTR = &stringVAL;
    std::string& stringREF = stringVAL;

    std::cout << std::endl << "Print the address of" << std::endl;

    std::cout << GREEN << "stringVAL: " << RESET << &stringVAL << std::endl;
    std::cout << YELLOW << "stringPTR: " << RESET << stringPTR << std::endl;
    std::cout << RED << "stringREF: " << RESET << &stringREF << std::endl;


    std::cout << std::endl << "Print the value of" << std::endl;
    
    std::cout << GREEN << "stringVAL: " << RESET << stringVAL << std::endl;
    std::cout << YELLOW << "stringPTR: " << RESET << *stringPTR << std::endl;
    std::cout << RED << "stringREF: " << RESET << stringREF << std::endl;

    return 0;
}
