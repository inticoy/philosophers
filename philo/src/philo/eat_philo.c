/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 00:23:02 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/09 02:21:55 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

static void	drop_left_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->left->mutex);
	philo->left->owner = 0;
	pthread_mutex_unlock(&philo->left->mutex);
}

static void	drop_right_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->right->mutex);
	philo->right->owner = 0;
	pthread_mutex_unlock(&philo->right->mutex);
}

void	eat_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	philo->status = EAT;
	philo->num_eat++;
	philo->time_last_eat = get_time();
	pthread_mutex_unlock(&philo->mutex);
	print_in_order(philo->mutex_print, *philo->time_start, philo->id, EAT);
	msleep(philo->manners->time_eat);
	drop_left_fork(philo);
	drop_right_fork(philo);
}
