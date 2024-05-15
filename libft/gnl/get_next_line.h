/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaha <btaha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 02:49:43 by btaha             #+#    #+#             */
/*   Updated: 2023/01/23 02:49:44 by btaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1024
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

size_t	ft_strlen_utils(const char *s);
char	*ft_strchr_utils(char *s, int c);
char	*ft_strjoin_utils(char *s, char *buff);
char	*get_next_line(int fd);
char	*get_the_line(char *buffer);
char	*get_the_res(char *buffer);
char	*get_the_buffer(int fd, char *buffer);

#endif
