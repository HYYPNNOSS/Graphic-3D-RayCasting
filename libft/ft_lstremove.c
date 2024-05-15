/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaha <btaha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:21:39 by btaha             #+#    #+#             */
/*   Updated: 2023/01/24 00:21:40 by btaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremove(t_list **lst, t_list *to_rm)
{
	t_list	*pre;
	t_list	*cur;

	pre = NULL;
	cur = *lst;
	while (cur)
	{
		if (cur == to_rm)
		{
			if (pre)
				pre->next = cur->next;
			else
				*lst = cur->next;
			return ;
		}
		pre = cur;
		cur = cur->next;
	}
}
