#include "EntityManager.hpp"

std::queue<Entity>			EntityManager::_availableEntities;
std::array<Signature, MAX_COMPONENTS>	EntityManager::_signatures;
int					EntityManager::_livingEntities = 0;

void	EntityManager::init(void)
{
	for (Entity id = 0; id < MAX_ENTITIES; ++id)
	{
		_availableEntities.push(id);
	}
}

Entity	EntityManager::newID(void)
{
	Entity	ID;

	if (_availableEntities.empty())
	{
		std::cerr << "Error: EntityManager::newEntity(): Too many entities, cannot make more." << std::endl;
		return (NULL_ENTITY);
	}
	ID = _availableEntities.front();
	_livingEntities += 1;
	_availableEntities.pop();
	return (ID);
}

void	EntityManager::deleteID(Entity entity)
{
	if (entity == NULL_ENTITY)
		return ;
	_signatures[entity].reset();
	_availableEntities.push(entity);
	_livingEntities -= 1;
}

void	EntityManager::setSignature(Entity entity, Signature signature)
{
	if (entity == NULL_ENTITY)
		return ;
	_signatures[entity] = signature;
}

Signature const	EntityManager::getSignature(Entity entity)
{
	if (entity == NULL_ENTITY)
	{
		std::cerr << "Error: EntityManager::getSignature: null entity." << std::endl;
		return (0);
	}
	return (_signatures[entity]);
}

int EntityManager::getLivingEntities(void)
{
	return (_livingEntities);
}
