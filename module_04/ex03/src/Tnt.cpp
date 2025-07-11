#include "Tnt.hpp"
#include "ICharacter.hpp"
#include <iostream>

Tnt::Tnt() : AMateria("tnt") {}

Tnt::Tnt(const Tnt &other) : AMateria(other) {}

Tnt &Tnt::operator=(const Tnt &other)
{
    AMateria::operator=(other);
    return (*this);
}

Tnt::~Tnt() {}

AMateria *Tnt::clone() const
{
    return (new Tnt(*this));
}

void Tnt::use(ICharacter &target)
{
    std::cout << "* throws TNT at " << target.getName() << " and it explodes! 💥 *" << std::endl;
}
