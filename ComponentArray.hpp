#ifndef COMPONENTARRAY_HPP
# define COMPONENTARRAY_HPP

# include <array>
# include "EntityManager.hpp"
# include "Component.hpp"

# define SUCCESS	0
# define FAIL		1

// An interface is needed to later group multiple different ComponentArrays in a single array
class IComponentArray
{
	public:
		virtual 	~IComponentArray(void) {}
		virtual void	onEntityDestroyed(Entity entity) = 0;
};

template <typename T>
class ComponentArray : public IComponentArray
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
			long	low;
			long	high;
			long	ret;

			low = 0;
			high = _size - 1;
			ret = 0;
			while (low <= high)
			{
				ret = low + (high - low) / 2;
				if (_array[ret].owner == entity)
					return (ret);
				if (_array[ret].owner > entity)
					high = ret - 1;
				else
					low = ret + 1;
			}
			return (ret + (entity > _array[ret].owner));
		}

		short	makeSpace(unsigned int position)
		{
			T		*copy;
			unsigned int	spaceToMake;

			spaceToMake = _size - position;
			if (spaceToMake == 0)
				return (SUCCESS);
			copy = new T[spaceToMake];
			if (!copy)
				return (FAIL);
			for (unsigned int i = 0; i < spaceToMake; ++i)
			{
				copy[i] = _array[position + i];
			}
			for (unsigned int i = 0; i < spaceToMake; ++i)
			{
				_array[position + i + 1] = copy[i];
			}

			delete [] (copy);
			return (SUCCESS);
		}

	public:
		
		void	insert(T const &component)
		{
			unsigned int	whereToInsert;

			if (_size == 0)
			{
				_array[0] = component;
				++_size;
				_signature = _array[0].signature; // gets component's signature. this acquisition method should change in the future
				return ;
			}
			whereToInsert = binarySearch(component.owner);
			if (component.owner != _array[whereToInsert].owner // check that we didn't already have this entity-component couple
				&& makeSpace(whereToInsert) == SUCCESS)
			{
				_array[whereToInsert] = component;
				++_size;
			}
		}

		void	erase(Entity entity)
		{
			unsigned int	whereToErase;

			whereToErase = binarySearch(entity);
			whereToErase += MAX_ENTITIES * (_array[whereToErase].owner != entity); // inhibits the following loop in case the entity was not found
			std::cout << "WHERE = " << whereToErase << std::endl;
			for (unsigned int i = whereToErase; i < _size - 1; ++i)
			{
				_array[i] = _array[i + 1];
			}
			_size -= (whereToErase < MAX_ENTITIES); // only decreases _size when the binary search was successful
		}

		T	*getData(Entity entity)
		{
			unsigned int	position;

			if (_size == 0 || (EntityManager::getSignature(entity) & _signature) == 0)
				return (NULL);
			position = binarySearch(entity);
			return (&_array[position]);
		}

		void	onEntityDestroyed(Entity entity) override
		{
			erase(entity);
		}

		void	check(void)
		{
			std::cout << "size = " << _size << std::endl; 
			for (unsigned int i = 0; i < _size; ++i)
			{
				std::cout << std::endl;
				std::cout << "entity = " << _array[i].owner << std::endl;
				std::cout << "signature = " << _array[i].signature << std::endl;
				_array[i].print();
				std::cout << std::endl;
			}
		}

};

#endif
