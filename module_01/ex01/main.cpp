#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main() {
	int num = 5;
	Zombie* horde = zombieHorde(num, "Walker");

	for (int i = 0; i < num; ++i)
		horde[i].announce();

	delete[] horde;
	return (0);
}
