/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileDto.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:33:01 by ejachoi           #+#    #+#             */
/*   Updated: 2023/05/04 15:33:02 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEDTO_HPP
# define FILEDTO_HPP

#include <iostream>
#include <fstream>

class FileDto {

    private:
        std::ifstream	m_fin;
        std::ofstream	m_fout;

    public:
        FileDto();
        FileDto(const std::string	fileName);
        ~FileDto();

        std::ifstream&	getFin();
        std::ofstream&	getFout();
        
        void	replaceString(std::string buf, const std::string& s1, const std::string& s2);
};

#endif
