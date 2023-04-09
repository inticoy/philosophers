/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:33:30 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/09 14:33:40 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_bool	is_dead_philo(t_philo *philo)
{
	t_bool	is_dead;

	is_dead = ft_false;
	pthread_mutex_lock(&philo->mutex);
	if (philo->status == DEAD)
		is_dead = ft_true;
	pthread_mutex_unlock(&philo->mutex);
	return (is_dead);
}
