/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 03:07:22 by mhanda            #+#    #+#             */
/*   Updated: 2022/04/05 05:29:44 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int				data;
	int				pos;
	struct s_list	*link;
} t_list;

typedef struct s_var
{
	int k;
	int f;
	int i;
	int j;
	// int	dd;
	int len;
	int count;
} t_var;

typedef struct s_jj
{
	int 	k;
	int 	f;
	int 	i;
	int 	j;
	char	*g;
	char	*str;
	char	**split;
	t_list	*node;
	t_list	*satef;
	t_list	*ptr;
} t_jj;

typedef struct s_jme3
{
	int		i;
	int		f;
	int		j;
	char	**split;

} t_j;

typedef struct s_data
{
	t_list *stack_top_b;
	t_list *tmp_sort;
	t_list	*maxb;
	t_list	*maxa;
	t_list	*min;
	t_list	*pr;
	
	int decide;
	int decide2;
	int point;
	int pointam;
	int lenb;
	int lena;
	int sacend_len_a;
	t_list *stack_top_a;
	t_list *stack_end_a;
} t_data;

// void	f_split(t_list *node, t_list *satef, char **av);
// char	**jme3_o_dir_espace(char **av);
// char	*get_next_line(int fd);
int		bcheck_sort_stack(t_data *ptr);
int		minposa(t_data *ptr);
int		ft_intcmp(int *s1, int *s2);
char	*ft_strjoin(char *s1, char *s2);
int		emty_str(char *str);
void	decide_sort(t_data *ptr);
void	get_addr_end(t_data *ptr);
void    spb(t_data *ptr);
void    spa(t_data *ptr);
void    ssa(t_data *ptr);
void    ssb(t_data *ptr);
void    srra(t_data *ptr);
void   	srrb(t_data *ptr);
int		ft_strncmp(char *s1, char *s2, int n);
void	check_sort_stack(t_data *ptr);
void	push_min(t_data *ptr);
void	push_max(t_data *ptr);
int		maxposa(t_data *ptr);
int		max_a(t_data *ptr);
int		sort_3(t_data *ptr);
int		min(t_data *ptr);
int		sort_5(t_data *ptr);
void	mainn(t_jj j, t_data *data, int ac, char **av);
void	intcmp(t_jj *j, t_data *data);
void	sload_to_a(t_jj *j, t_data *data);
void	sidk(t_jj j, t_data *data, char **av);
void	idk(t_jj j, t_data *data, char **av);
void	load_to_a(t_jj *j, t_data *data);
void	cmp_A(t_data *ptr);
int		get_len_A(t_data *ptr);
void	full_pos(t_data *ptr);
int		maxpos(t_data *ptr);
void	do_rrb(t_data *ptr);
void	do_rb(t_data *ptr);
void	push_to_a(t_data *ptr);
void 	max(t_data *ptr);
void	sateff(t_data *ptr);
void	laod_stack_tmp(t_data *ptr);
void	compair(t_data *ptr);
void	double_mouve_ss_rr_rrr(t_data *ptr, int num);
void	sa_sb_ra_rb(t_data *ptr, int num);
char	**ft_split(char const *s, char c);
int		ft_atoi(char *s);
void	pb(t_data *ptr);
void	pa(t_data *ptr);
void	rra(t_data *ptr);
void	rrb(t_data *ptr);
void	ra(t_data *ptr);
void	sra(t_data *ptr);
void	rb(t_data *ptr);
void	srb(t_data *ptr);
void	sa(t_data *ptr);
void	sb(t_data *ptr);
#endif
