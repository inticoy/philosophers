/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:45:20 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/07 15:14:26 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>
#include <unistd.h>

static void	pick_philo(t_philo *philo)
{
	t_bool	has_left;
	t_bool	has_right;

	has_left = ft_false;
	has_right = ft_false;
	while (!has_left || !has_right)
	{
		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(&philo->left->mutex);
			if (!philo->left->owner)
			{
				philo->left->owner = philo->id;
				printf("%dms %d has taken left fork\n", 0, philo->id);
				has_left = ft_true;
			}
			pthread_mutex_unlock(&philo->left->mutex);
			pthread_mutex_lock(&philo->right->mutex);
			if (!philo->right->owner)
			{
				philo->right->owner = philo->id;
				printf("%dms %d has taken right fork\n", 0, philo->id);
				has_right = ft_true;
			}
			pthread_mutex_unlock(&philo->right->mutex);
		}
		else
		{
			pthread_mutex_lock(&philo->right->mutex);
			if (!philo->right->owner)
			{
				philo->right->owner = philo->id;
				printf("%dms %d has taken right fork\n", 0, philo->id);
				has_right = ft_true;
			}
			pthread_mutex_unlock(&philo->right->mutex);
			pthread_mutex_lock(&philo->left->mutex);
			if (!philo->left->owner)
			{
				philo->left->owner = philo->id;
				printf("%dms %d has taken left fork\n", 0, philo->id);
				has_left = ft_true;
			}
			pthread_mutex_unlock(&philo->left->mutex);
		}
	}
}

static void	eat_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	philo->status = EAT;
	philo->num_eat++;
	printf("%dms %d is eating\n", 0, philo->id);
	usleep(philo->manners->time_eat);
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_lock(&philo->left->mutex);
	pthread_mutex_lock(&philo->right->mutex);
	philo->left->owner = 0;
	philo->right->owner = 0;
	pthread_mutex_unlock(&philo->left->mutex);
	pthread_mutex_unlock(&philo->right->mutex);
}

static void	sleep_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	philo->status = SLEEP;
	printf("%dms %d is sleeping\n", 0, philo->id);
	usleep(philo->manners->time_sleep);
	pthread_mutex_unlock(&philo->mutex);
}

static void	think_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	philo->status = THINK;
	printf("%dms %d is thinking\n", 0, philo->id);
	pthread_mutex_unlock(&philo->mutex);
}

void	*act_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		pick_philo(philo);
		eat_philo(philo);
		sleep_philo(philo);
		think_philo(philo);
	}
	return (philo);
}
