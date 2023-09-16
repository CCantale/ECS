#ifndef COMPONENTMANAGER_HPP
# define COMPONENTMANAGER_HPP

# include <vector>
# include <cstdbool>
# include "types.h"
# include "ComponentArray.hpp"

class ComponentManager
{
	private:
		static std::vector<IComponentArray>			_componentArrays;
		static Signature					_nextSignature;

		static int	signatureToPosition(Signature signature)
		{
			for (int i = 0; i < MAX_COMPONENTS; ++i)
			{
				if (signature[i] == 1)
					return (i);
			}
			return (-1);
		}

		static Signature	&positionToSignature(int position)
		{
			return (_components[i].signature);
		}

		static Signature	getNextSignature(void)
		{
			Signature	brandNewSignature;

			brandNewSignature = _nextSignature;
			_nextSignature <<= 1;
			return (brandNewSignature);
		}

		static std::vector<IComponentArray>::iterator	binarySearch(std::string name)
		{
			// binary search in _componentArrays[]
		}

	public:

		template <typename T>
		static void	addComponent(Entity entity, T &component, std::string &name) // does it deferenciate automatically?
		{
			component._owner = entity;
			if (addComponent(component, name) == SUCCESS)
			{
				return ;
			}
			else
			{
				ComponentArray	newComponentArray;
					
				newComponentArray.init(component, name, getNextSignature());
				addComponentArray(newComponentArray);
			}
		}

		template <typename T>
		static void	addComponentArray(IComponentArray array)
		{
			// binary search and _componentArrays.insert(iterator, array)
		}

		template <typename T>
		static bool	addComponent(T &component, std::string &name)
		{
			// binary search and 
			// if *it.name == name
			//	ComponentArray::insert(component);
			//	return (SUCCESS);
			// else
			//	return (FAIL);
		}
};

#endif
