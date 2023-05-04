/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:32:26 by ejachoi           #+#    #+#             */
/*   Updated: 2023/05/04 15:32:27 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie{
    private:
        std::string m_name;

    public:
        Zombie();
        ~Zombie();

        void    setName(std::string name);
        void    announce();
};

Zombie* zombieHorde(int N, std::string name);

#endif
