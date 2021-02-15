#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node {
	int value;
	tree_node* left;
	tree_node* right;
} tree_node;

tree_node* add(tree_node* root, int value);
tree_node* add_rec(tree_node* root, int value);
tree_node* search(tree_node* root, int value);
tree_node* search_rec(tree_node* root, int value);
tree_node* get_min(tree_node* root);
tree_node* get_max(tree_node* root);
tree_node* remove(tree_node* root, int value);
tree_node* print_asc(tree_node* root);  // по возрастанию
tree_node* print_desc(tree_node* root); // по убыванию
tree_node* destroy(tree_node* tree);

int main()
{
	tree_node* root = NULL;
	root = add(root, 15);
	print_asc(root);
	printf("\n");
	root = remove(root, 16);
	destroy(root);
	return 0;
}

tree_node* add(tree_node* root, int value)
{
	tree_node* current = root;
	tree_node* new_node = (tree_node*)malloc(sizeof(tree_node));
	new_node->value = value;
	new_node->left = NULL;
	new_node->right = NULL;
	while (current)
	{
		if (current->value == value)
		{
			free(new_node);
			return root;
		}
		if (value < current->value)
		{
			if (current->left)
			{
				current = current->left;
			}
		}
		else
		{
			current->left = new_node;
			return root;
		}
		if (value > current->value)
		{
			if (current->right)
			{
				current = current->right;
			}
			else
			{
				current->right = new_node;
				return root;
			}
		}
	}
	return new_node;
}
tree_node* add_rec(tree_node* root, int value)
{
	if (!root)
	{
		root = (tree_node*)malloc(sizeof(tree_node));
		root->value = value;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	if (value > root->value)
	{
		root->right = add_rec(root->right, value);
	}
	if (value < root->value)
	{
		root->left = add_rec(root->left, value);
	}
	return root;
}
tree_node* search(tree_node* root, int value)
{
	tree_node* current = root;
	while (current)
	{
		if (value == current->value)
		{
			return current;
		}
		if (value < current->value)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}
	return current;
}
tree_node* search_rec(tree_node* root, int value)
{
	if (!root)
	{
		return NULL;
	}
	if (root->value == value)
	{
		return root;
	}
	if (value > root->value)
	{
		return search_rec(root->right, value);
	}
	else
	{
		return search_rec(root->left, value);
	}
	return NULL;
}
tree_node* get_min(tree_node* root)
{
	if (!root)
		return NULL;
	while (root->left)
	{
		root = root->left;
	}
	return root;
}
tree_node* get_max(tree_node* root)
{
	if (!root)
		return NULL;
	while (root->right)
	{
		root = root->right;
	}
	return root;
}
tree_node* remove(tree_node* root, int value)
{
	if (!root)
		return NULL;
	tree_node* temp;
	if (value > root->value)
	{
		root->right = remove(root->right, value);
	}
	if (value < root->value)
	{
		root->left = remove(root->left, value);
	}
	if (root->value == value)
	{
		if (!root->left && !root->right)
		{
			free(root);
			return NULL;
		}
		if (root->left && !root->right)
		{
			temp = root->left;
			free(root);
			return temp;
		}
		if (!root->left && root->right)
		{
			temp = root->right;
			free(root);
			return temp;
		}
		if (root->left && root->right)
		{
			int max_left = get_max(root->left)->value;
			int min_right = get_min(root->right)->value;
			if ((root->value - max_left) < (min_right - root->value))
			{
				remove(root, max_left);
				root->value = max_left;
			}
			else
			{
				remove(root, min_right);
				root->value = min_right;
			}
		}
		return root;
	}
	return root;
}
tree_node* print_asc(tree_node* root)
{
	if (!root)
		return;
	if (root->left)
	{
		print_asc(root->left);
	}
	printf("%4d", root->value);
	if (root->right)
	{
		print_asc(root->right);
	}
	return;
}
tree_node* print_desc(tree_node* root)
{
	if (!root)
		return;
	if (root->right)
		print_desc(root->right);

	printf("%4d", root->value);
	if (root->left)
		print_desc(root->left);
	return;
}
tree_node* destroy(tree_node* root)
{
	if (root)
	{
		destroy(root->left);
		destroy(root->right);
		free(root);
	}
	return;
}























