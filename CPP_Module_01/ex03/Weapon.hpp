/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:32:54 by ejachoi           #+#    #+#             */
/*   Updated: 2023/05/04 15:32:56 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

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
