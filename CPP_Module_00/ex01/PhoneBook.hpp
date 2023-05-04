/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:30:12 by ejachoi           #+#    #+#             */
/*   Updated: 2023/05/04 15:30:14 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define MAX_STORAGE_SPACE 8

# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.hpp"

class PhoneBook{
    private:
    Contact contact[8];
    int index;

    Contact createContact();
    void    displaySubstrInfo(std::string info);
    void    displaySelectedValue();
    void    validateSelectedValue(std::string indexString);

    public:
    PhoneBook();
    ~PhoneBook();

    void addContact();
    void displayAllValues();
};

#endif
