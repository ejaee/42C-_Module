/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <choiejae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:32:54 by ejachoi           #+#    #+#             */
/*   Updated: 2023/05/12 11:44:44 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# define RED    "\033[0;31m"
# define GREEN  "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE   "\033[0;34m"
# define RESET  "\033[0m"

# include <iostream>

class Weapon {

    private:
        std::string m_type;

    public:
        Weapon();
        Weapon(std::string const type);
        ~Weapon();

        const std::string &getType() const;
        void        setType(std::string const type);

};

#endif
