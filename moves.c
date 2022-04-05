/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 00:29:50 by mnesfane          #+#    #+#             */
/*   Updated: 2022/04/05 05:33:57 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pb(t_data *ptr)
{
	if (ptr->stack_top_a)
	{
		t_list *temp;
		// t_list *temp2;
		static int remind;
		if (ptr->stack_top_a != NULL)
		{
			if (remind == 0)
			{
				ptr->stack_top_b = ptr->stack_top_a;
				ptr->stack_top_a = ptr->stack_top_a->link;
				ptr->stack_top_b->link = NULL;
				remind ++;
			}
			else
			{
				temp = ptr->stack_top_b;
				ptr->stack_top_b = ptr->stack_top_a;
				ptr->stack_top_a = ptr->stack_top_a->link;
				ptr->stack_top_b->link = temp;
			}
		}
		// if (ptr->stack_top_b = NULL)
		// 	exit(0);
		
		// printf("------------- stack a ---------------\n");
		// temp = ptr->stack_top_a;
		// while(temp)
		// {
		// 	printf("%d\n",temp->data);
		// 	temp = temp->link;
		// }
		// printf("------------- stack b ---------------\n");
		// temp2 = ptr->stack_top_b;
		// while(temp2)
		// {
		// 	printf("%d\n",temp2->data);
		// 	temp2 = temp2->link;
		// }
		write(1, "pb\n", 3);
	}
}

void pa(t_data *ptr)
{
	if(ptr->stack_top_b)
	{
		t_list *temp;
		// t_list *temp2;
		
		if (ptr->stack_top_b != NULL)
		{	
			temp = ptr->stack_top_a;
			ptr->stack_top_a = ptr->stack_top_b;
			ptr->stack_top_b = ptr->stack_top_b->link;
			ptr->stack_top_a->link = temp;
		}
		// if (ptr->stack_top_a = NULL)
		// 	exit(0);

		// printf("\n------------- stack a ---------------\n");
		// temp = ptr->stack_top_a;
		// while(temp)
		// {
		// 	printf("%d\n",temp->data);
		// 	temp = temp->link;
		// }

		// printf("------------- stack b ---------------\n");
		// temp2 = ptr->stack_top_b;
		// while(temp2)
		// {
		// 	printf("%d\n",temp2->data);
		// 	temp2 = temp2->link;
		// }
		write(1, "pa\n", 3);
	}
}

void sa(t_data *ptr)
{
	if (ptr->stack_top_a && ptr->stack_top_a->link)
	{
		t_list *temp;
		t_list *temp2;
		temp2 = ptr->stack_top_a->link->link;
		temp = ptr->stack_top_a;
		ptr->stack_top_a = ptr->stack_top_a->link;
		ptr->stack_top_a->link = temp;
		ptr->stack_top_a->link->link = temp2;

		// printf("------------- stack a sa_sb swap ---------------\n");
		// temp = ptr->stack_top_a;
		// while(temp)
		// {
		// 	printf("%d\n",temp->data);
		// 	temp = temp->link;
		// }
		write(1, "sa\n", 3);
	}
}


void sb(t_data *ptr)
{
	if ( ptr->stack_top_b &&ptr->stack_top_b->link)
	{
		t_list *temp;
		t_list *temp2;
		temp2 = ptr->stack_top_b->link->link;
		temp = ptr->stack_top_b;
		ptr->stack_top_b = ptr->stack_top_b->link;
		ptr->stack_top_b->link = temp;
		ptr->stack_top_b->link->link = temp2;

		// free(stack_top_b);
		// printf("------------- stack a sa_sb swap ---------------\n");
		// temp = ptr->stack_top_b;
		// while(temp)
		// {
		// 	printf("%d\n",temp->data);
		// 	temp = temp->link;
		// }
		write(1, "sb\n", 3);
	}
}


void ra(t_data *ptr)
{

	if (ptr->stack_top_a && ptr->stack_top_a->link)
	{
		t_list *temp;
		t_list *temp2;
		
		temp = ptr->stack_top_a;
		ptr->stack_top_a = ptr->stack_top_a->link;
		temp2 = ptr->stack_top_a;
		// free(ptr->stack_top_a);
		while(ptr->stack_top_a->link)
			ptr->stack_top_a = ptr->stack_top_a->link;
		ptr->stack_top_a->link = temp;
		ptr->stack_top_a = temp2;
		temp->link = NULL;

		// printf("------------- stack a ra ---------------\n");
		// temp = ptr->stack_top_a;
		// while(temp)
		// {
		// 	printf("%d\n",temp->data);
		// 	temp = temp->link;
		// }
		write(1, "ra\n", 3);	
	}
}
