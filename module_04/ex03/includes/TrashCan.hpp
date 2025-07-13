#ifndef TRASHCAN_HPP
#define TRASHCAN_HPP

#include "AMateria.hpp"
#include "constants.hpp"

class TrashCan
{
	public:
		TrashCan();
		TrashCan(const TrashCan &other);
		TrashCan &operator=(const TrashCan &other);
		~TrashCan();

		bool store(AMateria *m);
		void clear();

	private:
		AMateria	*_items[MAX_TRASH];
		int			_count;
};

#endif
