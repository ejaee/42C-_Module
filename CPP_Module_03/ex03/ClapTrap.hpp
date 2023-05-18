#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# define RED    "\033[0;31m"
# define GREEN  "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE   "\033[0;34m"
# define RESET  "\033[0m"

# include <iostream>

class ClapTrap {
    protected:

        std::string		m_name;
        unsigned int	m_hitPoints;
        unsigned int	m_energyPoints;
        unsigned int	m_attackDamage;

    public:

		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& clapTrap);
		ClapTrap& operator=(const ClapTrap& clapTrap);
		virtual ~ClapTrap();

		std::string		getName() const;
		unsigned int	getHitPoints() const;
		unsigned int	getEnergyPoints() const;
		unsigned int	getAttackDamage() const;

		virtual void	attack(const std::string& target);
		void	takeDamage(unsigned int	amount);
		void	beRepaired(unsigned int	amount);
		
};

#endif
