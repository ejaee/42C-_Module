/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:32:40 by ejachoi           #+#    #+#             */
/*   Updated: 2023/05/04 15:32:41 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

#include "Weapon.hpp"

class HumanA {

    private:
        std::string m_name;
        Weapon& m_weapon;

    public:
        HumanA();
        HumanA(std::string const name, Weapon &weapon);
        ~HumanA();

        void    attack() const;
};

#endif
