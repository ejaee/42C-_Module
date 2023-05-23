#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
    private:
        AMateria* m_slot[AMA_SIZE];

    public:
        MateriaSource();
        MateriaSource(const MateriaSource& ms);
        MateriaSource& operator=(const MateriaSource& ms);
        ~MateriaSource();

        const AMateria*   getAMateria(const int idx) const;

        void    learnMateria(AMateria* m);
        AMateria*   createMateria(const std::string& type);

        
};

# endif