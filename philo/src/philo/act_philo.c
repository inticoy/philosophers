/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:45:20 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/09 14:44:12 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>
#include <unistd.h>

static void	wait_philo(t_philo *philo)
{
	t_bool	is_activated;

	is_activated = ft_false;
	while (!is_activated)
	{
		pthread_mutex_lock(&philo->mutex);
		if (philo->status != READY)
			is_activated = ft_true;
		pthread_mutex_unlock(&philo->mutex);
		usleep(100);
	}
	if (philo->id % 2)
		usleep(200);
}

void	*act_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_philo(philo);
	while (1)
	{
		if (!grab_philo(philo))
			break ;
		if (!eat_philo(philo))
			break ;
		if (!sleep_philo(philo))
			break ;
		if (!think_philo(philo))
			break ;
	}
	return (philo);
}
