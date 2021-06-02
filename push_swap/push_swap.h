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
	int		p_small;
	int		p_big;
	int		rb_c;
	int		ra_c;
	int		pa_c;
	int		pb_c;
	int		range;
}					t_sd;

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

#endif
