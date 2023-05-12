/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:33:16 by ejachoi           #+#    #+#             */
/*   Updated: 2023/05/12 16:05:31 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# define RED    "\033[0;31m"
# define GREEN  "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE   "\033[0;34m"
# define RESET  "\033[0m"

# include <iostream>

class Harl {

    private:
        std::string m_level[4];
        void    (Harl::*m_funcPointer[4])(void);

        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);

    public:
        Harl();
        ~Harl();
        void    complain(std::string level);

};

#endif
