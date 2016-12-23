/* ********************************************************************************************** */
/*                                                                                                */
/*                                                        ################  ###           ###     */
/*                                                        ################  ####         ####     */
/*   servers.h                                                   ##         ## ##       ## ##     */
/*                                                      #######  ##  ###### ##  ## ### ##  ## ##  */
/*                                                     ########  ##  ###### ##  ##  #  ##  ## ##  */
/*   By: Cervac Petru <petru.cervac@gmail.com>        ##     ##  ##  ##     ##   ##   ##   ##     */
/*                                                      :::::##::##::##:::::##:::##:::##:::##:::  */
/*                                                      :::::##::##::##:::::##::::##:##::::##:::  */
/*   Created: 2016/12/05 08:17:16 by Cervac                  ##  ##  ##     ##    ## ##    ##     */
/*   Updated: 2016/12/05 12:10:24 by Cervac Petru             ##    ##      ##     ###     ##     */
/*                                                              ####        ##      #      ##     */
/*                                                                                                */
/* ********************************************************************************************** */

#ifndef __SERVERS_H__
# define __SERVERS_H__

# include <stdio.h>

int		get_free_server();
int		proc_dem_server();
void	add_dem_server(size_t nr, t_dem dem);
void	rem_dem_server(size_t nr);
int		is_free_server(size_t nr);
int		is_finish_server(size_t nr);
int		get_nr_servers();
int		get_usg_servers();
void	set_nr_serv(int nr);
void	free_servers();
t_dem	get_dem_server(size_t nr);

#endif //__SERVERS_H__