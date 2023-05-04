/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:32:33 by ejachoi           #+#    #+#             */
/*   Updated: 2023/05/04 15:32:35 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(){
    std::string stringVAL = "HI THIS IS BRAIN";
    std::string* stringPTR = &stringVAL;
    std::string& stringREF = stringVAL;

    std::cout << std::endl << "Print the address of" << std::endl;

    std::cout << "stringVAL: " << &stringVAL << std::endl;
    std::cout << "stringPTR: " << stringPTR << std::endl;
    std::cout << "stringREF: " << &stringREF << std::endl;


    std::cout << std::endl << "Print the value of" << std::endl;
    
    std::cout << "stringVAL: " << stringVAL << std::endl;
    std::cout << "stringPTR: " << *stringPTR << std::endl;
    std::cout << "stringREF: " << stringREF << std::endl;

    return 0;
}
