/* ********************************************************************************************** */
/*                                                                                                */
/*                                                        ################  ###           ###     */
/*                                                        ################  ####         ####     */
/*   tail.c                                                      ##         ## ##       ## ##     */
/*                                                      #######  ##  ###### ##  ## ### ##  ## ##  */
/*                                                     ########  ##  ###### ##  ##  #  ##  ## ##  */
/*   By: Cervac Petru <petru.cervac@gmail.com>        ##     ##  ##  ##     ##   ##   ##   ##     */
/*                                                      :::::##::##::##:::::##:::##:::##:::##:::  */
/*                                                      :::::##::##::##:::::##::::##:##::::##:::  */
/*   Created: 2016/11/10 09:57:35 by Cervac                  ##  ##  ##     ##    ## ##    ##     */
/*   Updated: 2016/12/03 18:02:17 by Cervac Petru             ##    ##      ##     ###     ##     */
/*                                                              ####        ##      #      ##     */
/*                                                                                                */
/* ********************************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "tail.h"

t_node *new_node(void *inf, int time)
{
	t_node	*tmp;

	if (NULL != (tmp = (t_node*)malloc(sizeof(t_node))))
	{
		tmp->inf = inf;
		tmp->time = time;
		tmp->next = NULL;
	}
	return (tmp);
}

void	add_node(t_node **end, t_node *new)
{
	if (NULL != end && new != NULL)
	{
		if (NULL == *end)
			*end = new;
		else
		{
			(*end)->next = new;
			*end = new;
		}
	}
}

void	add_asc_node(t_node **root, t_node *new)
{
	t_node	*tmp = *root;
	t_node	*prec = NULL;

	if (*root == NULL)
	{
		*root = new;
		return ;			
	}
	while (1)
	{
		if (new->time < tmp->time)
		{
			new->next = tmp;
			if (prec == NULL)
				*root = new;
			else
				prec->next = new;
			return ;
		}
		if (tmp->next == NULL)
		{
			tmp->next = new;
			return ;
		}
		prec = tmp;
		tmp = tmp->next;
	}
}

t_node	*rem_node(t_node **root)
{
	t_node	*tmp;

	if (root != NULL && *root != NULL)
	{
		if (NULL == (*root)->next)
		{
			free(*root);
			*root = NULL;
		}
		else
		{
			tmp = *root;
			*root = (*root)->next;
			free(tmp);
		}
		return (*root);
	}
	return (NULL);
}

int		getnr_node(t_node *root)
{
	int		size = 0;

	while (root != NULL)
	{
		root = root->next;
		size++;
	}
	return (size);
}

void	rem_tail(t_node **root)
{
	t_node	*tmp;

	while (*root != NULL)
	{
		tmp = *root;
		*root = (*root)->next;
		free(tmp->inf);
		free(tmp);
	}
}
