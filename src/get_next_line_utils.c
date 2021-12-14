#include "get_next_line.h"

#include <stdlib.h> /* malloc */

size_t	ft_strlen(const char *s)
{
	const char	*start;

	start = s;
	while (*s != 0)
	{
		s++;
	}
	return (s - start);
}

/* locates memory location of char c in s, returns NULL if not found. */
char	*ft_strchr(const char *s, const int c)
{
	if (s == NULL)
		return ((char *)s);
	while (*s != 0)
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if ((char)c == 0)
	{
		return ((char *)s);
	}
	return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	size_t	max_n;

	i = 0;
	max_n = (n / sizeof(size_t));
	while (i < max_n)
	{
		((size_t *)dst)[i] = ((const size_t *)src)[i];
		i++;
	}
	i *= sizeof(size_t);
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

/* modified strjoin which frees s1. s1 may be NULL,
 * s2 never should be. */
char	*ft_strfjoin(char *s1, char const *s2)
{
	char	*res;
	size_t	s1_len;
	size_t	s2_len;

	s2_len = ft_strlen(s2);
	if (s1 == NULL)
		s1_len = 0;
	else
		s1_len = ft_strlen(s1);
	res = malloc(s1_len + s2_len + 1);
	if (res == NULL)
		return (NULL);
	ft_memcpy(res, s1, s1_len);
	ft_memcpy(res + s1_len, s2, s2_len);
	if (s1 != NULL)
		free(s1);
	res[s2_len + s1_len] = 0;
	return (res);
}

//#include <stdio.h>

/* this is a strdup which stops at len characters.
 * it duplicates string s1, at most len chars.
 * it does NO BOUNDS CHECKING. If you give a len greater than its
 * string length, it will access memory it's not supposed to. */
char	*ft_strndup_unsafe(const char *s1, const size_t len)
{
	char	*s2;

	s2 = malloc(len + 1);
	if (s2 != NULL)
	{
		printf("%d\n", len);
		//ft_memcpy(s2, s1, len);
		s2[len] = 0;
	}
	return (s2);
}
