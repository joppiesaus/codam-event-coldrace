#include "coldrace.h"
#include "get_next_line.h"

int main(void)
{
	char	*key;
	char	*value;
	int		hash;

	while (1)
	{
		// TODO: OPTIMIZE
		key = get_next_line(0);
		if (*key == '\n' || key == 0)
			break ;
		value = get_next_line(0);
		if (value == 0 || *value == '\n')
			break ;
		hash = hash_func(key);
		// printf("%s$ %x\n", key, hash);
		node_t *toadd = malloc(sizeof(node_t));
		toadd->hash = hash;
		toadd->key = key;
		toadd->value = value;
		toadd->left = 0;
		toadd->right = 0;
		set_value(toadd);

	}
	while (1)
	{
		key = get_next_line(0);
		if (key == 0 || *key == '\n')
			break ;
		hash = hash_func(key);
		char *find = get_value(hash);
		if (!find)
			printf("%s: Not found.\n", key);	
		else
			printf("%s\n", find);
	}
	
	return 0;
}