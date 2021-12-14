#include <coldrace.h>
#define LEFT 1
#define RIGHT 0

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

void	set_value(node_t **base, node_t *node)
{
	if (!(*base))
	{
		*base = node;
	}
	else
	{
		node_t *it = *base;
		while (it->hash != node->hash)
		{
			if (it->hash > node->hash)
				it = move_it_or_create(it, LEFT, node);
			else
				it = move_it_or_create(it, RIGHT, node);
		}
		if (node->data->key != it->data->key)
		{
			listItem_t *nxt = it->data;
			while (nxt->next)
			{
				nxt = nxt->next;
			}
			nxt->next = node->data;
			free(node);
		}
		
	}	
}

char	*get_value(node_t **base, int tofind, char *key)
{
	if (!(*base))
		return (0);
	node_t *it = *base;
	while (it && it->hash != tofind)
	{
		if (it->hash < tofind)
			it = it->right;
		else if (it->hash > tofind)
			it = it->left;
	}
	if (it)
	{
		if (it->data->next)
		{
			listItem_t *li = it->data;
			while (li)
			{
				if (ft_strcmp(key, li->key) == 0)
					return li->value;
				li = li->next;
			}
		}
		else
			return it->data->value;
	}
	return 0;
}

void	delete_map(node_t *base)
{
	if (!base)
		return;
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
			listItem_t *iter = it->data;
			while (iter)
			{
				listItem_t *itertmp = iter;
				free(iter->key);
				free(iter->value);
				iter = iter->next;
				free(itertmp);
			}
			
			free(it);
			it = tmp;
		}
	}
}
