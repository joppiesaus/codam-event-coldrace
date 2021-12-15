#include "coldrace.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/time.h>

node_t	*buckets[65536];

int main(void)
{
	char	*key;
	char	*value;
	int		hash;

//	struct timeval stop1, stop2, start;

	while (1)
	{
		// TODO: OPTIMIZE lol
		key = get_next_line(0);
		if (key == 0 || *key == '\n')
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
		set_value(&buckets[(hash & 0x0000FFFF)], toadd);
	}
	while (1)
	{
		key = get_next_line(0);
		if (key == 0 || *key == '\n')
		{
			free(key);
			break ;
		}
		hash = hash_func(key);
		char *find = get_value(&buckets[(hash & 0x0000FFFF)], hash, key);
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
	for (size_t i = 0; i < 65536; i++)
	{
		delete_map(buckets[i]);
	}
	return 0;
}
