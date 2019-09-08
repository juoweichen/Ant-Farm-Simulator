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

int		set_adlist(t_lem *lem, char *r1_name, char *r2_name)
{
	t_room	*r;
	t_list	*new;

	if ((r = (t_room *)dict_get(lem->ad_dict, r1_name)) == NULL ||
		dict_get(lem->ad_dict, r2_name) == NULL)
		return (-1);
	new = ft_lstnew(r2_name, ft_strlen(r2_name));
	if (r->adlist == NULL)
		r->adlist = new;
	else
		ft_lstadd(&r->adlist, new);
	r->ad_num++;
	return (1);
}

int		link_ad_dict(t_lem *lem)
{
	t_list	*lptr;

	lptr = lem->llist;
	while (lptr)
	{
		if (!set_adlist(lem, ((t_link *)lptr->content)->r1,
			((t_link *)lptr->content)->r2))
			return (-1);
		if (!set_adlist(lem, ((t_link *)lptr->content)->r2,
			((t_link *)lptr->content)->r1))
			return (-1);
		lptr = lptr->next;
	}
	return (1);
}

int		set_ad_dict(t_lem *lem)
{
	t_list	*rptr;

	rptr = lem->rlist;
	while (rptr)
	{
		dict_add(lem->ad_dict, ((t_room *)rptr->content)->name,
			(t_room *)rptr->content, sizeof(t_room));
		rptr = rptr->next;
	}
	if (!link_ad_dict(lem))
		return (-1);
	return (1);
}
