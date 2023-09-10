#ifndef ENTITYMANAGER_HPP
# define ENTITYMANAGER_HPP

# include <iostream>
# include <queue>
# include <array>
# include "types.h"

class EntityManager
{
	private:
		static std::queue<Entity>			_availableEntities;
		static std::array<Signature, MAX_COMPONENTS>	_signatures;
		static int					_livingEntities;
	
	public:
		static void					init(void);
		static Entity					newID(void);
		static void					deleteID(Entity entity);
		static void					setSignature(Entity entity, Signature signature);
		static Signature const				getSignature(Entity entity);
		static int 					getLivingEntities(void);
};

#endif
