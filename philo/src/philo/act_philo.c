/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:45:20 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/08 16:40:53 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>
#include <unistd.h>

static void	eat_philo(t_philo *philo)
{
	t_bool	has_left;
	t_bool	has_right;

	has_left = ft_false;
	has_right = ft_false;
	while (!has_left || !has_right)
	{
		if (philo->id % 2 == 0)
		{
			if (!has_left)
			{
				pthread_mutex_lock(&philo->left->mutex);
				if (!philo->left->owner)
				{
					philo->left->owner = philo->id;
					has_left = ft_true;
				}
				pthread_mutex_unlock(&philo->left->mutex);
			}
			if (!has_right)
			{
				pthread_mutex_lock(&philo->right->mutex);
				if (!philo->right->owner)
				{
					philo->right->owner = philo->id;
					has_right = ft_true;
				}
				pthread_mutex_unlock(&philo->right->mutex);
			}
		}
		else
		{
			if (!has_right)
			{
				pthread_mutex_lock(&philo->right->mutex);
				if (!philo->right->owner)
				{
					philo->right->owner = philo->id;
					has_right = ft_true;
				}
				pthread_mutex_unlock(&philo->right->mutex);
			}
			if (!has_left)
			{
				pthread_mutex_lock(&philo->left->mutex);
				if (!philo->left->owner)
				{
					philo->left->owner = philo->id;
					has_left = ft_true;
				}
				pthread_mutex_unlock(&philo->left->mutex);
			}
		}
	}
	printf("%lld %d has taken a fork\n", get_time() - *philo->time_start, philo->id);
	printf("%lld %d has taken a fork\n", get_time() - *philo->time_start, philo->id);
	pthread_mutex_lock(&philo->mutex);
	philo->status = EAT;
	philo->num_eat++;
	printf("%lld %d is eating\n", get_time() - *philo->time_start, philo->id);
	msleep(philo->manners->time_eat);
	pthread_mutex_unlock(&philo->mutex);

	pthread_mutex_lock(&philo->left->mutex);
	philo->left->owner = 0;
	pthread_mutex_unlock(&philo->left->mutex);
	pthread_mutex_lock(&philo->right->mutex);
	philo->right->owner = 0;
	pthread_mutex_unlock(&philo->right->mutex);
}

static void	sleep_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	philo->status = SLEEP;
	printf("%lld %d is sleeping\n", get_time() - *philo->time_start, philo->id);
	pthread_mutex_unlock(&philo->mutex);
	msleep(philo->manners->time_sleep);
}

static void	think_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	philo->status = THINK;
	printf("%lld %d is thinking\n", get_time() - *philo->time_start, philo->id);
	pthread_mutex_unlock(&philo->mutex);
}

void	*act_philo(void *arg)
{
	t_philo	*philo;
	t_bool	check;

	philo = (t_philo *)arg;
	check = ft_false;
	while (!check)
	{
		pthread_mutex_lock(&philo->mutex);
		if (philo->status != READY)
			check = ft_true;
		pthread_mutex_unlock(&philo->mutex);
	}
	printf("%lld %d START!!\n", get_time() - *philo->time_start, philo->id);
	while (1)
	{
		eat_philo(philo);
		sleep_philo(philo);
		think_philo(philo);
	}
	return (philo);
}
