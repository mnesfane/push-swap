/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 02:49:23 by mnesfane          #+#    #+#             */
/*   Updated: 2022/04/05 05:38:56 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	maxposa(t_data *ptr)
{
	t_list *tmp;
	
	tmp = ptr->stack_top_a;
	ptr->point = 0;
	while (tmp != ptr->maxa)
	{
		ptr->point++;
		tmp = tmp->link;
	}
		// printf ("x%dx\n", ptr->point);
	return (ptr->point);
}

int	minposa(t_data *ptr)
{
	t_list *tmp;
	
	tmp = ptr->stack_top_a;
	ptr->pointam = 0;
	while (tmp != ptr->min)
	{
		ptr->pointam++;
		tmp = tmp->link;
	}
		// printf ("x%dx\n", ptr->point);
	return (ptr->pointam);
}

int  min(t_data *ptr)
{
	t_list *tmp;
	tmp = ptr->stack_top_a;
	ptr->min = tmp;
	while (tmp)
	{
		if (ptr->min->data > tmp->data)
		{
			ptr->min = tmp;
		}
		tmp = tmp->link;
	}
	return(ptr->min->data);
}

void	push_max(t_data *ptr)
{
	t_list *tmp;
	tmp = ptr->stack_top_a;
	
	max_a(ptr);
	maxposa(ptr);
	if (ptr->point <= 3)
		while (ptr->point)
		{
			ra(ptr);
			ptr->point--;
		}
	else
	{
		ptr->point = 5 - ptr->point;
		while (ptr->point)
	    {
	    	rra(ptr);
        	ptr->point--;
		}
	}
	pb(ptr);	
}

void	push_min(t_data *ptr)
{
	min(ptr);
	minposa(ptr);
	// printf ("%d", ptr->pointam);
	// exit (0);
	if (ptr->pointam <= 3)
    {
		while (ptr->pointam)
		{
			ra(ptr);
	        ptr->pointam--;
		}
    }
	else
	{
		ptr->pointam = 5 - ptr->pointam;
		while (ptr->pointam)
	    {
	        rra(ptr);
            ptr->pointam--;
		}
	}
	pb(ptr);	
}
        //printf ("k%dk", ptr->pointam);
        //exit(0);
        // if (ptr->pointam == 0)
		// 	rra(ptr);

int    sort_5(t_data *ptr)
{
	t_list *tmp;
	tmp = ptr->stack_top_a;

	push_min(ptr);
	push_min(ptr);
	// push_max(ptr);
    get_addr_end(ptr);
	sort_3(ptr);
	// return(pa(ptr), ra(ptr), pa(ptr), 0);
	return(pa(ptr), pa(ptr), 0);
}

int sort_3(t_data *ptr)
{   
	t_list *tmp;
	tmp = ptr->stack_top_a;

	if (bcheck_sort_stack(ptr) == 0)
		return (0);
	if(tmp->data == max_a(ptr))
	{
		if (ptr->stack_end_a->data == min(ptr))
			return(sa(ptr), rra(ptr), 0);
		else
			return(ra(ptr), 0);
	}
	if (tmp->link->data == max_a(ptr))
	{
		if (ptr->stack_end_a->data == min(ptr))
			return(rra(ptr), 0);
		else
			return(sa(ptr), ra(ptr), 0);
	}
	if(ptr->stack_end_a->data == max_a(ptr))
		return(sa(ptr), 0);
	return (0);
}
