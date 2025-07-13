#ifndef TNT_HPP
#define TNT_HPP

#include "AMateria.hpp"

class Tnt : public AMateria
{
    public:
        Tnt();
        Tnt(const Tnt &other);
        Tnt &operator=(const Tnt &other);
        ~Tnt();

        AMateria	*clone() const;
        void		use(ICharacter &target);
};

#endif
