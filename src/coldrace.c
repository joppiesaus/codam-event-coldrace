#include "coldrace.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/time.h>

node_t	*buckets[256];

int main(void)
{
	char	*key;
	char	*value;
	int		hash;

	struct timeval stop1, stop2, start;
	gettimeofday(&start, NULL);

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
		set_value(&buckets[(hash & 0x000000FF)], toadd);
	}
	gettimeofday(&stop1, NULL);
	while (1)
	{
		key = get_next_line(0);
		if (key == 0 || *key == '\n')
		{
			free(key);
			break ;
		}
		hash = hash_func(key);
		char *find = get_value(&buckets[(hash & 0x000000FF)], hash, key);
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

	gettimeofday(&stop2, NULL);
	for (size_t i = 0; i < 256; i++)
	{
		delete_map(buckets[i]);
	}
	printf("1:%lu, 2:%lu\n", (stop1.tv_sec - start.tv_sec) * 1000000 + stop1.tv_usec - start.tv_usec, (stop2.tv_sec - stop1.tv_sec) * 1000000 + stop2.tv_usec - stop1.tv_usec);
	return 0;
}
