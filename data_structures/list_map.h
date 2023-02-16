#pragma once

#include "exceptions.h"

// Below is just for fun
#define until(cond) while (!(cond))

namespace data_structures
{

	template <class K_t, class V_t>
	class ListMap
	{

	public:
		struct Node;

	private:

		Node* start;

	public:

		ListMap()
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

				Node* curr = start;

				while (curr != nullptr)
				{
					if (curr->key == key)
					{
						curr->value = value;
						return;
					}
					else
					{
						curr = curr->next;
					}
				}

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

		void remove(K_t key)
		{

			if (start->key == key)
			{
				start = start->next; // Even if start->next is nullptr this is fine
			}
			else
			{

				Node* prev = start;
				Node* curr = start->next;
				
				until (curr == nullptr || curr->key == key)
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

					// curr->key must be key

					// Update previous node's pointer
					prev->next = curr->next;

					// Free space of current node
					delete curr;

				}

			}

		}

	};

	template <class K_t, class V_t>
	struct ListMap<K_t, V_t>::Node
	{
		K_t key;
		V_t value;
		Node* next;
		Node(K_t key, V_t value, Node* next) : key(key), value(value), next(next)
		{ }
	};

}