/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:47:21 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/02 23:19:10 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				data;
	int				push_cost;
	int				median;
	struct s_list	*target;
	struct s_list	*next;
	struct s_list	*previous;
}				t_list;

typedef struct c_list
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}				t_rotation;

char	**ft_split(char *s, char c);
int		ft_isdigit(char c);
int		is_numeric(char *str);
int		ft_lstadd_back(t_list **lst, t_list *new);
int		is_sorted(t_list **stack_a);
int		median_bot_pos(t_list *stack, t_list *target_stack);
int		median_diff_pos(t_list *node, t_list *target_node, int value);
int		median_top_pos(t_list *stack, t_list *target);
int		is_on_top(t_list **stack_a, t_list **stack_b);
long	ft_atoi(char *str);
size_t	ft_strlen(char *str);
size_t	ft_lstsize(t_list *node);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
void	align_only_a_bis(t_list **stack_a, t_list **stack_b);
void	align_only_b_bis(t_list **stack_b);
void	align_both_mone(t_list **stack_a, t_list **stack_b);
void	align_diff_m(t_list **stack_a, t_list **stack_b);
void	get_to_top(t_list **stack_a, t_list **stack_b);
void	fil_rotation_data(t_list **stack_a);
void	align_both_mzero(t_list **stack_a, t_list **stack_b);
void	get_to_top_bis(t_list **stack_a, t_list **stack_b);
void	free_list(t_list **list);
void	free_tab(char **argv);
void	ft_exit_error(int code);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	sa(t_list **node);
void	sb(t_list **node);
void	ss(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	ft_start(t_list **stack_a);
void	small_ps(t_list **node);
void	sort(t_list **stack_a, t_list **stack_b);
void	get_push_cost(t_list **stack_a, t_list **stack_b);
void	get_target_smaller(t_list **stack_a, t_list **stack_b);
void	set_median(t_list **stack);
void	align_only_a(t_list **stack_a);
void	align_only_b(t_list **stack_a, t_list **stack_b);
void	push_to_b(t_list **stack_a, t_list **stack_b);
void	get_target_bigger(t_list **stack_a, t_list **stack_b);
void	fil_rotation_data_bis(t_list **stack_b);
void	get_push_cost_bis(t_list **stack_a, t_list **stack_b);
void	push_to_a(t_list **stack_a, t_list **stack_b);
void	align_diff_m_bis(t_list **stack_a, t_list **stack_b);
t_list	*get_cheap_push(t_list **stack_a);
t_list	*init_b(t_list **stack_a);
t_list	*get_max(t_list **stack);
t_list	*get_min(t_list **stack);
t_list	*init_a_bis(char **argv);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int nb);
#endif
