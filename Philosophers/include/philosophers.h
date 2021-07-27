#ifndef PHILO_ONE_H
# define PHILO_ONE_H

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
#include "../libft/libft.h"

typedef struct  s_time
{
  struct timeval      start;
  struct timeval      now;
  unsigned long long  start_msecs_time;
  unsigned long long  now_msecs_time;
  unsigned long long  *last_eat_time;

//    struct timeval *end;
//    unsigned long long *end_msecs_time;
//    struct timeval *new_time;
//    unsigned long long *new_msecs_time;
}               t_time;

typedef struct  s_philosophers_data
{
  int     number_of_philosophers;
  int     time_to_die;
  int     time_to_eat;
  int     time_to_sleep;
  int     number_of_times_each_philosopher_must_eat;
}               t_philosopers_data;

typedef struct  s_all_data
{
  pthread_mutex_t *mutex;
  pthread_mutex_t *monitor_mutex;
  pthread_mutex_t *print_mutex;
  pthread_t       *philosopher;
  pthread_t       *monitor;
  struct s_philosophers_data pd;
  struct s_time   t;
  int             *die_flag;
  int			  *die_index;
  int             number;
}               t_all_data;

int argc_argv_check(int argc, char **argv);
int     set_philosopers(int argc, char **argv, t_all_data *ad);
int get_time(unsigned long long *save);
int     create_mutex(t_all_data *ad);
void *t_philo_thread(void * arg);
int       accurate_usleep(unsigned long long how_sleep, unsigned long long start_time, t_all_data *ad);
int       time_distinction_start_between_end(t_all_data *ad, char *action_string, int number);
#endif
