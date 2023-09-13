#ifndef NAME_HPP
# define NAME_HPP

# include <string>
# include "Component.hpp"

typedef struct s_Name : public Component
{
	std::string	name;
} Name;

#endif
