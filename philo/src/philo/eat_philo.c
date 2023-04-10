/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 00:23:02 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/10 22:48:48 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

static void	drop_left_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->left.fork->mutex);
	philo->left.fork->is_held = ft_false;
	pthread_mutex_unlock(&philo->left.fork->mutex);
	philo->left.is_holding = ft_false;
}

static void	drop_right_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->right.fork->mutex);
	philo->right.fork->is_held = ft_false;
	pthread_mutex_unlock(&philo->right.fork->mutex);
	philo->right.is_holding = ft_false;
}

t_bool	eat_philo(t_philo *philo)
{
	if (is_dead_philo(philo))
		return (ft_false);
	pthread_mutex_lock(&philo->mutex);
	philo->status = EAT;
	philo->eat_count++;
	philo->time_last_eat = get_time();
	print_in_order(philo->table, get_time(), philo->id, EAT);
	pthread_mutex_unlock(&philo->mutex);
	msleep(philo->table->manners.time_eat);
	drop_left_fork(philo);
	drop_right_fork(philo);
	return (ft_true);
}
