/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 19:53:45 by hoylee            #+#    #+#             */
/*   Updated: 2020/08/30 17:18:23 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>

struct person {    // 구조체 정의
    long long int tmp ;        // 구조체 멤버 1
    long long int tmp2;              // 구조체 멤버 2
    int count;	//width 가 시작할떄 0 잉있는지 확인하는 값
	int decimal; //width가 소수점 부터 시작하는데 0이 먼저 나올떄 0 값을 카운터 할려고 만듬.
	int minus; // width 에 마이너스가 있는지 확인할려고 만듬.
	int value_minus; // 값이 마이너스로 시작하면 앞에 마이너스 처리할려고 만듬.
	int period;
	int star;
	int star2;
	int c_null;
	int jump;
	int result;
	int save_count;
	int tmp2_minus;
};
long long int   ft_save_set(char *st, struct person *width,
						long long int *x, long long int *save);
void        ft_c(va_list ap, struct person *width);
void        ft_s(va_list ap, struct person *width);

void        ft_u(va_list ap, struct person *width);
void        ft_x(va_list ap, struct person *width);
void        ft_p(va_list ap, struct person *width);
void        ft_o(va_list ap, struct person *width);
void        ft_xx(va_list ap, struct person *width);
void	ft_string_stprintf(char *st, struct person *width);
void	ft_string_stprintf(char *st, struct person *width);
void	ft_string_stprintf(char *st, struct person *width);
void	ft_string_stprintf(char *st, struct person *width);
void	ft_string_stprintf(char *st, struct person *width);
void	ft_string_stprintf(char *st, struct person *width);
void    ft_stprintf(char *st, struct person *width);
void	ft_d(va_list ap, struct person *width);
void	ft_discrimination(const char *args, int *i, va_list ap, struct person *width);
int		ft_persent_count(const char *args, int *i,struct person *width);
char	*ft_putnbr_base8(unsigned int nbr, char *base);
char    *ft_putnbr_base(unsigned int nbr, char *base);

char    *ft_putnbr_base2(unsigned long long int nbr, char *base);

int     ft_sizeitoa(int n, int max);
void    ft_setitoa(int *count, long long int *nn, int *max, int *n);
char    *ft_itoa_u(unsigned long long int n);
char    *ft_itoa(int n);
void ft_nonnum_count(const char *args, int *i, int *j, struct person *width);
void ft_firstnonzero_count(const char *args, int *i, int *j, struct person *width);
void ft_firstzero_count(const char *args, int *i, int *j, struct person *width);
void ft_minus(const char *args, int *i, int *j, struct person *width);
void ft_jump(const char *args, int *i, int *j, struct person *width);
int     ft_printf(const char *args, ...); 
#endif
