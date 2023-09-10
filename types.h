#ifndef TYPES_H
# define TYPES_H

# include <cstdint>
# include <bitset>

# define NULL_ENTITY	MAX_ENTITIES + 1
# define MAX_ENTITIES	5000
# define MAX_COMPONENTS	32

using Entity = std::uint32_t;
using Component = std::uint8_t;
using Signature = std::bitset<MAX_COMPONENTS>;

#endif
