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
	speed._owner = carl;
	speed._signature = 1;
	speed.speed = 300;
	std::cout << "Component setup done (Speed)." << std::endl;

	speedArray.insert(speed);
	EntityManager::setSignature(carl, 3);
	EntityManager::setSignature(bob, 3);
	std::cout << "Component inserted" << std::endl;

	std::cout << "Carl's speed = " << speedArray.getData(carl)->speed << std::endl;


	ComponentArray<Name>	nameArray;
	Name			name;

	std::cout << "Component and array created (Name)." << std::endl;
	name._owner = carl;
	name._signature = 2;
	name.name = "Carl";
	std::cout << "Component setup done (Name)." << std::endl;
	nameArray.insert(name);
	std::cout << "Name inserted" << std::endl;


	std::cout << "Speed check:" << std::endl;
	speedArray.check();
	std::cout << "Name check:" << std::endl;
	nameArray.check();

	std::cout << "Carl's name = " << nameArray.getData(carl)->name << std::endl;



	Name	bobName;

	bobName._owner = bob;
	bobName._signature = 2;
	bobName.name = "Bob";
	nameArray.insert(bobName);
	std::cout << "Bob's name inserted" << std::endl;
	std::cout << "Name check:" << std::endl;
	nameArray.check();
	std::cout << "Bob's name = " << nameArray.getData(bob)->name << std::endl;


	nameArray.check();
	speedArray.erase(carl);
	EntityManager::setSignature(carl, 2);
	if (speedArray.getData(carl))
		std::cout << "Carl's speed = " << speedArray.getData(carl)->speed << std::endl;
	else
		std::cout << "Component Speed erased." << std::endl;
	nameArray.erase(carl);
	EntityManager::setSignature(carl, 0);
	if (nameArray.getData(carl))
		std::cout << "Carl's name = " << nameArray.getData(carl)->name << std::endl;
	else
		std::cout << "Component Name erased." << std::endl;

	std::cout << "Name check:" << std::endl;
	nameArray.check();
	Name	aName;
	Name	bName;
	Name	cName;
	Name	sName;
	Entity steve = EntityManager::newID();
	if (carl != NULL_ENTITY)
		std::cout << "Carl created." << std::endl;

	aName._owner = bob;
	aName._signature = 2;
	aName.name = "Lal";
	bName._owner = carl;
	bName._signature = 2;
	bName.name = "Laaal";
	cName._owner = carl;
	cName._signature = 2;
	cName.name = "Lal";
	sName._owner = steve;
	sName._signature = 2;
	sName.name = "Weeee";
	EntityManager::setSignature(carl, 2);
	EntityManager::setSignature(steve, 2);
	
	nameArray.insert(aName);
	nameArray.insert(bName);
	nameArray.insert(cName);
	nameArray.insert(sName);
	std::cout << "Bob's name = " << nameArray.getData(bob)->name << std::endl;
	std::cout << "Carl's name = " << nameArray.getData(carl)->name << std::endl;
	std::cout << "Name check:" << std::endl;
	nameArray.check();
	nameArray.erase(carl);
	std::cout << "Name check:" << std::endl;
	nameArray.check();
	nameArray.insert(bName);
	std::cout << "Name check:" << std::endl;
	nameArray.check();
	nameArray.erase(carl);
	nameArray.erase(bob);
	std::cout << "DA QUI >" << std::endl;
	nameArray.insert(aName);
	nameArray.insert(bName);
	nameArray.insert(cName);
	nameArray.insert(sName);
	std::cout << "Name check:" << std::endl;
	nameArray.check();
	nameArray.erase(carl);
	std::cout << "CARL" << std::endl;
	Entity	newGuy = EntityManager::newID();
	EntityManager::setSignature(newGuy, 2);
	sName._owner = newGuy;
	sName.name = "NEW";
	nameArray.insert(sName);
	std::cout << "Name check:" << std::endl;
	nameArray.check();
	nameArray.insert(bName);
	std::cout << "Name check:" << std::endl;
	nameArray.check();
/*
	std::cout << "Entities nbr = " << EntityManager::getLivingEntities() << std::endl;
	std::cout << "Bob = " << bob << std::endl;
	std::cout << "Carl = " << carl << std::endl;

	EntityManager::setSignature(bob, 42);
	std::cout << "Bob's _signature = " << EntityManager::getSignature(bob) << std::endl;
	std::cout << "Carl's _signature = " << EntityManager::getSignature(carl) << std::endl;

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
