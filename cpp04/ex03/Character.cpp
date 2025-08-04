#include "Character.hpp"

Character::Character(std::string const & name) : _name(name), _floorIndex(0)
{
	for (int i = 0; i < 4 ; ++i)
		_inventory[i] = NULL;
	for (int i = 0; i < 100; ++i)
		_floor[i] = NULL;
}

Character::~Character()
{
	clearInventory();
	for(int i = 0; i < _floorIndex; ++i)
		delete _floor[i];
}

Character::Character (const Character& other)
{
	*this = other;
}

Character& Character::operator=(const Character& other)
{
	if(this != &other)
	{
		_name = other._name;
		clearInventory();
		copyInventory(other);
	}
	return *this;
}

void Character::clearInventory()
{
	for (int i = 0; i < 4; ++i)
	{
		delete _inventory[i];
		_inventory[i] = NULL;
	}
}

void Character::copyInventory(const Character& other)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

std::string const &Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	if(!m)
		return;
	for (int i = 0; i < 4; ++i)
	{
		if(!_inventory[i])
		{
			_inventory[i] = m;
			std::cout << _name << " equipped a " << m->getType() << " materia." << std::endl;
			return;
		}
	}
	std::cout << "Inventory full! Cannot equip this " << m->getType() << " materia." << std::endl;
}

void Character::unequip(int idx)
{
	if(!_inventory[idx])
	{
		std::cout << "No materia equipped at index " << idx << "." << std::endl;
		return;
	}
	else if (idx < 0 || idx >= 4)
	{
		std::cout << "Invalid index, it must be between 0 and 3." << std::endl;
		return;
	}
	if (_floorIndex < 100)
	{
		_floor[_floorIndex++] = _inventory[idx];
		std::cout << _name << " unequipped materia from index " << idx << "." << std::endl;
	}
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Invalid index, it must be between 0 and 3." << std::endl;
		return;
	}
	else if(!_inventory[idx])
	{
		std::cout << "No materia equipped at index " << idx << "." << std::endl;
		return;
	}
	_inventory[idx]->use(target);
}
