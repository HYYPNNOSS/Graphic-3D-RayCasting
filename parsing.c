/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaha <btaha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 22:10:51 by btaha             #+#    #+#             */
/*   Updated: 2023/01/24 00:49:40 by btaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_input(t_input *input)
{
	if (input->n)
		free(input->n);
	if (input->s)
		free(input->s);
	if (input->w)
		free(input->w);
	if (input->e)
		free(input->e);
	if (input->floor)
		free(input->floor);
	if (input->ceil)
		free(input->ceil);
	if (input->map)
		free_tab(input->map);
}

void	fill_rc(t_data *data)
{
	int	rows;
	int	cols;

	rows = 0;
	cols = ft_strlen(data->input->map[rows]);
	while (data->input->map[rows])
	{
		if (cols < (int)ft_strlen(data->input->map[rows]))
			cols = ft_strlen(data->input->map[rows]);
		rows++;
	}
	data->num_rows = rows;
	data->num_cols = cols;
}

char	*fill_line(char const *s, int len)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

int	check_empty(t_input *input)
{
	if (!input->n || !input->s || !input->e
		|| !input->w || !input->floor || !input->ceil)
		return (1);
	return (0);
}

int	longest_line(t_list *lst)
{
	int	len;

	len = ft_strlen((char *)lst->content);
	while (lst)
	{
		if (len < (int)ft_strlen((char *)lst->content))
			len = ft_strlen(lst->content);
		lst = lst->next;
	}
	return (len);
}
