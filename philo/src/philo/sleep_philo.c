/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:12:28 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/10 17:27:18 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_bool	sleep_philo(t_philo *philo)
{
	if (!get_is_dining(philo->table))
		return (ft_false);
	pthread_mutex_lock(&philo->mutex);
	philo->status = SLEEP;
	pthread_mutex_unlock(&philo->mutex);
	print_in_order(philo->table, philo->id, SLEEP);
	msleep(philo->table->manners.time_sleep);
	return (ft_true);
}
