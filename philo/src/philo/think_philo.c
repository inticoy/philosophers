/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 00:27:44 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/09 02:12:15 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>

void	think_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	philo->status = THINK;
	pthread_mutex_unlock(&philo->mutex);
	print_in_order(philo->mutex_print, *philo->time_start, philo->id, THINK);
	usleep(100);
}
