#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
public:
    Zombie();
    ~Zombie();

    void setName(std::string name);
    void announce() const;

private:
    std::string _name;
};

#endif
