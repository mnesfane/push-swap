/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:03:29 by mnesfane          #+#    #+#             */
/*   Updated: 2022/04/05 23:38:44 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	long	sing;
	long	ok;
	long	i;

	ok = 0;
	i = 0;
	sing = 1;
	if (str[i] == '-')
		sing = -1 ;
	if ((str[i] == '-' || str[i] == '+')  && (str[i + 1] == '0' || str[i + 1] == '1' ||
			str[i + 1] == '2' || str[i + 1] == '3' || str[i  + 1] == '4' || str[i + 1] == '5' ||
			str[i + 1] == '6' || str[i + 1] == '7' || str[i + 1] == '8' || str[i + 1] == '9'))
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			ok = (ok * 10) + str[i] - 48;
		else
		{
			write(2, "Error\n", 6);
			exit (0);
		}
		i++;
	}
	if ((ok * sing) > 2147483647 || (ok * sing) < -2147483648)
	{
		write(2, "Erroppr\n", 6);
		exit (0);
	}
	return (ok * sing);
}

void	*ft_memset(void *str, int c, size_t len)
{
	char	*p;

	p = str;
	while (len-- > 0)
	{
		*p = c;
		p++;
	}
	return (str);
}

void	*ft_calloc(size_t nitems, size_t sizeitems)
{
	char			*ptr;
	char			*p;
	unsigned int	k;

	k = nitems * sizeitems;
	ptr = malloc(k);
	if (ptr == 0)
	{
		free (ptr);
		return (NULL);
	}
	ft_memset(ptr, 0, k);
	free (ptr);
	return (ptr)
}

static void	ft_free(char **str, int k)
{
	while (k--)
		free(str[k]);
	free(str);
}

static char	**subsrtings(char **str, char const *s, char c, int count)
{
	int	len;
	int	k;
	int	i;

	i = 0;
	len = 0;
	k = 0;
	while (s[i] && k < count)
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			len++;
		}
		str[k++] = (char *)ft_calloc(sizeof(char), (len + 1));
		len = 0;
	}
	if (k > 0 && !str[k - 1])
	{
		ft_free(str, k - 1);
		return (0);
	}
	return (str);
}

int	wdc(char const *s, char c)
{
	int	wdc;
	int	i;

	i = 0;
	wdc = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			wdc++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (wdc);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**str;
	int		len;
	int		k;
	int		j;

	i = 0;
	k = 0;
	j = -1;
	if (s == NULL)
		return (NULL);
	len = wdc(s, c);
	str = (char **)ft_calloc(sizeof(char *), (len + 1));
	if (!str)
		return (NULL);
	subsrtings(str, s, c, len);
	while (s[i] && j + 1 < len)
	{
		if (s[i] != c && ++j >= 0)
			while (s[i] != c && s[i])
				str[j][k++] = s[i++];
		while (s[i] == c && s[i++])
			k = 0;
	}
	return (str);
}

int	bcheck_sort_stack(t_data *ptr)
{
	ptr->lenb =0;
	ptr->lena =0;
	t_list *tmp;
	tmp = ptr->stack_top_a;
	while(tmp)
	{
		ptr->lena++;
		tmp = tmp->link;
	}
	tmp = ptr->stack_top_a;
	while(tmp->link)
	{
		if (tmp->data < tmp->link->data)
			ptr->lenb++;
		tmp = tmp->link;
	}
	if ((ptr->lena - 1) == ptr->lenb)
		return (0);
	return (1);
}
void	check_sort_stack(t_data *ptr)
{
	ptr->lenb =0;
	ptr->lena =0;
	t_list *tmp;
	tmp = ptr->stack_top_a;
	while(tmp)
	{
		ptr->lena++;
		tmp = tmp->link;
	}
	tmp = ptr->stack_top_a;
	while(tmp->link)
	{
		if (tmp->data < tmp->link->data)
			ptr->lenb++;
		tmp = tmp->link;
	}
	if ((ptr->lena - 1) == ptr->lenb)
		exit(0);
}

int	scheck_sort_stack(t_data *ptr)
{
	if (ptr->stack_top_a)
	{	
		ptr->lenb =0;
		ptr->lena =0;
		t_list *tmp;
		tmp = ptr->stack_top_a;
		while(tmp)
		{
			ptr->lena++;
			tmp = tmp->link;
		}
		tmp = ptr->stack_top_a;
		while(tmp->link)
		{
			if (tmp->data < tmp->link->data)
				ptr->lenb++;
			tmp = tmp->link;
		}
		if ((ptr->lena - 1) == ptr->lenb)
			return(0);
	}
	return(1);
}

int ft_strncmp(char *s1, char *s2, int n)
{
    int i;

    i = 0;
    while ((s1[i] || s2[i]) && i < n)
    {
        if (s1[i] != s2[i])
        return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        i++;
    }
    return (0);
}

void	get_addr_end(t_data *ptr)
{
	t_list *tmp;

	tmp = ptr->stack_top_a;
	while (tmp->link)
		tmp = tmp->link;
	ptr->stack_end_a = tmp;
}

int	get_len_A(t_data *ptr)
{
	int i;
	t_list	*tmp;

	i = 0;

	tmp = ptr->stack_top_a;
	while (tmp)
	{
		i ++;
		tmp = tmp->link;
	}
	return (i);
}

void	decide_sort(t_data *ptr)
{
	if (get_len_A(ptr) == 2)
	{
		sa(ptr);
		exit(0);
	}
	else if (get_len_A(ptr) == 5)
	{
		sort_5(ptr);
		exit (0);
	}
	else if (get_len_A(ptr) == 3)
	{
		sort_3(ptr);
		exit(0);
	}
	else if (get_len_A(ptr) == 500)
	{
		ptr->decide = 10;
		ptr->decide2 = 4;
	}
	else
	{
		ptr->decide = 3;
		ptr->decide2 = 2;
	}
}