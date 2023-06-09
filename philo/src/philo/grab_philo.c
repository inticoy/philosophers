/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:42:04 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/15 17:35:45 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>

static t_bool	grab_fork(t_philo *philo, t_direction direction);

t_bool	grab_philo(t_philo *philo)
{
	t_direction	direction;

	direction = (t_direction)(philo->id % 2);
	while (!philo->hands[LEFT].is_holding || !philo->hands[RIGHT].is_holding)
	{
		usleep(50);
		if (!philo->hands[direction].is_holding)
		{
			if (is_dead_philo(philo))
				return (ft_false);
			philo->hands[direction].is_holding = grab_fork(philo, direction);
			if (!philo->hands[direction].is_holding)
				continue ;
		}
		if (is_dead_philo(philo))
			return (ft_false);
		philo->hands[!direction].is_holding = grab_fork(philo, !direction);
		if (!philo->hands[!direction].is_holding)
			drop_fork(philo, direction);
	}
	if (is_dead_philo(philo))
		return (ft_false);
	print_in_order(philo->table, philo->id, GRAB);
	return (ft_true);
}

static t_bool	grab_fork(t_philo *philo, t_direction direction)
{
	t_bool	ret;

	ret = ft_false;
	pthread_mutex_lock(&philo->hands[direction].fork->mutex);
	if (!philo->hands[direction].fork->is_held)
	{
		philo->hands[direction].fork->is_held = ft_true;
		ret = ft_true;
	}
	pthread_mutex_unlock(&philo->hands[direction].fork->mutex);
	return (ret);
}
