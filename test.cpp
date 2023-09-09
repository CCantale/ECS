#include <iostream>
#include "types.h"

int	main(void)
{
	Entity entity;
	Component component;

	entity = 0;
	component = 0;
	++entity;
	++component;
	std::cout << "Hello World!" << std::endl;
	return (0);
}
