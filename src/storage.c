#include <coldrace.h>
#define LEFT 1
#define RIGHT 0

node_t *base;

node_t	*move_it_or_create(node_t *it, int dir, node_t *create)
{
	if (dir == LEFT)
	{
		if (it->left)
			return it->left;
		create->back = it;
		it->left = create;
		return it->left;
	}
	else
	{
		if (it->right)
			return it->right;
		create->back = it;
		it->right = create;
		return it->right;
	}
}

void	set_value(node_t *node)
{
	if (!base)
	{
		base = node;
	}
	else
	{
		node_t *it = base;
		while (it->hash != node->hash)
		{
			if (it->hash > node->hash)
				it = move_it_or_create(it, LEFT, node);
			else
				it = move_it_or_create(it, RIGHT, node);
		}
	}	
}

char	*get_value(int tofind)
{
	if (!base)
		return (0);
	node_t *it = base;
	while (it && it->hash != tofind)
	{
		if (it->hash < tofind)
			it = it->right;
		else if (it->hash > tofind)
			it = it->left;
	}
	if (it)
		return it->value;
	return 0;
}

void	delete_map()
{
	node_t *it = base;
	while (it->left)
	{
		it = it->left;
	}
	while (it)
	{
		if (it->right)
			it = it->right;
		else if (it->left)
			it = it->left;
		else if (!it->left && !it->right)
		{
			node_t *tmp = it->back;
			if (tmp)
			{
				if (tmp->right == it)
					tmp->right = 0;
				else
					tmp->left = 0;
			}
			free(it->key);
			free(it->value);
			free(it);
			it = tmp;
		}
		

	}
	
	
}