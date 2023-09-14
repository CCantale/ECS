#ifndef COMPONENT_HPP
# define COMPONENT_HPP

typedef struct s_Component
{
		Entity		owner;	
		Signature	signature;

		virtual void		print(void) = 0;

} Component;

#endif
