#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		_templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for(int i = 0; i < 4; ++i)
	{
		if(other._templates[i])
			_templates[i] = other._templates[i]->clone();
		else
			_templates[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; ++i)
		{
			delete _templates[i];
			if(other._templates[i])
				_templates[i] = other._templates[i]->clone();
			else
				_templates[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for(int i = 0; i < 4; ++i)
	{
		delete _templates[i];
		_templates[i] = NULL;
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	if(!m)
		return;
	for(int i = 0; i < 4; ++i)
	{
		if(!_templates[i])
		{
			_templates[i] = m->clone();
			std::cout << "Materia learned: " << m->getType() << std::endl;
			return ;
		}
	}
	std::cout << "MateriaSource is full, cannot learn more materia!" << std::endl;
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; ++i)
		if(_templates[i] && _templates[i]->getType() == type)
		{
			std::cout << "Creating materia: " << type << std::endl;
			return _templates[i]->clone();
		}
	std::cout << "Materia of type " << type << " unknown!" << std::endl;
	return NULL;
}
