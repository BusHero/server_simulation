/* ********************************************************************************************** */
/*                                                                                                */
/*                                                        ################  ###           ###     */
/*                                                        ################  ####         ####     */
/*   calendar.c                                                  ##         ## ##       ## ##     */
/*                                                      #######  ##  ###### ##  ## ### ##  ## ##  */
/*                                                     ########  ##  ###### ##  ##  #  ##  ## ##  */
/*   By: Cervac Petru <petru.cervac@gmail.com>        ##     ##  ##  ##     ##   ##   ##   ##     */
/*                                                      :::::##::##::##:::::##:::##:::##:::##:::  */
/*                                                      :::::##::##::##:::::##::::##:##::::##:::  */
/*   Created: 2016/11/30 22:48:45 by Cervac                  ##  ##  ##     ##    ## ##    ##     */
/*   Updated: 2016/12/03 17:53:38 by Cervac Petru             ##    ##      ##     ###     ##     */
/*                                                              ####        ##      #      ##     */
/*                                                                                                */
/* ********************************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "tail.h"
#include "calendar.h"

static t_node	*root;
static char		type[4][6] = {"START", "p", "s", "STOP"};
static int		stop = 0;

void	add_even_cal(int time, int nr_cl, int type)
{
	t_cal	*tmp = (t_cal*)malloc(sizeof(t_cal));

	if (type == 3)
		stop = time;
	else
	{
		tmp = (t_cal*)malloc(sizeof(t_cal));
		tmp->time = time;
		tmp->nr_cl = nr_cl;
		tmp->type = type;
		add_asc_node(&root, new_node(tmp, time));
	}
}

void	record_cal()
{
	t_node	*tmp = root;
	t_cal	*cal;

	if (root == NULL)
	{
		printf("\n");
		return ;
	}
	while (tmp != NULL)
	{
		cal = ((t_cal*)tmp->inf);
		printf("(%d,%d,%s)", cal->time, cal->nr_cl, type[cal->type]);
		if (tmp->next != NULL)
			printf(",");
		tmp = tmp->next;
	}
	if (stop)
		printf("(%d,-,STOP)",stop);
	printf("\n");
}

void	record_cal_file(FILE *fp)
{
	t_node	*tmp = root;
	t_cal	*cal;

	if (root == NULL)
	{
		fprintf(fp, "\n");
		return ;
	}
	while (tmp != NULL)
	{
		cal = ((t_cal*)tmp->inf);
		fprintf(fp, "(%d,%d,%s)", cal->time, cal->nr_cl, type[cal->type]);
		if (tmp->next != NULL)
			fprintf(fp, ",");
		tmp = tmp->next;
	}
	if (stop)
		fprintf(fp, "(%d,-,STOP)",stop);
	fprintf(fp, "\n");
}

void	rem_even_cal()
{
	rem_node(&root);
}

void	free_evn_cal()
{
	rem_tail(&root);
}

void	rem_stop_cal()
{
	stop = 0;
}