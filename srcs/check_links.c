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

void	store_link(t_lem *lem, t_link *new_link)
{
	t_list *ptr;

	ptr = ft_lstnew((void *)new_link, sizeof(t_link));
	if (lem->llist == NULL)
		lem->llist = ptr;
	else
		ft_lstaddend(&lem->llist, ptr);
}

int		check_link(t_lem *lem, t_list *cur)
{
	char	**split;
	t_link	new_link;

	if (cur == NULL || ft_words_count((char *)cur->content, '-') != 2)
		return (-1);
	split = ft_strsplit(cur->content, '-');
	if (split[0] && split[1] && !split[2])
	{
		new_link.r1 = ft_strdup(split[0]);
		new_link.r2 = ft_strdup(split[1]);
		store_link(lem, &new_link);
		lem->link_num++;
		ft_mstrdel_rows(&split, 2);
		return (1);
	}
	ft_mstrdel_norows(&split);
	return (-1);
}

t_list	*check_links(t_list *cur, t_lem *lem)
{
	while (cur)
	{
		if (ft_strchr((char *)cur->content, '-'))
			if (check_link(lem, cur) == -1)
				break ;
		cur = cur->next;
	}
	return (cur);
}
