#pragma once

#include "exceptions.h"

namespace data_structures
{
    template <class V_t>
	class OpenAddrHashMap
	{

        // Uses quadratic probing for collision rectification with the formula:
        //     index to place in = () h(k) + 1 * (j^2) ) % N
        //         h(k) - hash of the key
        //         j = 0,1,... - increases each time the position is already taken

	private:

		typedef int K_t;

		struct Entry
		{
			bool is_set;
			K_t key;
			V_t value;
		};
		
		int N;
		Entry* table;

		int hash(K_t key) const
		{
			return key % N;
		}

        bool is_full() const
        {

            for (int i = 0; i < N; i++)
                if (!table[i].is_set)
                    return false;

            return true;

        }

		void insert_at(int index, K_t key, V_t value)
		{

            if (is_full())
                throw NoSpaceInHashTableException();

			if (!table[index].is_set)
			{

				table[index] = { true, key, value };

			}
			else
			{

                int j = 0;
                int i = (index + (j*j)) % N;

                int start_index = i;

				while (table[i].is_set && table[i].key != key)
                {

                    j++;
                    i = (index + (j*j)) % N;

                }

				if (table[i].key == key)
				{
					// If needing to replace an existing entry
					table[i].value = value;
				}
				else
				{
					// If needing to create a new entry
					table[i] = { true, key, value };
				}

			}

		}

		V_t get_at(int index, K_t key) const
		{

            int j = 0;
            int i = (index + (j*j)) % N;

            while (table[i].key != key && table[i].is_set)
            {
                j++;
                i = (index + (j*j)) % N;
            }

            if (!table[i].is_set)
                throw KeyDoesntExistException();
            else
                return table[i].value;

		}

	public:

		OpenAddrHashMap(int N, V_t default_value) : N(N)
		{

			table = new Entry[N];

			for (int i = 0; i < N; i++)
				table[i] = { false, 0, default_value };

		}

		void set(K_t key, V_t value)
		{

			int hash_v = hash(key);

			insert_at(hash_v, key, value);

		}

		V_t get(K_t key) const
		{

			int hash_v = hash(key);

			return get_at(hash_v, key);

		}

	};
}
