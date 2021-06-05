/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_save_load.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <hoylee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:03:38 by hoylee            #+#    #+#             */
/*   Updated: 2021/06/05 16:03:39 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	data_save(t_sd *s_data, int *rr_ab_c, int *p_sb, int *pa_count)
{
	rr_ab_c[0] = s_data->ra_c;
	rr_ab_c[1] = s_data->rb_c;
	p_sb[0] = s_data->p_small;
	p_sb[1] = s_data->p_big;
}

void	data_load(t_sd *s_data, int *rr_ab_c, int *p_sb, int *pb_count)
{
	s_data->ra_c = rr_ab_c[0];
	s_data->rb_c = rr_ab_c[1];
	s_data->p_small = p_sb[0];
	s_data->p_big = p_sb[1];
	s_data->pa_c = (*pb_count);
}
