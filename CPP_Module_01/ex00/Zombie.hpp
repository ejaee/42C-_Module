/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:32:17 by ejachoi           #+#    #+#             */
/*   Updated: 2023/05/04 15:32:19 by ejachoi          ###   ########.fr       */
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
        Zombie(std::string name);
        ~Zombie();

        void    announce();
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

#endif
