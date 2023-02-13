#pragma once

#include "exceptions.h"

namespace data_structures
{

	template <class K_t, class V_t>
	class BasicListMap
	{

	public:
		struct Node;

	private:

		Node* start;

	public:

		BasicListMap()
		{
			start = nullptr;
		}

		void set(K_t key, V_t value)
		{
			if (start == nullptr)
			{
				start = new Node(key, value, nullptr);
			}
			else
			{
				start = new Node(key, value, start);
			}
		}

		V_t get(K_t key) const
		{

			Node* curr = start;
			while (curr != nullptr)
			{
				if (curr->key == key)
				{
					return curr->value;
				}
				else
				{
					curr = curr->next;
				}
			}

			throw KeyDoesntExistException();

		}

	};

	template <class K_t, class V_t>
	struct BasicListMap<K_t, V_t>::Node
	{
		K_t key;
		V_t value;
		Node* next;
		Node(K_t key, V_t value, Node* next) : key(key), value(value), next(next)
		{ }
	};

}