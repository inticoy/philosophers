/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:42:04 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/11 15:55:30 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>

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

static t_bool	grab_left_fork(t_philo *philo)
{
	t_bool	ret;

	ret = ft_false;
	pthread_mutex_lock(&philo->left.fork->mutex);
	if (!philo->left.fork->is_held)
	{
		philo->left.fork->is_held = ft_true;
		ret = ft_true;
	}
	pthread_mutex_unlock(&philo->left.fork->mutex);
	return (ret);
}

static t_bool	grab_right_fork(t_philo *philo)
{
	t_bool	ret;

	ret = ft_false;
	pthread_mutex_lock(&philo->right.fork->mutex);
	if (!philo->right.fork->is_held)
	{
		philo->right.fork->is_held = ft_true;
		ret = ft_true;
	}
	pthread_mutex_unlock(&philo->right.fork->mutex);
	return (ret);
}

t_bool	grab_philo(t_philo *philo)
{
	while (!philo->left.is_holding || !philo->right.is_holding)
	{
		usleep(100);
		if (philo->id % 2 == 0)
		{
			if (!philo->left.is_holding)
			{
				if (is_dead_philo(philo))
					return (ft_false);
				philo->left.is_holding = grab_left_fork(philo);
				if (!philo->left.is_holding)
					continue ;

			}
			if (is_dead_philo(philo))
				return (ft_false);
			if (!philo->right.is_holding)
				philo->right.is_holding = grab_right_fork(philo);
			if (!philo->right.is_holding)
				drop_left_fork(philo);
		}
		else
		{
			if (!philo->right.is_holding)
			{
				if (is_dead_philo(philo))
					return (ft_false);
				philo->right.is_holding = grab_right_fork(philo);
				if (!philo->right.is_holding)
					continue ;

			}
			if (is_dead_philo(philo))
				return (ft_false);
			if (!philo->left.is_holding)
				philo->left.is_holding = grab_left_fork(philo);
			if (!philo->left.is_holding)
				drop_right_fork(philo);	
		}
	}
	if (is_dead_philo(philo))
		return (ft_false);
	print_in_order(philo->table, philo->id, GRAB);
	return (ft_true);
}
