/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:32:45 by ejachoi           #+#    #+#             */
/*   Updated: 2023/05/04 15:32:46 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {

    private:
        std::string m_name;
        Weapon* m_weapon;

    public:
        HumanB(std::string const name);
        ~HumanB();

        void    setWeapon(Weapon &weapon);
        void    attack() const;
};

#endif
