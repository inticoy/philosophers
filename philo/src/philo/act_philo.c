/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:45:20 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/11 15:18:01 by gyoon            ###   ########.fr       */
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
		usleep(100);
		pthread_mutex_lock(&philo->mutex);
		if (philo->status != READY)
			is_activated = ft_true;
		pthread_mutex_unlock(&philo->mutex);
	}
}

void	*act_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_philo(philo);
	while (!(philo->eat_count == philo->table->manners.num_eat))
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
