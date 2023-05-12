/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <choiejae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:32:26 by ejachoi           #+#    #+#             */
/*   Updated: 2023/05/12 11:27:09 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# define RED    "\033[0;31m"
# define GREEN  "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE   "\033[0;34m"
# define RESET  "\033[0m"

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
