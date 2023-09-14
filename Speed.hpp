#ifndef SPEED_HPP
# define SPEED_HPP

# include "Component.hpp"

typedef struct s_Speed : public Component
{
	int	speed;
	void	print(void) override
	{
		std::cout << "speed = " << speed << std::endl;
	}
} Speed;

#endif
