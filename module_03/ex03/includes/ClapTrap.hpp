#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		virtual ~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void	setName(const std::string& name);
		void	setHitPoints(unsigned int hp);
		void	setEnergyPoints(unsigned int ep);
		void	setAttackDamage(unsigned int ad);
		
		const std::string&	getName() const;
		unsigned int		getHitPoints()   const;
		unsigned int		getEnergyPoints() const;
		unsigned int		getAttackDamage() const;
	
	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
};

#endif
