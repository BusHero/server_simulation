/* ********************************************************************************************** */
/*                                                                                                */
/*                                                        ################  ###           ###     */
/*                                                        ################  ####         ####     */
/*   dem.c                                                       ##         ## ##       ## ##     */
/*                                                      #######  ##  ###### ##  ## ### ##  ## ##  */
/*                                                     ########  ##  ###### ##  ##  #  ##  ## ##  */
/*   By: Cervac Petru <petru.cervac@gmail.com>        ##     ##  ##  ##     ##   ##   ##   ##     */
/*                                                      :::::##::##::##:::::##:::##:::##:::##:::  */
/*                                                      :::::##::##::##:::::##::::##:##::::##:::  */
/*   Created: 2016/11/25 10:02:18 by Cervac                  ##  ##  ##     ##    ## ##    ##     */
/*   Updated: 2016/12/03 17:45:06 by Cervac Petru             ##    ##      ##     ###     ##     */
/*                                                              ####        ##      #      ##     */
/*                                                                                                */
/* ********************************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "dem.h"
#include "tail.h"

static t_node	*root = NULL;
static t_node	*end = NULL;

void	add_dem_tail(t_dem dem)
{
	t_dem *temp = (t_dem*)malloc(sizeof(t_dem));

	assert(temp != NULL);
	*temp = dem;
	add_node(&end, new_node(temp, temp->des_tm));
	root = (NULL == root ? end : root);
}

t_dem	rem_dem_tail(void)
{
	t_dem	temp = *((t_dem*)root->inf);

	end = (NULL == rem_node(&root) ? NULL : end);
	return (temp);
}

int		is_dem_tail(void)
{
	return (!(NULL == root));
}

int		get_size_tail(void)
{
	return(getnr_node(root));
}

int		proc_dem_tail(void)
{
	t_node	*tmp = root;
	int		nr = 0;

	while (tmp != NULL)
	{
		if (0 == --tmp->time)
			nr++;
		tmp = tmp->next;
	}
	return (nr);
}

void	free_dem_tail()
{
	rem_tail(&root);
	root = NULL;
	end = NULL;
}
