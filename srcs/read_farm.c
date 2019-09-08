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

t_list	*check_ants_number(t_lem *lem)
{
	t_list *cur;

	lem->ant_num = 0;
	cur = lem->flist;
	while (cur)
	{
		if (ft_isdigit_str((char *)cur->content) &&
			ft_atoi((char *)cur->content) > 0)
		{
			lem->ant_num = ft_atoi((char *)cur->content);
			cur = cur->next;
			return (cur);
		}
		cur = cur->next;
	}
	return (NULL);
}

int		check_farm(t_lem *lem)
{
	t_list *cur;

	if ((cur = check_ants_number(lem)) == NULL)
		return (0);
	if ((cur = check_rooms(cur, lem)) == NULL)
		return (0);
	if ((cur = check_links(cur, lem)) != NULL)
		return (0);
	return ((lem->ant_num > 0 && lem->rlist && lem->llist &&
		lem->start_name && lem->end_name) ? 1 : 0);
}

int		read_farm(t_lem *lem)
{
	char	*line;

	while (get_next_line_sin(0, &line))
	{
		if (lem->flist == NULL)
			lem->flist = ft_lstnew(line, ft_strlen(line));
		else
			ft_lstaddend(&lem->flist, ft_lstnew(line, ft_strlen(line)));
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (1);
}
