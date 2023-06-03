#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(const std::string newName);
	ScavTrap(const ScavTrap &other);
	~ScavTrap();

	ScavTrap &operator=(ScavTrap &other);

	void attack(const std::string &target);
	void guardGate();
};
