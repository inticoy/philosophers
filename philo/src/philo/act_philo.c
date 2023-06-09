/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:45:20 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/16 13:41:12 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>
#include <unistd.h>

static void	wait_philo(t_philo *philo);

void	*act_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_philo(philo);
	while (ft_true)
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
	return (FT_NULL);
}

static void	wait_philo(t_philo *philo)
{
	t_bool	is_activated;

	is_activated = ft_false;
	while (!is_activated)
	{
		usleep(50);
		pthread_mutex_lock(&philo->mutex);
		if (philo->status != READY)
			is_activated = ft_true;
		pthread_mutex_unlock(&philo->mutex);
	}
}
