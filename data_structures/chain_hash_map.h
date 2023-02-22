#pragma once

#include "exceptions.h"

namespace data_structures
{

	template <class V_t>
	class ChainHashMap
	{

	private:

		typedef int K_t;

		struct Node;

		int N;
		Node** starts;

		int hash(K_t key) const
		{
			return key % N;
		}

		void insert_at(int index, K_t key, V_t value)
		{

			Node* node = new Node(key, value);

			if (starts[index] == nullptr)
			{

				starts[index] = node;

			}
			else
			{

				Node* curr = starts[index];

				while (curr->next != nullptr && curr->key != key)
					curr = curr->next;

				if (curr->key == key)
				{
					// If needing to replace an existing node
					curr->value = value;
				}
				else
				{
					// If needing to create a new node
					curr->next = node;
				}

			}

		}

		V_t get_at(int index, K_t key) const
		{

			if (starts[index] == nullptr)
			{
				throw KeyDoesntExistException();
			}
			else
			{

				Node* curr = starts[index];

				while (curr != nullptr && curr->key != key)
					curr = curr->next;

				if (curr == nullptr)
					throw KeyDoesntExistException();
				else
					return curr->value;

			}

		}

		void remove_at(int index, K_t key)
		{

			if (starts[index] == nullptr)
			{
				throw KeyDoesntExistException();
			}
			else
			{

				if (starts[index]->key == key)
				{

					Node* deleted = starts[index];
					starts[index] = starts[index]->next;
					delete deleted;

				}
				else
				{

					Node* prev = nullptr;
					Node* curr = starts[index];

					while (curr != nullptr && curr->key != key)
					{
						prev = curr;
						curr = curr->next;
					}

					if (curr == nullptr)
					{
						throw KeyDoesntExistException();
					}
					else
					{

						prev->next = curr->next;
						delete curr;

					}

				}

			}

		}

	public:

		ChainHashMap(int N) : N(N)
		{

			starts = new Node* [N];

			for (int i = 0; i < N; i++)
				starts[i] = nullptr;

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

		void remove(K_t key)
		{

			int hash_v = hash(key);

			remove_at(hash_v, key);

		}

	};

	template <class V_t>
	struct ChainHashMap<V_t>::Node
	{

		K_t key;
		V_t value;
		Node* next;

		Node(K_t key, V_t value, Node* next) : key(key), value(value), next(next) { }
		Node(K_t key, V_t value) : Node(key, value, nullptr) { }
		Node() { }

	};

}
