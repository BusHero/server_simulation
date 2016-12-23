/* ********************************************************************************************** */
/*                                                                                                */
/*                                                        ################  ###           ###     */
/*                                                        ################  ####         ####     */
/*   tail.h                                                      ##         ## ##       ## ##     */
/*                                                      #######  ##  ###### ##  ## ### ##  ## ##  */
/*                                                     ########  ##  ###### ##  ##  #  ##  ## ##  */
/*   By: Cervac Petru <petru.cervac@gmail.com>        ##     ##  ##  ##     ##   ##   ##   ##     */
/*                                                      :::::##::##::##:::::##:::##:::##:::##:::  */
/*                                                      :::::##::##::##:::::##::::##:##::::##:::  */
/*   Created: 2016/11/23 00:23:42 by Cervac                  ##  ##  ##     ##    ## ##    ##     */
/*   Updated: 2016/11/30 00:33:19 by Cervac Petru             ##    ##      ##     ###     ##     */
/*                                                              ####        ##      #      ##     */
/*                                                                                                */
/* ********************************************************************************************** */

#ifndef __TAIL_H__
# define __TAIL_H__

typedef struct		s_node
{
	void			*inf;
	int				time;
	struct s_node	*next;
}					t_node;

t_node	*new_node(void *inf, int time);
void	add_node(t_node **end, t_node *new);
t_node	*rem_node(t_node **root);
int		getnr_node(t_node *root);
void	rem_tail(t_node **root);
void	add_asc_node(t_node **root, t_node *new);

#endif //__TAIL_H__