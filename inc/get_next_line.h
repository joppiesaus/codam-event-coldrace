#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>

# define BUFFER_SIZE (1024)

char	*get_next_line(int fd);

char	*ft_strfjoin(char *s1, char const *s2);
char	*ft_strchr(const char *s, const int c);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);

char	*ft_strndup_unsafe(const char *s1, const size_t len);

#endif