/* ********************************************************************************************** */
/*                                                                                                */
/*                                                        ################  ###           ###     */
/*                                                        ################  ####         ####     */
/*   calendar.h                                                  ##         ## ##       ## ##     */
/*                                                      #######  ##  ###### ##  ## ### ##  ## ##  */
/*                                                     ########  ##  ###### ##  ##  #  ##  ## ##  */
/*   By: Cervac Petru <petru.cervac@gmail.com>        ##     ##  ##  ##     ##   ##   ##   ##     */
/*                                                      :::::##::##::##:::::##:::##:::##:::##:::  */
/*                                                      :::::##::##::##:::::##::::##:##::::##:::  */
/*   Created: 2016/11/30 22:48:03 by Cervac                  ##  ##  ##     ##    ## ##    ##     */
/*   Updated: 2016/12/03 17:49:48 by Cervac Petru             ##    ##      ##     ###     ##     */
/*                                                              ####        ##      #      ##     */
/*                                                                                                */
/* ********************************************************************************************** */

#ifndef __CALENDAR_H__
# define __CALENDAR_H__

typedef struct	s_cal
{
	int			time;
	int			nr_cl;
	int			type;
}				t_cal;

void	add_even_cal(int time, int nr_cl, int type);
void	record_cal();
void	rem_even_cal();
void	rem_stop_cal();
void	record_cal_file(FILE *fp);
void	free_evn_cal();

#endif //__CALENDAR_H__