#include "../include/philosophers.h"

int argv_check(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    while(i < argc)
    {
        j = 0;
        while(argv[i][j])
        {
            if(ft_isdigit(argv[i][j]) == 0)
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int argc_argv_check(int argc, char **argv)
{
    if(argc != 5 && argc != 6)
        return (-1);
    if(argv_check(argc, argv) == 0)
        return (-1);
    return (0);
}

int get_time(unsigned long long *save)
{
    struct timeval now;

    if(gettimeofday(&now, 0) == -1)
        return (-2);
    *save = (now.tv_sec * 1000000) + (now.tv_usec);
    return (0);
}

int     create_mutex(t_all_data *ad)
{
    int i = 0;

    if(0 == (ad->mutex = malloc(ad->pd.number_of_philosophers * sizeof(pthread_mutex_t))))
        return (-3);
    if(0 == (ad->monitor_mutex = malloc(sizeof(pthread_mutex_t))))
        return (-3);
    if(0 == (ad->print_mutex = malloc(sizeof(pthread_mutex_t))))
        return (-3);
    while(i < ad->pd.number_of_philosophers)
    {
        if(pthread_mutex_init(&ad->mutex[i], NULL) == -1)
            return (-4);
        i++;
    }
    if(pthread_mutex_init(ad->monitor_mutex, NULL) == -1)
        return (-4);
    if(pthread_mutex_init(ad->print_mutex, NULL) == -1)
        return (-4);
    return 0;
}

int     set_philosopers(int argc, char **argv, t_all_data *ad)
{
    int     i;
    int     tmp;
    int     numbers;

    i = 1;
    ad->pd.number_of_times_each_philosopher_must_eat = -1;
    while(i < argc)
    {
        tmp = ft_atoi(argv[i]);
        if (tmp <= 0 || (tmp == 1 && i == 1) || (tmp < 60 && (i == 3 || i == 4)))
            return (-1);
        if (i == 1)
            ad->pd.number_of_philosophers = tmp;
        else if (i == 2)
            ad->pd.time_to_die = tmp;
        else if (i == 3)
            ad->pd.time_to_eat = tmp;
        else if (i == 4)
            ad->pd.time_to_sleep = tmp;
        else if (i == 5)
            ad->pd.number_of_times_each_philosopher_must_eat = tmp;
        i++;
    }
    return (0);
}


