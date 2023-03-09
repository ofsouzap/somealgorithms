#pragma once

#include "tree_map.h"

namespace data_structures
{

	class TreeSet : protected TreeMap<bool>
	{

		// I'm being lazy: this is just a TreeMap with meaningless values and the keys are the items in the set

	public:

		TreeSet() : TreeMap()
		{
		}

		void add(TreeMap::K_t x)
		{
			TreeMap::set(x, false);
		}

		bool contains(TreeMap::K_t x) const
		{
			return TreeMap::contains_key(x);
		}

		void remove(TreeMap::K_t x)
		{
			TreeMap::remove(x);
		}

	};

}