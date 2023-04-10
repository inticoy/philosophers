/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 00:27:44 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/10 17:27:20 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>

t_bool	think_philo(t_philo *philo)
{
	if (!get_is_dining(philo->table))
		return (ft_false);
	pthread_mutex_lock(&philo->mutex);
	philo->status = THINK;
	pthread_mutex_unlock(&philo->mutex);
	print_in_order(philo->table, philo->id, THINK);
	usleep(100);
	return (ft_true);
}
