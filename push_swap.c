/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 04:25:53 by mhanda            #+#    #+#             */
/*   Updated: 2022/04/05 23:10:57 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// one arg segment./ max min int if sort do notghin

int main(int ac, char **av) // min max, head mhanda , args fihum char abc, - or + bla numb
{
	t_jj j;
	t_data data;
	
	j.f = 0;
	data.stack_top_b = NULL;
	data.stack_top_a = NULL;
	mainn(j, &data, ac, av);
	check_sort_stack(&data);
	decide_sort(&data);
	sateff(&data);
	while (data.stack_top_a->link != NULL)
	{
		compair(&data);	
		laod_stack_tmp(&data);
	}
	max(&data);
	maxpos(&data);
	push_to_a(&data);
	while (1);
	return (0);
}