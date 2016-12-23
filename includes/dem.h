/* ********************************************************************************************** */
/*                                                                                                */
/*                                                        ################  ###           ###     */
/*                                                        ################  ####         ####     */
/*   dem.h                                                       ##         ## ##       ## ##     */
/*                                                      #######  ##  ###### ##  ## ### ##  ## ##  */
/*                                                     ########  ##  ###### ##  ##  #  ##  ## ##  */
/*   By: Cervac Petru <petru.cervac@gmail.com>        ##     ##  ##  ##     ##   ##   ##   ##     */
/*                                                      :::::##::##::##:::::##:::##:::##:::##:::  */
/*                                                      :::::##::##::##:::::##::::##:##::::##:::  */
/*   Created: 2016/11/25 09:15:20 by Cervac                  ##  ##  ##     ##    ## ##    ##     */
/*   Updated: 2016/12/08 08:07:49 by Cervac Petru             ##    ##      ##     ###     ##     */
/*                                                              ####        ##      #      ##     */
/*                                                                                                */
/* ********************************************************************************************** */

#ifndef __DEM_H__
# define __DEM_H__

# include <stdio.h>

typedef struct	s_client
{
	int			arv_per;
	int			des_per;
}				t_client;

typedef struct	s_even
{
	int			mom;
	int			nr_cl;
	char		*type;
}				t_even;

typedef struct	s_dem
{
	int			nr_cl;
	int			des_tm;
	int			arv_tm;
}				t_dem;

void			add_dem_tail(t_dem dem);
t_dem			rem_dem_tail(void);
int				is_dem_tail(void); 
int				get_size_tail(void);
int				proc_dem_tail(void);
void			set_nr_serv(int nr);
void			free_dem_tail();

#endif //__DEM_H__