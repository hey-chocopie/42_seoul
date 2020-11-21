/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 19:53:45 by hoylee            #+#    #+#             */
/*   Updated: 2020/09/05 02:30:01 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

struct			s_person {
	long long int	tmp;
	long long int	tmp2;
	int				count;
	int				decimal;
	int				minus;
	int				value_minus;
	int				period;
	int				star;
	int				star2;
	int				c_null;
	int				jump;
	int				result;
	int				save_count;
	int				tmp2_minus;
	int				persent_count;
	int				persent_count2;
};

long long int	ft_save_set(char *st, struct s_person *width,
						long long int *x, long long int *save);
void			ft_c(va_list ap, struct s_person *width);
void			ft_s(va_list ap, struct s_person *width);
void			ft_u(va_list ap, struct s_person *width);
void			ft_x(va_list ap, struct s_person *width);
void			ft_p(va_list ap, struct s_person *width);
void			ft_o(va_list ap, struct s_person *width);
void			ft_xx(va_list ap, struct s_person *width);
void			ft_string_stprintf(char *st, struct s_person *width);
void			ft_string_stprintf(char *st, struct s_person *width);
void			ft_string_stprintf(char *st, struct s_person *width);
void			ft_string_stprintf(char *st, struct s_person *width);
void			ft_string_stprintf(char *st, struct s_person *width);
void			ft_string_stprintf(char *st, struct s_person *width);
void			ft_stprintf(char *st, struct s_person *width);
void			ft_d(va_list ap, struct s_person *width);
void			ft_discrimination(const char *args,
					int *i, va_list ap, struct s_person *width);
int				ft_persent_count(const char *args,
					int *i, struct s_person *width, va_list ap);
char			*ft_putnbr_base8(unsigned int nbr, char *base);
char			*ft_putnbr_base(unsigned int nbr, char *base);
char			*ft_putnbr_base2(unsigned long long int nbr, char *base);
int				ft_sizeitoa(int n, int max);
void			ft_setitoa(int *count, long long int *nn, int *max, int *n);
char			*ft_itoa_u(unsigned long long int n);
char			*ft_itoa(int n);
void			ft_nonnum_count(const char *args,
					int *i, int *j, struct s_person *width);
void			ft_firstnonzero_count(const char *args,
						int *i, int *j, struct s_person *width);
void			ft_firstzero_count(const char *args,
					int *i, int *j, struct s_person *width);
void			ft_minus(const char *args,
					int *i, int *j, struct s_person *width);
void			ft_jump(const char *args,
					int *i, int *j, struct s_person *width);
int				ft_printf(const char *args, ...);
#endif
