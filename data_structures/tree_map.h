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

		void swap_nodes(Node* const n1, Node* const n2)
		{

			Node* n1_parent = n1->parent;

			bool n1_is_left_child = true;
			if (n1_parent != nullptr)
				n1_is_left_child = n1_parent->left == n1;

			Node* n2_parent = n2->parent;

			bool n2_is_left_child = true;
			if (n2_parent != nullptr)
				n2_is_left_child = n2_parent->left == n2;

			// Change tree root if needed

			if (root == n1)
				root = n2;
			else if (root == n2)
				root = n1;

			// Change parents' children pointers

			if (n1_parent != nullptr)
			{

				// Set n1's new child to be n2

				if (n1_is_left_child)
					n1_parent->left = n2;
				else
					n1_parent->right = n2;

			}

			if (n2_parent != nullptr)
			{

				// Set n2's new child to be n1

				if (n2_is_left_child)
					n2_parent->left = n1;
				else
					n2_parent->right = n1;

			}

			// Change nodes' parent pointers

			n1->parent = n2_parent;
			n2->parent = n1_parent;

			// Swap children

			Node* n1_left = n1->left;
			Node* n1_right = n1->right;

			n1->left = n2->left;
			n1->right = n2->right;

			n2->left = n1_left;
			n2->right = n1_right;

		}

		Node* child_succ(const Node* const node) const
		{

			if (node->right == nullptr)
			{
				return nullptr;
			}
			else
			{
				
				Node* curr = node->right;

				while (curr->left != nullptr)
					curr = curr->left;

				return curr;

			}

		}

		Node* get_node(const K_t key) const
		{

			Node* curr = root;

			while (curr != nullptr)
			{
				if (key == curr->key)
				{
					return curr;
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

		V_t get(const K_t key) const
		{
			return get_node(key)->value;
		}

		void remove(const K_t key)
		{

			Node* node = get_node(key);
			Node* n_succ = child_succ(node);

			if (node->is_leaf())
			{

				// If node is leaf then it can just be deleted

				if (root == node)
				{

					root = nullptr;

				}
				else
				{

					// Remove node as parent's child

					bool node_is_left_child = node->parent->left == node;

					if (node_is_left_child)
						node->parent->left = nullptr;
					else
						node->parent->right = nullptr;

				}

			}
			else if (n_succ == nullptr)
			{

				// If the node has no successor then it can only have a left child

				if (root == node)
				{

					root = node->left;

				}
				else
				{

					// Swap the node for its left subtree

					bool node_is_left_child = node->parent->left == node;

					if (node_is_left_child)
						node->parent->left = node->left;
					else
						node->parent->right = node->left;

				}

			}
			else
			{

				// Replace node with its successor

				swap_nodes(node, n_succ);

				// Remove node from tree

				bool node_is_left_child = node->parent->left == node;

				if (node_is_left_child)
					node->parent->left = nullptr;
				else
					node->parent->right = nullptr;

			}

			// Delete node

			delete node;

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

		bool is_leaf() const
		{
			return left == nullptr && right == nullptr;
		}

	};

}