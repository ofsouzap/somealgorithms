#pragma once

#include "exceptions.h"

namespace data_structures
{

	template <class V_t>
	class TreeMap
	{

	public:
		typedef int K_t;
		struct Node;

	private:

		Node* root;

	public:

		TreeMap()
		{
			root = nullptr;
		}

		void set(K_t key, V_t value)
		{

			if (root == nullptr)
			{
				root = new Node(key, value, nullptr);
			}
			else
			{

				Node* curr = root;

				while (true)
				{

					if (key == curr->key)
					{
						curr->value = value;
						return;
					}
					else if (key < curr->key)
					{
						if (curr->left != nullptr)
						{
							curr = curr->left;
						}
						else
						{
							curr->left = new Node(key, value, curr);
							return;
						}
					}
					else
					{
						if (curr->right != nullptr)
						{
							curr = curr->right;
						}
						else
						{
							curr->right = new Node(key, value, curr);
							return;
						}
					}

				}

			}

		}

		V_t get(K_t key) const
		{

			Node* curr = root;

			while (curr != nullptr)
			{
				if (key == curr->key)
				{
					return curr->value;
				}
				else if (key < curr->key)
				{
					curr = curr->left;
				}
				else
				{
					curr = curr->right;
				}
			}

			throw KeyDoesntExistException();

		}

	};

	template <class V_t>
	struct TreeMap<V_t>::Node
	{

		K_t key;
		V_t value;
		Node* parent;
		Node* left;
		Node* right;

		Node(K_t key, V_t value, Node* parent) : key(key), value(value), parent(parent)
		{
			left = nullptr;
			right = nullptr;
		}

	};

}