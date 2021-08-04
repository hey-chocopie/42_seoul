#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct s_time
{
	struct timeval				start;
	struct timeval				now;
	unsigned long long			start_msecs_time;
	unsigned long long			now_msecs_time;
	unsigned long long			*last_eat_time;
}	t_time;

typedef struct s_philosophers_data
{
	int							number_of_philosophers;
	int							time_to_die;
	int							time_to_eat;
	int							time_to_sleep;
	int							number_of_times_each_philosopher_must_eat;
}	t_philosopers_data;

typedef struct s_all_data
{
	pthread_mutex_t				*mutex;
	pthread_mutex_t				*monitor_mutex;
	pthread_mutex_t				*print_mutex;
	pthread_t					*philosopher;
	pthread_t					*monitor;
	struct s_philosophers_data	pd;
	struct s_time				t;
	int							*die_flag;
	int							*die_index;
	int							number;
	int							*return_value;
	int							*monitor_return_value;
	int							*eat_count;
	unsigned long long			save_time;
}	t_all_data;

int			argc_argv_check(int argc, char **argv);
int			set_argv_data(int argc, char **argv, t_all_data *ad);
int			get_time(unsigned long long *save);
int			create_mutex(t_all_data *ad);
void		*t_philo_thread(void *arg);
int			accurate_usleep(unsigned long long how_sleep,
				unsigned long long start_time);
int			print_t_data(t_all_data *ad, char *action_string, int number);
void		malloc_reset(t_all_data *ad, t_all_data **tmp);
void		all_free(t_all_data *ad, t_all_data **tmp);
void		error_print(int error_code);
int			malloc_mutex(t_all_data *ad);
int			malloc_pthread(t_all_data *ad, t_all_data **tmp);
int			malloc_tmp_data(t_all_data **tmp, int i);
void		*monitor_thread(void *arg);
void		set_around_number(t_all_data *ad, int *ph_number,
				int *ph_next_number, int *ph_pre_number);
void		philosophers_order(t_all_data *ad);
int			*fork_unlock(t_all_data *ad, int ph_number, int ph_pre_number);
int			unlock_fork(t_all_data *ad, int return_value,
				int *ph_number, int *ph_pre_number);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
char		*ft_strnstr(const char *haystack,
				const char *needle, size_t len);
#endif
