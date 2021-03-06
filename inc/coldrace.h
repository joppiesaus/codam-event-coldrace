#ifndef COLDRACE_H
#define COLDRACE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

typedef	struct listItem_s
{
	char *key;
	char *value;
	struct listItem_s *next;
}				listItem_t;


typedef struct node_s
{
	int hash;
	listItem_t *data;

	struct node_s *back;
	struct node_s *left;
	struct node_s *right;

}		node_t;

int		hash_func(const char *str);
void	set_value(node_t **base, node_t *node);
char	*get_value(node_t **base, int tofind, char *key);
void	delete_map(node_t *base);

int		ft_strcmp(const char *s1, const char *s2);
void	pflush();
void	print(const char *str);

#endif

