#include "coldrace.h"

#include <unistd.h> // write

#define PBUF_SIZE 65535

static char	g_print_buf[PBUF_SIZE];
static int	g_print_i = 0;

void	print(const char *str)
{
	while (*str)
	{
		g_print_buf[g_print_i] = *str;
		g_print_i++;
		if (g_print_i == PBUF_SIZE)
		{
			pflush();
		}
		str++;
	}
}

void pflush()
{
	write(1, g_print_buf, g_print_i);
	g_print_i = 0;
}
