#include "coldrace.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	char	*key;
	char	*value;
	int		hash;

	while (1)
	{
		// TODO: OPTIMIZE lol
		key = get_next_line(0);
		if (*key == '\n' || key == 0)
		{
			free(key);
			break ;
		}
		value = get_next_line(0);
		if (value == 0 || *value == '\n')
			break ;
		hash = hash_func(key);
		node_t *toadd = malloc(sizeof(node_t));
		toadd->hash = hash;
		toadd->data = malloc(sizeof(listItem_t));
		toadd->data->key = key;
		toadd->data->value = value;
		toadd->data->next = 0;
		toadd->left = 0;
		toadd->right = 0;
		toadd->back = 0;
		set_value(toadd);
	}	
	while (1)
	{
		key = get_next_line(0);
		if (key == NULL)
		{
			break ;
		}
		else if (*key == '\n')
		{
			free(key);
			break ;
		}
		hash = hash_func(key);
		char *find = get_value(hash, key);
		if (!find)
		{
			printf("%s: Not found.\n", key);
		}
		else
		{
			printf("%s\n", find);
		}
		free(key);
	}

	delete_map();
	
	return 0;
}
