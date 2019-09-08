/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 22:52:51 by juochen           #+#    #+#             */
/*   Updated: 2018/04/19 22:52:56 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/dictionary.h"
# include <fcntl.h>
# include <limits.h>

# define QC (char *)qptr->content
# define BQC (char *)bfs->queue->content

typedef	struct	s_link
{
	char		*r1;
	char		*r2;
}				t_link;

typedef struct	s_bfs
{
	t_dict		**is_visit;
	t_dict		**pred;
	t_dict		**dis;
	t_list		*queue;
}				t_bfs;

typedef struct	s_ants
{
	int			nbr;
	t_list		*cur_room;
	int			route;
}				t_ants;

typedef struct	s_rank
{
	int			dist;
	t_list		*path;
	int			flow;
	int			is_open;
}				t_rank;

typedef	struct	s_room
{
	char		*name;
	int			x;
	int			y;
	t_list		*adlist;
	int			ad_num;
	int			is_occupy;
}				t_room;

typedef	struct	s_lem_in
{
	t_list		*flist;
	t_list		*rlist;
	t_list		*llist;
	char		*start_name;
	char		*end_name;
	int			ant_num;
	int			room_num;
	int			link_num;
	t_dict		**ad_dict;
	t_ants		*ants;
	int			rank_num;
	t_rank		**rank;
}				t_lem;

/*
**	read_farm.c
*/
int				read_farm(t_lem *lem);
int				check_farm(t_lem *lem);
/*
**	check_rooms.c
*/
t_list			*check_rooms(t_list *cur, t_lem *lem);
/*
**	check_links.c
*/
t_list			*check_links(t_list *cur, t_lem *lem);
/*
**	set_ad_dict.c
*/
int				set_ad_dict(t_lem *lem);
/*
**	find_shortest.c
*/
void			find_shortest(t_lem *lem);
void			find_shortest_from_start(t_lem *lem, t_room *sroom, int i);
/*
**	rank.c
*/
void			rank_route(t_lem *lem);
/*
**	turn.c
*/
int				turn(t_lem *lem, int ants_num);

#endif
