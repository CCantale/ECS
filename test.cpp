#include <iostream>
#include "EntityManager.hpp"
#include "ComponentArray.hpp"
#include "Speed.hpp"
#include "Name.hpp"

int	main(void)
{
	EntityManager::init();

	Entity bob = EntityManager::newID();
	if (bob != NULL_ENTITY)
		std::cout << "Bob created." << std::endl;
	Entity carl = EntityManager::newID();
	if (carl != NULL_ENTITY)
		std::cout << "Carl created." << std::endl;

	ComponentArray<Speed>	speedArray;
	Speed			speed;

	std::cout << "Component and array created (Speed)." << std::endl;
	speed.owner = carl;
	speed.signature = 1;
	speed.speed = 300;
	std::cout << "Component setup done (Speed)." << std::endl;

	speedArray.insert(speed);
	EntityManager::setSignature(carl, 3);
	std::cout << "Component inserted" << std::endl;

	std::cout << "Carl's speed = " << speedArray.getData(carl)->speed << std::endl;


	ComponentArray<Name>	nameArray;
	Name			name;

	std::cout << "Component and array created (Name)." << std::endl;
	name.owner = carl;
	name.signature = 2;
	name.name = "Carl";
	std::cout << "Component setup done (Name)." << std::endl;
	nameArray.insert(name);
	std::cout << "Name inserted" << std::endl;


	std::cout << "Speed check:" << std::endl;
	speedArray.check();
	std::cout << "Name check:" << std::endl;
	nameArray.check();

	std::cout << "Carl's name = " << nameArray.getData(carl)->name << std::endl;

	speedArray.erase(carl);
	if (speedArray.getData(carl))
		std::cout << "Carl's speed = " << speedArray.getData(carl)->speed << std::endl;
	else
		std::cout << "Component erased." << std::endl;
/*
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
*/
	return (0);
}
