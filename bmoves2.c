/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmoves2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:48:16 by mnesfane          #+#    #+#             */
/*   Updated: 2022/04/03 23:50:16 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void bsrb(t_data *ptr)
{
	if (ptr->stack_top_b && ptr->stack_top_b->link)
	{
		t_list *temp;
		t_list *temp2;
		
		temp = ptr->stack_top_b;
		ptr->stack_top_b = ptr->stack_top_b->link;
		temp2 = ptr->stack_top_b;
		// free(ptr->stack_top_b);
		while(ptr->stack_top_b->link)
			ptr->stack_top_b = ptr->stack_top_b->link;
		ptr->stack_top_b->link = temp;
		ptr->stack_top_b = temp2;
		temp->link = NULL;

		// printf("------------- stack b rb ---------------\n");
		// temp = ptr->stack_top_b;
		// while(temp)
		// {
		// 	printf("%d\n",temp->data);
		// 	temp = temp->link;
		// }
	}
}

void srra(t_data *ptr)
{
	if (ptr->stack_top_a && ptr->stack_top_a->link)
	{
		t_list *temp;
		
		temp = ptr->stack_top_a;
		if (temp->link)
		{
			while(temp->link->link)
				temp = temp->link;
			temp->link->link = ptr->stack_top_a;
			ptr->stack_top_a = temp->link;
			temp->link = NULL;
		}
		
		// printf("------------- stack ab rra ---------------\n");
		// temp = ptr->stack_top_a;
		// while(temp)
		// {
		// 	printf("%d\n",temp->data);
		// 	temp = temp->link;
		// }
	}
}


void srrb(t_data *ptr)
{
	if (ptr->stack_top_b && ptr->stack_top_b->link)
	{
		t_list *temp;
		temp = ptr->stack_top_b;
		if (temp->link)
		{
			while(temp->link->link)
				temp = temp->link;
			temp->link->link = ptr->stack_top_b;
			ptr->stack_top_b = temp->link;
			temp->link = NULL;
		}
		
		// printf("------------- stack ab rrb ---------------\n");
		// temp = ptr->stack_top_b;
		// while(temp)
		// {
		// 	printf("%d\n",temp->data);
		// 	temp = temp->link;
		// }
	}
}