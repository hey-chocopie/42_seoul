#include "../include/philosophers.h"

void	set_around_number(t_all_data *ad, int *philosopher_number, int *philosopher_next_number, int *philosopher_pre_number)
{
    *philosopher_number = ad->number;
    *philosopher_next_number = (ad->number + 1) % (ad->pd.number_of_philosophers);
    if((*philosopher_number - 1) == -1)
        *philosopher_pre_number = (ad->pd.number_of_philosophers - 1);
    else
        *philosopher_pre_number = *philosopher_number - 1;
}

void philosophers_order(t_all_data *ad)
{
    if(ad->number % 2 == 1)
		usleep(1000 * ad->pd.time_to_eat);
		//accurate_usleep(1000 * ad->pd.time_to_eat, 0);
    if(ad->pd.number_of_philosophers % 2 == 1)
        if (ad->pd.number_of_philosophers == ad->number + 1)
		usleep(1000 * ad->pd.time_to_eat * 2);
		//accurate_usleep(1000 * ad->pd.time_to_eat * 2, 0);
}

void	numbers_odd_or_even(t_all_data *ad, int *philosopher_number, int *philosopher_next_number, int *philosopher_pre_number)
{
	if(ad->number % 2 == 1)
	{
	    pthread_mutex_lock(&(ad->mutex[*philosopher_number]));
	    time_distinction_start_between_end(ad, "has taken a fork", *philosopher_number);
	    pthread_mutex_lock(&(ad->mutex[*philosopher_pre_number]));
	    time_distinction_start_between_end(ad, "has taken a fork", *philosopher_number);
	}
	else if(ad->number % 2 == 0)
	{
	    if(ad->pd.number_of_philosophers % 2 == 1)
	    {
	        if(ad->t.last_eat_time[*philosopher_number] >= 1000)
	            usleep(100);
	    }
	    pthread_mutex_lock(&(ad->mutex[*philosopher_pre_number])); //먼저 다 락떄려
	    time_distinction_start_between_end(ad, "has taken a fork", *philosopher_number);
	    pthread_mutex_lock(&(ad->mutex[*philosopher_number])); //먼저 다 락떄려
	    time_distinction_start_between_end(ad, "has taken a fork", *philosopher_number);
	}
}

void *t_philo_thread(void * arg)
{
    int philosopher_number;
    int philosopher_next_number;
    int philosopher_pre_number;
    t_all_data *ad = (t_all_data *)arg;
    //exit(-3);
	int i = 0;
	int max_index = 0;
	unsigned long long save_time;


	set_around_number(ad, &philosopher_number, &philosopher_next_number, &philosopher_pre_number);
	philosophers_order(ad);
    while(1)
    {
		numbers_odd_or_even(ad, &philosopher_number, &philosopher_next_number, &philosopher_pre_number);
        pthread_mutex_lock(ad->monitor_mutex);
        get_time(&(ad->t.last_eat_time[philosopher_number]));

		get_time(&save_time);

		///get_time(&(ad->t). new_msecs_time);
		pthread_mutex_unlock(ad->monitor_mutex); //먼저 다 락떄려
        if (time_distinction_start_between_end(ad, "is eating", philosopher_number) == -1|| (accurate_usleep(1000 * ad->pd.time_to_eat, save_time, ad)) == -2)
        {
			return (void *)(-2);
        }
		//usleep(1000 * ad->pd.time_to_eat);
        pthread_mutex_unlock(&(ad->mutex[philosopher_number])); //먼저 다 락떄려
        pthread_mutex_unlock(&(ad->mutex[philosopher_pre_number])); //먼저 다 락떄려
		//pthread_mutex_lock(ad->monitor_mutex);
        if(*(ad->die_flag) == 1)
		{
			//pthread_mutex_unlock(ad->monitor_mutex);
            break; // 맞겠지?
		}
//		save_time = 0;
		get_time(&save_time);

		//printf("%d,%d %s\n", ad->number,philosopher_number, "pre sleep");
		//pthread_mutex_unlock(ad->monitor_mutex);
        if (time_distinction_start_between_end(ad, "is sleeping", philosopher_number) == -1 || (accurate_usleep((1000 * ad->pd.time_to_sleep), save_time, ad)) == -2 )
        {
			return (void *)(-2);
        }
		//usleep(1000 * ad->pd.time_to_sleep);
		//printf("%d,%d %s\n", ad->number,philosopher_number, "pre think");
        if(time_distinction_start_between_end(ad, "is thinking", philosopher_number) == -1)
        {
			return (void *)(-2);
        }
		if( ad->pd.time_to_eat > ad->pd.time_to_sleep)
		{
			if ((accurate_usleep((1000 * (ad->pd.time_to_eat - ad->pd.time_to_sleep)), 0, ad)) == -2)
				return (void *)(-2);
			//usleep(1000 * (ad->pd.time_to_eat - ad->pd.time_to_sleep));
		}
		else if(ad->pd.number_of_philosophers % 2 == 1)
		{
			if ((accurate_usleep(1000 * ad->pd.time_to_eat, 0, ad)) == -2)
				return (void *)(-2);
		}
	//	else if(ad->pd.number_of_philosophers % 2 == 0)
//		if(ad->pd.number_of_philosophers % 2)
//		if(ad->pd.number_of_philosophers % 2 == 1)
//			if ((accurate_usleep(1000)) == -1)
//				return (void *)(-2);
		
		if (ad->pd.number_of_philosophers >= 100)
			usleep(100000);
		if (ad->pd.number_of_philosophers >= 50)
			usleep(50000);
		else if (ad->pd.number_of_philosophers > 40)
			usleep(20000);

		else if (ad->pd.number_of_philosophers > 30)
			usleep(15000);

		else if (ad->pd.number_of_philosophers > 20)
			usleep(10000);
		else if (ad->pd.number_of_philosophers > 10)
			usleep(2000);
		else if (ad->pd.number_of_philosophers > 0)
			usleep(1000);

    }
    return (0);
}

