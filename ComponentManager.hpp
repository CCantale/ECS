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
			long	low;
			long	high;
			long	ret;
			int	place;

			place = 0;
			low = 0;
			high = _size - 1;
			ret = 0;
			while (low <= high)
			{
				ret = low + (high - low) / 2;
				//if (_componentArrays[ret]._name.compare(name) == 0)
					//return (ret);
				if (_componentArrays[ret]._name[place] == name[place])
				{
					++place;
					continue ;
				}
				else if (_componentArrays[ret]._name[place] > name[place])
				{
					high = ret - 1;
				}
				else
				{
					low = ret + 1;
				}
				place = 0;
			}
			return (ret + (entity > _componentArrays[ret]._owner));
		}

	public:

		template <typename T>
		static void	addComponent(Entity entity, T &component, std::string &name) // does it deferenciate automatically? Ya, I think so.
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

};

#endif
