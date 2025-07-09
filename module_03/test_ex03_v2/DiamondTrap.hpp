#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

// Estrutura global para capturar valores das classes base
struct DiamondTrapValues {
	int fragTrapHP;
	int scavTrapEP;
	int fragTrapAD;
	
	DiamondTrapValues() : fragTrapHP(0), scavTrapEP(0), fragTrapAD(0) {}
};

// Instância global para capturar valores
extern DiamondTrapValues g_diamondValues;

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
	DiamondTrap();
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& other);
	DiamondTrap& operator=(const DiamondTrap& other);
	~DiamondTrap();
	
	// o attack “normal” de ScavTrap:
	void attack(const std::string& target);
	
	// forwarding para resolver ambiguidade:
	// void takeDamage(unsigned int amount);
	// void beRepaired(unsigned int amount);
	
	void whoAmI();

	private:
		std::string _name;
};

#endif
