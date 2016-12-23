/* ********************************************************************************************** */
/*                                                                                                */
/*                                                        ################  ###           ###     */
/*                                                        ################  ####         ####     */
/*   servers.c                                                   ##         ## ##       ## ##     */
/*                                                      #######  ##  ###### ##  ## ### ##  ## ##  */
/*                                                     ########  ##  ###### ##  ##  #  ##  ## ##  */
/*   By: Cervac Petru <petru.cervac@gmail.com>        ##     ##  ##  ##     ##   ##   ##   ##     */
/*                                                      :::::##::##::##:::::##:::##:::##:::##:::  */
/*                                                      :::::##::##::##:::::##::::##:##::::##:::  */
/*   Created: 2016/11/25 17:24:23 by Cervac                  ##  ##  ##     ##    ## ##    ##     */
/*   Updated: 2016/12/08 08:11:00 by Cervac Petru             ##    ##      ##     ###     ##     */
/*                                                              ####        ##      #      ##     */
/*                                                                                                */
/* ********************************************************************************************** */

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "dem.h"

#define MAX_SERV 10

static size_t	nr_serv = 1;
static t_dem	server[MAX_SERV];
static t_dem	null_dem = {0, 0, 0};

/**
 * show that exist free servers
 * @return function will return number of first free server founded + 1
 *         or 0 there are not free servers
 */
int		get_free_server()
{
	size_t	i;

	// printf("in get\t\t\t%d \n", server[0].des_tm);
	for (i = 0; i < nr_serv; i++)
		if (0 == server[i].des_tm)
			return (i + 1);
	return (0);
}

/**
 * will process demerses in servers;
 */
int		proc_dem_server()
{
	size_t	i;
	int		proc = 0;

	for (i = 0; i < nr_serv; i++)
		if (server[i].des_tm != 0)
		{
			proc++;
			server[i].des_tm--;
		}
	return (proc);
	// printf("tm_des = %d \n", server[0].des_tm);
}

/**
 * add a demand to a server
 * @param nr  number of server
 * @param dem demand to be added
 */
void	add_dem_server(size_t nr, t_dem dem)
{
	// printf("in add\n");
	assert(nr < nr_serv);
	server[nr] = dem;
}

/**
 * cleansed the demand from a server
 * @param nr - number of server that will be cleansed
 */
void	rem_dem_server(size_t nr)
{
	assert(nr < nr_serv);
	server[nr] = null_dem;
}

t_dem	get_dem_server(size_t nr)
{
	assert(nr < nr_serv);
	return (server[nr]);
}

int		is_free_server(size_t nr)
{
	return (!memcmp((void*)&server[nr], (void*)&null_dem, sizeof(t_dem)));
}

int		is_finish_server(size_t nr)
{
	return (server[nr].des_tm == 0 && server[nr].nr_cl != 0);
}

int		get_nr_servers()
{
	return (nr_serv);
}

int		get_usg_servers()
{
	size_t	i;
	int		proc = 0;

	for (i = 0; i < nr_serv; i++)
		if (server[i].des_tm != 0)
			proc++;
	return (proc);
}

void	set_nr_serv(int nr)
{
	nr_serv = nr;
}

void	free_servers()
{
	size_t	i;
	for (i = 0; i < nr_serv; i++)
		server[i] = null_dem;
}