/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 07:42:54 by mnesfane          #+#    #+#             */
/*   Updated: 2022/04/04 08:00:43 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	idk(t_jj j, t_data *data, char **av)
{
	j.str = malloc(1);
	j.str[0] = '\0';
	while (av[j.i])
	{
		if (emty_str(av[j.i]) == 0)
			exit (0);
		j.g = ft_strjoin(j.str, av[j.i]);
		free(j.str);
		j.str = ft_strjoin(j.g, " ");
		free(j.g);
		j.i++;
	}
	j.split = ft_split(j.str, ' ');
	free(j.str);
	j.node = malloc(sizeof(t_list));
	j.satef = malloc(sizeof(t_list));
	data->stack_top_a = j.node;
	data->tmp_sort = j.satef;
	load_to_a(&j, data);
}

void	load_to_a(t_jj *j, t_data *data)
{
	j->ptr = j->node;
	j->i = 0;
	while (j->split[j->j])
	{
		j->node->data = ft_atoi(j->split[j->j]);
		j->satef->data = ft_atoi(j->split[j->j]);
		j->node->link = NULL;
		j->satef->link = NULL;
		j->j++;
		if (j->split[j->j])
		{
			j->node->link = malloc(sizeof(t_list));
			j->satef->link = malloc(sizeof(t_list));
			j->node = j->node->link;
			j->satef = j->satef->link;
		}
		free (j->split[j->j]);
	}
	free(j->split);
	data->stack_end_a = j->node;
	j->node = j->ptr;
	data->pr = j->ptr;
	j->i = 0;
	j->k = 1;
}
void	sidk(t_jj j, t_data *data, char **av)
{
	j.str = malloc(1);
	j.str[0] = '\0';
	while (av[j.i])
	{
		if (emty_str(av[j.i]) == 0)
			exit (0);
		j.g = ft_strjoin(j.str, av[j.i]);
		free(j.str);
		j.str = ft_strjoin(j.g, " ");
		free(j.g);
		j.i++;
	}
	j.split = ft_split(j.str, ' ');
	free(j.str);
	j.node = malloc(sizeof(t_list));
	data->stack_top_a = j.node;
	sload_to_a(&j, data);
}

void	sload_to_a(t_jj *j, t_data *data)
{
	j->ptr = j->node;
	j->i = 0;
	while (j->split[j->j])
	{
		j->node->data = ft_atoi(j->split[j->j]);
		j->node->link = NULL;
		j->j++;
		if (j->split[j->j])
		{
			j->node->link = malloc(sizeof(t_list));
			j->node = j->node->link;
		}
		free (j->split[j->j]);
	}
	free(j->split);
	data->stack_end_a = j->node;
	j->node = j->ptr;
	data->pr = j->ptr;
	j->i = 0;
	j->k = 1;
}

void	intcmp(t_jj *j, t_data *data)
{
	j->node = data->pr;
	while (data->pr != NULL)
	{
		while (j->node->link != NULL)
		{
			if (ft_intcmp(&data->pr->data, &j->node->link->data) == 0)
			{
				write(1, "wrong", 5);
				exit(0);
			}
			j->node = j->node->link;
		}
		data->pr = data->pr->link;
		j->node = data->pr;
	}
}


void	mainn(t_jj j, t_data *data, int ac, char **av)
{
	j.i = 1;
	j.f = 0;
	j.j = 0;
	if (ac <= 1)
		exit (0);
	idk(j, data, av);
	if (data->stack_top_a->link == NULL)
	{
		free(j.node);
		free(j.satef);
		exit(0);
	}
	intcmp(&j, data);
}

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	// if (!c)
	// 	return (0);
	while (c[i] != 0)
	{
		i++;
	}
	return (i);
}

int	ft_intcmp(int *s1, int *s2)
{
	if (*s1 == *s2)
		return (0);
	return (1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*p;
	int		len;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	while (*s1)
		p[i++] = *s1++;
	while (*s2)
		p[i++] = *s2++;
	p[i] = '\0';
	return (p);
}

int emty_str(char *str)
{
	int i, k;
	
	i = 0 ;
	k = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			k++;
		i++;
	}
	if (k == i)
		return (write(2, "Error", 5), 0);
	else
		return (1);
}

void	double_mouve_ss_rr_rrr(t_data *ptr, int num)
{
	if (num == 0)
	{
		ssa(ptr);
		ssb(ptr);
		write(1, "ss\n", 3);
	}
	if (num == 1)
	{
		srb(ptr);
		sra(ptr);
		write(1, "rr\n", 3);
	}
	if (num == 2)
	{
		srra(ptr);
		srrb(ptr);
		write(1, "rrr\n", 4);
	}
}

void	sateff(t_data *ptr)
{
	t_var var;
	// t_list *tmp;
	t_list *tmp1;
	// t_list *temp;
	t_list *temp2;
	
	var.i = 0;
	var.len = 0;
	var.j = 0;
	tmp1 = ptr->tmp_sort;
	temp2 = ptr->tmp_sort;
	while(ptr->tmp_sort)
	{
		ptr->tmp_sort = ptr->tmp_sort->link;
		var.len ++;
	}
	int dd;

	dd = 0;
	var.len = var.len;
	while(var.len)
	{
		ptr->tmp_sort = tmp1;
		while (ptr->tmp_sort->link) 
		{
			if (ptr->tmp_sort->data > ptr->tmp_sort->link->data)
			{
				dd = ptr->tmp_sort->data;
				ptr->tmp_sort->data = ptr->tmp_sort->link->data;
				ptr->tmp_sort->link->data = dd;
			}
			ptr->tmp_sort = ptr->tmp_sort->link;
		}
		var.len--;
	}
	
	// ptr->tmp_sort = temp2;
	
	// printf("------------- sort ---------------\n");
	// while(ptr->tmp_sort)
	// {
		
	// 	printf("%d\n",ptr->tmp_sort->data);
	// 	ptr->tmp_sort = ptr->tmp_sort->link;
	// }
	ptr->tmp_sort = temp2;
}
