#ifndef COMPONENTARRAY_HPP
# define COMPONENTARRAY_HPP

# include <cstring>
# include <array>
# include "EntityManager.hpp"
# include "Component.hpp"

# define SUCCESS	0
# define FAIL		1

template <typename T>
class ComponentArray 
{
	private:
		std::array<T, MAX_ENTITIES>	_array;
		unsigned int			_size = 0;
		Signature 			_signature;

		// returns the position of the component owned by the entity.
		// in case the search fails, returns the suitable position
		// for the insertion of a new component for the provided entity.
		unsigned int	binarySearch(Entity entity)
		{
			unsigned int	low;
			unsigned int	high;
			unsigned int	last;
			unsigned int	ret;

			low = 0;
			high = _size - 1;
			ret = 0;
			while (low <= high)
			{
				last = ret;
				ret = low + (high - low) / 2;
				if (_array[ret].owner == entity)
					return (ret);
				if (_array[ret].owner > entity)
					high = ret - 1;
				else
					low = ret + 1;
			}
			return (ret + (last > ret));
		}

		short	makeSpace(unsigned int position)
		{
			T	*copy;
			T	*whereToMakeSpace;
			unsigned int	spaceToMake;

			whereToMakeSpace = _array.data() + position;
			spaceToMake = sizeof(T) * (_size - position);
			if (spaceToMake == 0)
				return (SUCCESS);
			copy = new T[spaceToMake];
			if (!copy)
				return (FAIL);
			std::memcpy(copy, whereToMakeSpace, spaceToMake);
			std::memcpy(whereToMakeSpace + 1, copy, spaceToMake);

			delete (copy);
			return (SUCCESS);
		}

	public:
		
		void	insert(T const &component)
		{
			unsigned int	whereToInsert;

			if (_size == 0)
			{
				std::memcpy(_array.data(), &component, sizeof(T));
				++_size;
				_signature = _array[0].signature; // gets component's signature
				return ;
			}
			whereToInsert = binarySearch(component.owner);
			if (makeSpace(whereToInsert) == SUCCESS)
			{
				std::memcpy(_array.data() + whereToInsert, &component, sizeof(T));
				++_size;
			}
		}

		void	erase(Entity entity)
		{
			unsigned int	whereToErase;

			whereToErase = binarySearch(entity);
			if (_array[whereToErase].owner != entity) // return if didn't find the right component
				return ;
			std::memcpy(_array.data() + whereToErase, _array.data() + whereToErase + 1, _size - (whereToErase + 1));
			--_size;
		}

		T	*getData(Entity entity)
		{
			unsigned int	position;

			if (_size == 0 || (EntityManager::getSignature(entity) & _signature) == 0)
				return (NULL);
			position = binarySearch(entity);
				return (&_array[position]);
		}

		void	onEntityDestroyed(Entity entity)
		{
			erase(entity);
		}

		void	check(void)
		{
			std::cout << "size = " << _size << std::endl; 
			for (unsigned int i = 0; i < _size; ++i)
			{
				std::cout << "entity = " << _array[i].owner << std::endl;
				std::cout << "signature = " << _array[i].signature << std::endl;
			}
		}

};

#endif
