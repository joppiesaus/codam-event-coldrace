#ifndef COLDRACE_H
#define COLDRACE_H

#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct node_s
{
	int hash;
	char *key;
	char *value;

	struct node_s *left;
	struct node_s *right;

}		node_t;

int	hash_func(const char *str);
void	set_value(node_t *node);
char	*get_value(int tofind);

#endif