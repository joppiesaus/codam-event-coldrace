#include "coldrace.h"

int	hash_func(const char *str)
{
	int	hash = 234975987;
	//int	*istr = (int *)str;
	//int	len;

	// todo: len == 0
	//len = ft_strlen(str) / sizeof(int);

	/*for (int i = 0; i < len; i++)
	{
		hash ^= istr[i] + (hash << 6) + (hash >> 2);
	}*/

	while (*str)
	{
		hash ^= *str + (hash << 6) + (hash >> 2);
		str++;
	}
	return (hash);
}
