/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 21:59:03 by juochen           #+#    #+#             */
/*   Updated: 2018/09/12 08:16:06 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mstrdel_norows(char ***mstr)
{
	int count;
	int i;

	if (mstr == NULL)
		return ;
	count = 0;
	while (*mstr[count])
		count++;
	i = 0;
	while (i < count)
		ft_strdel(&(*mstr)[i++]);
	ft_memdel((void **)mstr);
}
