#include "get_next_line.h"

#include <unistd.h> /* read */
#include <stdlib.h> /* free */

static int	read_until_newline(const int fd, char **s, ssize_t *len)
{
	char	buf[BUFFER_SIZE + 1];
	ssize_t	bytes_read = -1;

	while (ft_strchr(*s, '\n') == 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			return (bytes_read);
		}
		buf[bytes_read] = 0;
		*len += bytes_read;
		*s = ft_strfjoin(*s, buf);
	}
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char		*sto = NULL;
	static ssize_t	len = 0;
	char			*ret;
	ssize_t			bytes_read;
	size_t			index;

	ret = NULL;
	if (ft_strchr(sto, '\n') == 0)
	{
		bytes_read = read_until_newline(fd, &sto, &len);
		if (bytes_read == -1 || (bytes_read == 0 && sto == NULL))
			return (NULL);
	}
	index = (size_t)ft_strchr(sto, '\n');
	if (index == 0)
	{
		if (*sto != 0)
			ret = ft_strndup_unsafe(sto, len);
		len = 0;
		free(sto);
		sto = NULL;
		return (ret);
	}
	index -= ((size_t)sto);
	ret = ft_strndup_unsafe(sto, index == 0 ? index + 1 : index);
	ft_memcpy(sto, sto + index + 1, len + 1 - (index + 1));
	len -= index + 1;
	return (ret);
}
