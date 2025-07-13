#include "main.hpp"

void printStep(std::string msg) {
    std::cout << BLUE << "\n🔹 " << msg << RESET << std::endl;
}

int main()
{
    std::cout << YELLOW << "\n✨ Bem-vindo ao MateriaCraft - cpp04/ex03\n" << RESET;
    std::cout << CYAN << "🎓 Explorando Interfaces, Herança e Polimorfismo!\n" << RESET;

    // Interface IMateriaSource
    printStep("Interface 📚 IMateriaSource define a fábrica de magias.");
    IMateriaSource *biblioteca = new MateriaSource();
    biblioteca->learnMateria(new Ice());
    biblioteca->learnMateria(new Cure());
    biblioteca->learnMateria(new Tnt()); // Adiciona TNT à biblioteca

    // Interface ICharacter
    printStep("Interface 🧙 ICharacter define personagens mágicos.");
    ICharacter *steve = new Character("🎮 Steve");
    ICharacter *inimigo = new Character("👾 Creeper");

    printStep("Fábrica cria magias com clone de modelos:");
    AMateria *ice = biblioteca->createMateria("ice");
    AMateria *cure = biblioteca->createMateria("cure");
    AMateria *tnt = biblioteca->createMateria("tnt"); // Cria TNT

    printStep("Personagem equipa magias:");
    steve->equip(ice); // 0
    steve->equip(cure); // 1
    steve->equip(tnt); // 2
    
    steve->equip(biblioteca->createMateria("fire")); // Steve tenta equipar uma magia inexistente

    steve->equip(NULL); // Steve tenta equipar um null

    steve->equip(tnt->clone()); // 3 Steve equipa mais uma TNT
    steve->equip(tnt->clone()); // 3 Steve equipa mais uma TNT
    steve->equip(tnt->clone()); // 3 Steve equipa mais uma TNT
    steve->equip(tnt->clone()); // 3 Steve equipa mais uma TNT
    steve->equip(tnt->clone()); // 3 Steve equipa mais uma TNT
    steve->equip(tnt->clone()); // 3 Steve equipa mais uma TNT
    steve->equip(tnt->clone()); // 3 Steve equipa mais uma TNT
    steve->equip(tnt->clone()); // 3 Steve equipa mais uma TNT
    
    
    printStep("Magias são usadas via ponteiros e polimorfismo:");
    steve->use(0, *inimigo); // ice
    steve->use(1, *inimigo); // cure
    steve->use(2, *inimigo); 
    steve->use(3, *inimigo); 
    steve->use(4, *inimigo); 

    printStep("Desequipando magias:");
    steve->unequip(0); // Desequipa a magia do slot 0 (ice)
    steve->unequip(1); // Desequipa a magia do slot 1 (cure)
    steve->unequip(2); // Desequipa a magia do slot 2 (TNT)
    steve->unequip(3); // Desequipa a magia do slot 3 (TNT)

    printStep("Desmontando cenário com delete e destrutores:");
    delete inimigo;
    delete steve;
    delete biblioteca;

    std::cout << GREEN << "\n✅ Fim da apresentação. Nenhum leak se tudo correu bem!\n" << RESET;
    return 0;
}