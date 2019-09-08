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

void	send_new_ants(t_lem *lem, int i)
{
	int		j;

	j = 0;
	while (j < lem->rank_num && i + j < lem->ant_num)
	{
		if (lem->rank[lem->ants[i + j].route]->is_open == 0)
			return ;
		lem->ants[i + j].cur_room =
			lem->rank[lem->ants[i + j].route]->path->next;
		ft_printf("L%d-%s ", lem->ants[i + j].nbr,
			(char *)lem->ants[i + j].cur_room->content);
		lem->rank[lem->ants[i + j].route]->is_open = 0;
		j++;
	}
}

int		ants_forward(t_lem *lem, int i, int ants_num)
{
	lem->rank[lem->ants[i].route]->is_open = 1;
	lem->ants[i].cur_room = lem->ants[i].cur_room->next;
	if (lem->ants[i].cur_room == NULL)
	{
		ft_printf("L%d-%s ", lem->ants[i].nbr, lem->end_name);
		lem->ants[i].nbr = 0;
		ants_num--;
	}
	else
		ft_printf("L%d-%s ", lem->ants[i].nbr,
			(char *)lem->ants[i].cur_room->content);
	return (ants_num);
}

int		turn(t_lem *lem, int ants_num)
{
	int		i;

	i = -1;
	while (++i < lem->ant_num)
	{
		if (lem->ants[i].nbr == 0)
			continue ;
		if (lem->ants[i].cur_room != NULL)
			ants_num = ants_forward(lem, i, ants_num);
		else
		{
			send_new_ants(lem, i);
			break ;
		}
		if (ants_num == 0)
			break ;
	}
	ft_printf("\n");
	return (ants_num);
}
