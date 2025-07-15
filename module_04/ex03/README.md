📚 MateriaSource → magic factory
🧙‍♂️ Character     → character who learns and uses magic
✨ Ice / Cure    → the concrete spells


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
       |   AMateria   |<----------------+
       +--------------+                 |
       ^              ^                  |
     Ice             Cure     <- clone creates these
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
