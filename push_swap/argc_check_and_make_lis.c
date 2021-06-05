/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argc_check_and_make_lis.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <hoylee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:03:26 by hoylee            #+#    #+#             */
/*   Updated: 2021/06/05 16:14:45 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		argv_check_with_make_stack_a(int i, char **argv, t_list **start)
{
	int		value;
	int		j;
	t_list	*tmp;

	j = 0;
	while (argv[i][j])
	{
		if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-')
			return (-1);
		j++;
	}
	value = ft_atoi(argv[i]);
	if (value == -1 && ft_strncmp(argv[i], "-1", 2)
		!= 0 && ft_strlen(argv[i]) != 2)
		return (-1);
	if (0 == (tmp = ft_lstnew(value)))
		return (-1);
	if ((*start) != NULL)
		ft_lstadd_back(start, tmp);
	else if ((*start) == NULL)
		*start = tmp;
	return (0);
}

void	exit_error_free(char **argv, int argc, t_list **stack_a, t_sd *s_data)
{
	t_list	*tmp;

	if (argc == 2)
		free(argv);
	while ((*stack_a) != 0)
	{
		tmp = (*stack_a)->next;
		free(*stack_a);
		*stack_a = tmp;
	}
	if (s_data->s != 0)
		free(s_data->s);
	write(2, "Error\n", 6);
}

int		argv_overlap_check(char **argv, int argc, int i)
{
	int j;

	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (0 == ft_strncmp(argv[i], argv[j], ft_strlen(argv[i]))
			&& ft_strlen(argv[i]) == ft_strlen(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	arg_string(char ***argv, int *argc, int *i)
{
	(*argv) = ft_split((*argv)[1], ' ');
	*i = 0;
	*argc = 0;
	while ((*argv)[(*argc)])
		(*argc)++;
}

int		argc_check_and_make_lst(t_list **stack_a,
				char **argv, int argc, t_sd *s_data)
{
	int i;

	i = 1;
	if (argc < 2)
		return (1);
	if (argc == 2)
		arg_string(&argv, &argc, &i);
	if (argv_overlap_check(argv, argc, i) == 1)
	{
		exit_error_free(argv, argc, stack_a, s_data);
		return (1);
	}
	while (i != argc)
	{
		(s_data->ca)++;
		if (-1 == argv_check_with_make_stack_a(i, argv, stack_a))
		{
			exit_error_free(argv, argc, stack_a, s_data);
			return (1);
		}
		i++;
	}
	if (argc == 2)
		free(argv);
	return (0);
}
