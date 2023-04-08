/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:42:04 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/09 02:19:53 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>

static t_bool	grab_left_fork(t_philo *philo)
{
	t_bool	ret;

	ret = ft_false;
	pthread_mutex_lock(&philo->left->mutex);
	if (!philo->left->owner)
	{
		philo->left->owner = philo->id;
		ret = ft_true;
	}
	pthread_mutex_unlock(&philo->left->mutex);
	return (ret);
}

static t_bool	grab_right_fork(t_philo *philo)
{
	t_bool	ret;

	ret = ft_false;
	pthread_mutex_lock(&philo->right->mutex);
	if (!philo->right->owner)
	{
		philo->right->owner = philo->id;
		ret = ft_true;
	}
	pthread_mutex_unlock(&philo->right->mutex);
	return (ret);
}

void	grab_philo(t_philo *philo)
{
	t_bool	has_left;
	t_bool	has_right;

	has_left = ft_false;
	has_right = ft_false;
	while (!has_left || !has_right)
	{
		usleep(100);
		if (philo->id % 2 == 0)
		{
			if (!has_left)
			{
				has_left = grab_left_fork(philo);
				if (!has_left)
					continue ;
			}
			if (!has_right)
				has_right = grab_right_fork(philo);
		}
		else
		{
			if (!has_right)
			{
				has_right = grab_right_fork(philo);
				if (!has_right)
					continue ;
			}
			if (!has_left)
				has_left = grab_left_fork(philo);
		}
	}
	print_in_order(philo->mutex_print, *philo->time_start, philo->id, GRAB);
	print_in_order(philo->mutex_print, *philo->time_start, philo->id, GRAB);
}
