/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 00:55:47 by mhanda            #+#    #+#             */
/*   Updated: 2022/04/04 02:41:18 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# define BUFFER_SIZE 1

#include"push_swap.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int	scheck_sort_stack(t_data *ptr);
char	*ft_strdup(char *str);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
int		gft_strlen(char *c);
char	*gft_strjoin(char *s1, char *s2);
char	*get_line( char *line);
void    bmainn(t_jj j, t_data *data, int ac, char **av);
#endif