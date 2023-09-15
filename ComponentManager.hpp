#ifndef COMPONENTMANAGER_HPP
# define COMPONENTMANAGER_HPP

# include <array>
# include "types.h"
# include "ComponentArray.hpp"

class ComponentManager
{
	private:
		static std::array<IComponentArray, MAX_COMPONENTS>	_componentArrays;
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

	public:
		template <typename T>
		static void	addComponent(T *component)
		{
			// if first time, create component array
			// then add
			// delete
		}

		template <typename T>
		static void	addComponent(T &component)
		{
			// if first time, create component array
			// then add
			// do not delete
		}
};

#endif
