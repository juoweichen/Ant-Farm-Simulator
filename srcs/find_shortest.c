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

void	run_bfs(t_lem *lem, t_bfs *bfs, t_room *room)
{
	int		v;
	t_list	*qptr;

	while (bfs->queue != NULL)
	{
		qptr = bfs->queue;
		bfs->queue = bfs->queue->next;
		ft_lstdelone(&qptr, ft_lstdel_content);
		qptr = room->adlist;
		while (qptr)
		{
			if (*(int *)dict_get(bfs->is_visit, QC) == 0)
			{
				v = 1;
				dict_add(bfs->is_visit, QC, &v, sizeof(int));
				dict_add(bfs->pred, QC, room->name, sizeof(char *));
				v = *(int *)dict_get(bfs->dis, room->name) + 1;
				dict_add(bfs->dis, QC, &v, sizeof(int));
				ft_lstaddend(&bfs->queue, ft_lstnew(QC, ft_strlen(QC)));
			}
			qptr = qptr->next;
		}
		if (bfs->queue != NULL)
			run_bfs(lem, bfs, dict_get(lem->ad_dict, BQC));
	}
}

void	empty_dict_isvisit_and_pred(t_lem *lem, t_bfs *bfs)
{
	t_list	*rptr;
	int		v;
	int		m;
	t_room	*room;

	v = 0;
	m = INT_MAX;
	rptr = lem->rlist;
	while (rptr)
	{
		room = dict_get(lem->ad_dict, ((t_room *)rptr->content)->name);
		if (room->is_occupy == 0)
			dict_add(bfs->is_visit, ((t_room *)rptr->content)->name,
				&v, sizeof(int));
		else
			dict_add(bfs->is_visit, ((t_room *)rptr->content)->name,
				&m, sizeof(int));
		dict_add(bfs->pred, ((t_room *)rptr->content)->name,
			"L", sizeof(char *));
		dict_add(bfs->dis, ((t_room *)rptr->content)->name,
			&m, sizeof(int));
		rptr = rptr->next;
	}
	v = 1;
	dict_add(bfs->is_visit, lem->start_name, &v, sizeof(int));
}

void	init_bfs(t_lem *lem, t_bfs *bfs)
{
	bfs->is_visit = dict_create();
	bfs->pred = dict_create();
	bfs->dis = dict_create();
	bfs->queue = NULL;
	empty_dict_isvisit_and_pred(lem, bfs);
}

void	store_shorest_path(t_lem *lem, t_bfs *bfs, int i)
{
	char *pred_name;

	lem->rank[i] = (t_rank *)ft_memalloc(sizeof(t_rank));
	lem->rank[i]->dist = *(int *)dict_get(bfs->dis, lem->end_name);
	pred_name = (char *)dict_get(bfs->pred, lem->end_name);
	lem->rank[i]->path = ft_lstnew(pred_name, ft_strlen(pred_name));
	while ((pred_name = (char *)dict_get(bfs->pred, pred_name)))
	{
		if (ft_strncmp(pred_name, "L", 1))
			ft_lstadd(&lem->rank[i]->path, ft_lstnew(pred_name,
				ft_strlen(pred_name)));
	}
	lem->rank[i]->is_open = 1;
	lem->rank[i]->flow = 0;
}

void	find_shortest_from_start(t_lem *lem, t_room *sroom, int i)
{
	t_bfs	bfs;
	int		v;

	init_bfs(lem, &bfs);
	v = 1;
	dict_add(bfs.is_visit, sroom->name, &v, sizeof(int));
	bfs.queue = ft_lstnew(sroom->name, ft_strlen(sroom->name));
	v = 0;
	dict_add(bfs.dis, sroom->name, &v, sizeof(int));
	run_bfs(lem, &bfs, sroom);
	store_shorest_path(lem, &bfs, i);
	dict_destory(&bfs.is_visit);
	dict_destory(&bfs.pred);
	dict_destory(&bfs.dis);
}
