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

void	store_room(t_lem *lem, t_room *new_room, char type)
{
	t_list *ptr;

	ptr = ft_lstnew((void *)new_room, sizeof(t_room));
	if (type == 's')
		lem->start_name = new_room->name;
	if (type == 'e')
		lem->end_name = new_room->name;
	if (lem->rlist == NULL)
		lem->rlist = ptr;
	else
		ft_lstaddend(&lem->rlist, ptr);
}

void	set_room(t_room *new_room, char **split)
{
	new_room->name = ft_strdup(split[0]);
	new_room->x = ft_atoi(split[1]);
	new_room->y = ft_atoi(split[2]);
	new_room->adlist = NULL;
	new_room->ad_num = 0;
	new_room->is_occupy = 0;
}

t_list	*check_room(t_lem *lem, t_list *cur, char type)
{
	char	**split;
	t_room	new_room;

	if (cur == NULL || ft_words_count((char *)cur->content, ' ') != 3)
		return (NULL);
	split = ft_strsplit(cur->content, ' ');
	if (split[0] && !ft_strchr(split[0], '-') &&
		split[1] && ft_isdigit_str(split[1]) &&
		split[2] && ft_isdigit_str(split[2]) && split[3] == NULL)
	{
		set_room(&new_room, split);
		store_room(lem, &new_room, type);
		lem->room_num++;
		ft_mstrdel_rows(&split, 3);
		return (cur);
	}
	return (NULL);
}

t_list	*check_rooms(t_list *cur, t_lem *lem)
{
	while (cur)
	{
		if (*(char *)cur->content == '#')
		{
			if (!ft_strcmp((char *)cur->content, "##start") && !lem->start_name)
				if (!check_room(lem, cur->next, 's'))
					return (NULL);
			if (!ft_strcmp((char *)cur->content, "##end") && !lem->end_name)
				if (!check_room(lem, cur->next, 'e'))
					return (NULL);
			if (!ft_strcmp((char *)cur->content, "##start") ||
				!ft_strcmp((char *)cur->content, "##end"))
				cur = cur->next;
		}
		else if (*(char *)cur->content == 'L')
			return (NULL);
		else
		{
			if (ft_strchr((char *)cur->content, '-') ||
				(cur = check_room(lem, cur, 'r')) == NULL)
				return (cur);
		}
		cur = cur->next;
	}
	return (NULL);
}
