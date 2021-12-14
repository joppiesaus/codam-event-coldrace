#include "get_next_line.h"

#include <unistd.h> /* read */
#include <stdlib.h> /* free */

static void	m_free_and_set_null(void **p)
{
	free(*p);
	*p = NULL;
}

static int	read_until_newline(const int fd, char **s)
{
	char	buf[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	while (ft_strchr(*s, '\n') == 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			return (bytes_read);
		}
		buf[bytes_read] = 0;
		*s = ft_strfjoin(*s, buf);
	}
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char		*sto = NULL;
	char			*ret;
	ssize_t			bytes_read;
	size_t			index;

	ret = NULL;
	if (ft_strchr(sto, '\n') == 0)
	{
		bytes_read = read_until_newline(fd, &sto);
		if (bytes_read == -1 || (bytes_read == 0 && sto == NULL))
			return (NULL);
	}
	index = (size_t)ft_strchr(sto, '\n');
	if (index == 0)
	{
		if (*sto != 0)
			ret = ft_strndup_unsafe(sto, ft_strlen(sto));
		m_free_and_set_null((void **)&sto);
		return (ret);
	}
	index -= ((size_t)sto);
	ret = ft_strndup_unsafe(sto, index == 0 ? index + 1 : index);
	ft_memcpy(sto, sto + index + 1, ft_strlen(sto) + 1 - (index + 1));
	return (ret);
}
