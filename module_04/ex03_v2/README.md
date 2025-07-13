
📚 MateriaSource → fábrica de magias
🧙‍♂️ Character		→ personagem que aprende e usa magias
✨ Ice / Cure	→ as magias concretas




       +-------------------+
       |   IMateriaSource  |
       +-------------------+
                ▲
                |
       +-------------------+
       |   MateriaSource   |
       +-------------------+
             |
             | learns
             v
       +--------------+
       |   AMateria   |<--------------+
       +--------------+               |
       ^             ^                |
    Ice           Cure         <- clone creates these
       \             /
        \           /
         v         v
     ICharacter (interface)
            ▲
            |
     +--------------+
     |  Character   |
     +--------------+
          |
          | equip/use
          v
      AMateria*
