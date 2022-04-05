/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 01:32:07 by mnesfane          #+#    #+#             */
/*   Updated: 2022/04/04 02:55:15 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"


void	bmainn(t_jj j, t_data *data, int ac, char **av)
{
	j.i = 1;
	j.f = 0;
	j.j = 0;
	if (ac <= 1)
		exit (0);
	sidk(j, data, av);
	if (data->stack_top_a->link == NULL)
	{
		free(j.node);
		free(j.satef);
		exit(0);
	}
	intcmp(&j, data);
}

void	instructions_and_execute(char *str, t_data *ptr)
{
	if (!ft_strncmp(str, "sa\n", 3))
		ssa(ptr);
	else if (!ft_strncmp(str, "sb\n", 3))
		ssb(ptr);
	else if (!ft_strncmp(str, "ss\n", 3))
		double_mouve_ss_rr_rrr(ptr, 0);
	else if (!ft_strncmp(str, "pa\n", 3))
		spa(ptr);
	else if (!ft_strncmp(str, "pb\n", 3))
		spb(ptr);
	else if (!ft_strncmp(str, "ra\n", 3))
		sra(ptr);
	else if (!ft_strncmp(str, "rb\n", 3))
		srb(ptr);
	else if (!ft_strncmp(str, "rr\n", 3))// && ptr->stack_top_b;
		double_mouve_ss_rr_rrr(ptr, 1);
	else if (!ft_strncmp(str, "rra\n", 4))
		srra(ptr);
	else if (!ft_strncmp(str, "rrb\n", 4))
		srrb(ptr);
	else if (!ft_strncmp(str, "rrr\n", 4))
		double_mouve_ss_rr_rrr(ptr, 2);
	else
		write(2, "Error\n", 6);
}

void check_ok_ko(t_data *ptr)
{
	if((scheck_sort_stack(ptr) == 0) && !ptr->stack_top_b)
	{
		write(1, "OK", 2);
		// free(ptr->stack_top_a);
		// exit(0);
		return ;
	}
	else
	{
		write(1, "KO", 2);
		// free(ptr->stack_top_a);
		// exit(0);
		return ;
	}
}

int main(int ac, char **av)
{
	t_jj 	j;
	t_data 	data;
	char	*str;
	
	j.i = 0;
	data.stack_top_b = NULL;
	data.stack_top_a = NULL;
	if (ac >= 2)
	{
		bmainn(j, &data, ac, av);
		str = get_next_line(0);
		while (str)
		{
			instructions_and_execute(str, &data);
			str = get_next_line(0);
		}
		
	}
	check_ok_ko(&data);
}
// jamill