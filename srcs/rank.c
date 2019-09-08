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

void	block_this_path(t_lem *lem, int i)
{
	t_list *pptr;
	t_room *block_room;

	pptr = lem->rank[i]->path;
	while (pptr)
	{
		block_room = dict_get(lem->ad_dict, (char *)pptr->content);
		block_room->is_occupy = 1;
		pptr = pptr->next;
	}
}

void	rank_route(t_lem *lem)
{
	t_room	*sroom;
	int		i;

	sroom = dict_get(lem->ad_dict, lem->start_name);
	lem->rank_num = 0;
	lem->rank = (t_rank **)ft_memalloc(sizeof(t_rank *) * sroom->ad_num);
	i = 0;
	while (i < sroom->ad_num)
	{
		find_shortest_from_start(lem, sroom, i);
		lem->rank_num++;
		if (lem->rank[i]->dist == INT_MAX)
			return ;
		block_this_path(lem, i++);
	}
}
