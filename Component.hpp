#ifndef COMPONENT_HPP
# define COMPONENT_HPP

typedef struct s_Component
{
	Entity		_owner;	
	Signature	_signature; // This will go eventually

	virtual void	inspect(void) = 0;

} Component;

#endif
