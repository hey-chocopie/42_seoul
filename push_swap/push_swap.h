#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

typedef struct		s_sd
{
	int		ca;
	int		cb;
	char	*s;
	char	*input_d;
	int		p_small;
	int		p_big;
	int		rb_c;
	int		ra_c;
	int		pa_c;
	int		pb_c;
	int		range;

}					t_sd;
void	 A_to_B(t_list **stack_a, t_list **stack_b, t_sd *s_data, int range);
void	 B_to_A(t_list **stack_a, t_list **stack_b, t_sd *s_data, int range);


//void			sa(t_list **stackA);
//void			sb(t_list **stackB);
//void	        ss(t_list **stackA, t_list **stackB);
//void	        pa(t_list **stackA, t_list **stackB, t_sd *s_data);
//void	        pb(t_list **stackA, t_list **stackB, t_sd *s_data);
//void			ra(t_list **stackA);
//void			rb(t_list **stackB);
//void			rr(t_list **stackA, **stackB);
//void			rra(t_list **stackA, t_sd *s_data);
//void		    rrb(t_list **stackB, t_sd *s_data);
//void			rrr(t_list **stackA, t_sd *s_data);

void    rrr_location(t_list **stack_a, t_list **stackB, t_sd *s_data);
void    rr_location(t_list **stack_a, t_list **stackB, t_sd *s_data);
void    data_save(t_sd *s_data, int *rr_ab_c, int *p_sb, int *pa_count);
int		argc_check_and_make_lst(t_list **stack_a, char ** argv, int argc, t_sd *s_data);
void	range_five(t_list **stack_a, t_list **stack_b, t_sd *s_data, int range);
void	two_three_optimization(t_list **stack_a, t_sd *s_data, int range);
int		min_value(t_list **stack, int depth);
void	pre_value(char *s, t_sd *s_data);
void		circle_lst(t_list **stack, int lst_depth);
void		input_string(t_sd *s_data, char *tmp);
void	data_save(t_sd *s_data, int *rr_ab_c, int *p_sb, int *pa_count);
void	data_load(t_sd *s_data, int *rr_ab_c, int *p_sb, int *pb_count);
void	b_short_length(t_list **stack_a, t_list **stack_b, t_sd *s_data, int range);
void	a_pivot_split(t_list **stack_a, t_list **stack_b, t_sd *s_data, int *remain);
int		location_check(t_sd *s_data, int ra_count, int rb_count);
<<<<<<< HEAD
void		setup_data(t_sd	*s_data);
=======
void		setup_data(t_list **stack_a, t_sd	*s_data);
>>>>>>> f5c52a659c20cce6591b58eca151b22b87e3a969

void	rrr_location(t_list **stack_a, t_list **stack_b, t_sd *s_data);
void	rr_location(t_list **stack_a, t_list **stack_b, t_sd *s_data);
void	b_pivot_split(t_list **stack_a, t_list **stack_b, t_sd *s_data, int *remain);
int		pivot_select(t_list **stack, int range, int *p_small);
void		stack_d_check(t_list *stack_a, t_list *stack_b, t_sd *s_data);

void		sa(t_list **stack_a, t_sd *s_data);
void		sb(t_list **stack_b, t_sd *s_data);
void		ss(t_list **stack_a, t_list **stack_b, t_sd *s_data);
void		pa(t_list **stack_a, t_list **stack_b, t_sd *s_data);
void		pb(t_list **stack_a, t_list **stack_b, t_sd *s_data);
void	ra(t_list **stack_a, t_sd *s_data);
void	rb(t_list **stack_b, t_sd *s_data);
void	rr(t_list **stack_a, t_list **stack_b, t_sd *s_data);
void	rra(t_list **stack_a, t_sd *s_data);
void	rrb(t_list **stack_b, t_sd *s_data);
void	rrr(t_list **stack_a, t_list **stack_b, t_sd *s_data);


<<<<<<< HEAD
=======
void		sa2(t_list **stack_a, t_sd *s_data);
void		sb2(t_list **stack_b, t_sd *s_data);
void		ss2(t_list **stack_a, t_list **stack_b, t_sd *s_data);
void		pa2(t_list **stack_a, t_list **stack_b, t_sd *s_data);
void		pb2(t_list **stack_a, t_list **stack_b, t_sd *s_data);
void	ra2(t_list **stack_a, t_sd *s_data);
void	rb2(t_list **stack_b, t_sd *s_data);
void	rr2(t_list **stack_a, t_list **stack_b, t_sd *s_data);
void	rra2(t_list **stack_a, t_sd *s_data);
void	rrb2(t_list **stack_b, t_sd *s_data);
void	rrr2(t_list **stack_a, t_list **stack_b, t_sd *s_data);
>>>>>>> f5c52a659c20cce6591b58eca151b22b87e3a969





#endif
