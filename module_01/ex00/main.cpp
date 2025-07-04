#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int main()
{
	Zombie *z1 = newZombie("HeapZombie");
	z1->announce();
	delete z1; // destrói manualmente

	randomChump("StackZombie"); // destruído automaticamente

	return (0);
}
