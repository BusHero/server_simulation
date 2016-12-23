/* ********************************************************************************************** */
/*                                                                                                */
/*                                                        ################  ###           ###     */
/*   main2.c                                                     ##         ## ##       ## ##     */
/*                                                      #######  ##  ###### ##  ## ### ##  ## ##  */
/*                                                     ########  ##  ###### ##  ##  #  ##  ## ##  */
/*   By: Cervac Petru <petru.cervac@gmail.com>        ##     ##  ##  ##     ##   ##   ##   ##     */
/*                                                      :::::##::##::##:::::##:::##:::##:::##:::  */
/*                                                      :::::##::##::##:::::##::::##:##::::##:::  */
/*   Created: 2016/11/24 23:33:27 by Cervac                  ##  ##  ##     ##    ## ##    ##     */
/*   Updated: 2016/12/04 00:17:15 by Cervac Petru             ##    ##      ##     ###     ##     */
/*                                                              ####        ##      #      ##     */
/*                                                                                                */
/* ********************************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dem.h"
#include "calendar.h"
#include "servers.h"

static int		st_nr_cl = 0;
static int		Nq = 0;
static int		tq = 0;
static int		Toc = 0;
static t_dem	null_dem = {0, 0, 0};

void	record_event_file(
	FILE *fp,
	int time,
	int type,
	t_dem dem,
	int tail_size,
	int serv_state,
	int rest)
{
	static int	nr = 0;
	char		even[4][6] = {"START", "p", "s", "STOP"};

	if (rest)
		nr = 0;
	if (nr == 0)
	{
		fprintf(fp, "nr_even\t|ceasul\t|client\t|tipul\t|coada\t|starea\t|Toc\t|tq\t|Nq\t|calendar\n");
	}
	fprintf(fp, "%d\t|", nr);
	fprintf(fp, "%d\t|", time);
	if (!dem.nr_cl)
		fprintf(fp, "-\t|");
	else
		fprintf(fp, "%d\t|", dem.nr_cl);
	fprintf(fp, "%s\t|", even[type]);
	fprintf(fp, "%d\t|", tail_size);
	fprintf(fp, "%d\t|", serv_state);
	fprintf(fp, "%d\t|", Toc);
	fprintf(fp, "%d\t|", tq);
	fprintf(fp, "%d\t|", Nq);
	record_cal_file(fp);
	nr++;
}

void	record_event(
	int time,
	int type,
	t_dem dem,
	int tail_size,
	int serv_state,
	int rest)
{
	static int	nr = 0;
	char		even[4][6] = {"START", "p", "s", "STOP"};
	
	if (rest)
		nr = 0;
	if (nr == 0)
	{
		printf("nr_even\t|ceasul\t|client\t|tipul\t|coada\t|starea\t|Toc\t|tq\t|Nq\t|calendar\n");
	}
	printf("%d\t|", nr);
	printf("%d\t|", time);
	if (!dem.nr_cl)
		printf("-\t|");
	else
		printf("%d\t|", dem.nr_cl);
	printf("%s\t|", even[type]);
	printf("%d\t|", tail_size);
	printf("%d\t|", serv_state);
	printf("%d\t|", Toc);
	printf("%d\t|", tq);
	printf("%d\t|", Nq);
	record_cal();
	nr++;
}

t_dem	create_dem(
	int nr,
	t_client client,
	int res)
{
	t_dem		new;

	new.nr_cl = nr;
	new.arv_tm = client.arv_per;
	new.des_tm = client.des_per;

	if (res)
		new.arv_tm++;
	return (new);
}

int 	do_simulation(
	char *file,
	t_client *client,
	int nr_ser)
{
	int		time = 0;
	int		nr_client = 0;
	t_dem	next_dem = create_dem(1, client[0], 1);
	t_dem	rem_dem;
	FILE	*fp;
	int		stop = 0;
	int		max = 0;

	Nq = 0;
	tq = 0;
	Toc = 0;
	set_nr_serv(nr_ser);
	fp = fopen(file, "w");
	add_even_cal(client[0].arv_per, 1, 2);
	record_event_file(fp, 0, 0, null_dem, 0, 0, 1);
	// record_event(0, 0, null_dem, 0, 0, 1);
	while ((is_dem_tail() || nr_client != st_nr_cl || !get_free_server())
		&& !stop)
	{
		if (0 == (--next_dem.arv_tm) && nr_client < st_nr_cl)
		{
			if (0 != (nr_ser = get_free_server()))
			{
				add_even_cal(time + client[nr_client].des_per,
					nr_client + 1, 1);
				add_dem_server(nr_ser - 1, next_dem);
			}
			else
			{
				add_dem_tail(next_dem);
				if (get_size_tail() > max)
					max = get_size_tail();
			}
			rem_even_cal();
			if (nr_client != st_nr_cl - 1)
				add_even_cal(time + client[nr_client + 1].arv_per,
					nr_client + 2, 2);
			record_event_file(fp, time, 2, next_dem, get_size_tail(),
				get_usg_servers(), 0);
			// record_event(time, 2, next_dem, get_size_tail(), get_usg_servers(),
				// 0);
			nr_client++;
			next_dem = create_dem(nr_client + 1, client[nr_client], 0);
		}
		Toc += proc_dem_server();
		tq += get_size_tail();
		while ((0 != (nr_ser = get_free_server())))
		{
			rem_dem = get_dem_server(nr_ser - 1);
			if (rem_dem.nr_cl == 1000)
				stop = 1;
			rem_dem_server(nr_ser - 1);
			if (is_dem_tail())
			{
				Nq++;
				add_dem_server(nr_ser - 1, rem_dem_tail());
				add_even_cal(time + get_dem_server(nr_ser - 1).des_tm + 1,
					get_dem_server(nr_ser - 1).nr_cl, 1);
			}
			if (rem_dem.nr_cl != 0)
			{
				rem_even_cal();
				record_event_file(fp,time + 1, 1,
					rem_dem, get_size_tail(), get_usg_servers(), 0);
				// record_event(time + 1, 1,
					// rem_dem, get_size_tail(), get_usg_servers(), 0);
			}
			if (!is_dem_tail())
				break ;
		}
		time++;
	}
	fprintf(fp, "Durata integrala de ocupare a serverului: %d\n", Toc);
	fprintf(fp, "Gradul de utilizare a serverului: %f\n", 1.0 * Toc / time);
	fprintf(fp, "Lungimea maximala a cozii: %d\n", max);
	fprintf(fp, "Lungimea medie a firului de asteptare: %f\n", 1.0 * tq / time);
	fprintf(fp, "Retinerea medie a unui client in coada de asteptare: %f\n", 1.0 * tq / Nq);
	rem_stop_cal();
	free_dem_tail();
	free_servers();
	free_evn_cal();
	fclose(fp);
	return (0);
}

t_client	*read_file(const char *file)
{
	FILE		*fp;
	t_client	cl;
	t_client	*regs = NULL;

	if (NULL == (fp = fopen(file, "r")))
	{
		printf("Wrong file!!!");
		exit(1);
	}
	while (3 == fscanf(fp, "%d%d%d", &st_nr_cl, &cl.arv_per, &cl.des_per))
	{
		regs = realloc(regs, sizeof(t_client) * st_nr_cl);
		regs[st_nr_cl - 1] = cl;
	}
	return (regs);
}

int		main(int argc, char **argv)
{
	t_client	*dates;

	if (argc > 1)
	{
		dates = read_file(argv[1]);
		// 	// printf("%d\t%d\n", dates[i].arv_per, dates[i].des_per);
		do_simulation("rez1", dates, 1);
		printf("\n");
		do_simulation("rez2", dates, 2);
		free(dates);
	}
	else
		printf("usage:\narg[1] - fisierul de intrare\n");
	return (0);
}
