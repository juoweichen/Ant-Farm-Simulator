/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 22:52:51 by juochen           #+#    #+#             */
/*   Updated: 2018/04/19 22:52:56 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_farm(t_lem *lem)
{
	t_list *ptr;

	ptr = lem->flist;
	while (ptr)
	{
		ft_putendl((char *)ptr->content);
		ptr = ptr->next;
	}
	ft_putchar('\n');
}

void	flow_placement(t_lem *lem)
{
	int i;
	int ri;

	i = 0;
	while (i < lem->ant_num)
	{
		ri = 0;
		while (ri < lem->rank_num)
		{
			if ((lem->rank[ri + 1] == NULL && lem->rank[ri]->dist != INT_MAX)
				|| (lem->rank[ri]->dist < lem->rank[ri + 1]->dist))
			{
				lem->rank[ri]->flow++;
				lem->rank[ri]->dist++;
				break ;
			}
			ri++;
		}
		i++;
	}
}

void	ants_warm_up(t_lem *lem)
{
	int i;
	int ri;

	lem->ants = (t_ants *)ft_memalloc(sizeof(t_ants) * lem->ant_num);
	i = 0;
	while (i < lem->ant_num)
	{
		ri = -1;
		while (++ri < lem->rank_num)
		{
			if (lem->rank[ri]->flow > 0)
			{
				lem->ants[i].nbr = i + 1;
				lem->ants[i].route = ri;
				lem->ants[i].cur_room = NULL;
				lem->rank[ri]->flow--;
				i++;
			}
		}
	}
}

void	ants_go(t_lem *lem)
{
	int		count;
	int		ants_num;

	ants_num = lem->ant_num;
	count = 0;
	while (++count)
		if ((ants_num = turn(lem, ants_num)) == 0)
			break ;
	ft_printf("turn: %d\n", count);
	exit(0);
}

int		main(void)
{
	t_lem	lem;

	ft_bzero((void *)&lem, sizeof(t_lem));
	lem.ad_dict = dict_create();
	if (!read_farm(&lem) || !check_farm(&lem) ||
		!ft_strcmp(lem.start_name, lem.end_name) || !set_ad_dict(&lem))
	{
		ft_printf("ERROR\n");
		exit(1);
	}
	rank_route(&lem);
	if (lem.rank_num == 0 || lem.rank[0]->dist == INT_MAX)
	{
		ft_printf("No possible solutions:(\n");
		exit(1);
	}
	print_farm(&lem);
	flow_placement(&lem);
	ants_warm_up(&lem);
	ants_go(&lem);
	return (0);
}
