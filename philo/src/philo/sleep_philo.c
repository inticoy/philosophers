/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:12:28 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/09 02:22:51 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	sleep_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	philo->status = SLEEP;
	pthread_mutex_unlock(&philo->mutex);
	print_in_order(philo->mutex_print, *philo->time_start, philo->id, SLEEP);
	msleep(philo->manners->time_sleep);
}
