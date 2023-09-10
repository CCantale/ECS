#include <iostream>
#include "EntityManager.hpp"

int	main(void)
{
	EntityManager::init();

	Entity bob = EntityManager::newID();
	if (bob != NULL_ENTITY)
		std::cout << "Bob created." << std::endl;
	Entity carl = EntityManager::newID();
	if (carl != NULL_ENTITY)
		std::cout << "Carl created." << std::endl;

	std::cout << "Entities nbr = " << EntityManager::getLivingEntities() << std::endl;
	std::cout << "Bob = " << bob << std::endl;
	std::cout << "Carl = " << carl << std::endl;

	EntityManager::setSignature(bob, 42);
	std::cout << "Bob's signature = " << EntityManager::getSignature(bob) << std::endl;
	std::cout << "Carl's signature = " << EntityManager::getSignature(carl) << std::endl;

	std::cout << "Deleting bob..." << std::endl;
	EntityManager::deleteID(bob);
	std::cout << "Entities nbr = " << EntityManager::getLivingEntities() << std::endl;

	std::cout << "Deleting carl..." << std::endl;
	EntityManager::deleteID(carl);
	std::cout << "Entities nbr = " << EntityManager::getLivingEntities() << std::endl;

	Entity	steve = EntityManager::newID();
	if (steve != NULL_ENTITY)
		std::cout << "Steve created." << std::endl;
	std::cout << "Entities nbr = " << EntityManager::getLivingEntities() << std::endl;
	std::cout << "Steve = " << steve << std::endl;

	std::cout << "Deleting Steve..." << std::endl;
	EntityManager::deleteID(steve);
	std::cout << "Entities nbr = " << EntityManager::getLivingEntities() << std::endl;

	return (0);
}
