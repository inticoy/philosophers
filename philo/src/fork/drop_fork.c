/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drop_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:27:42 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/15 17:28:10 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

void	drop_fork(t_philo *philo, t_direction direction)
{
	pthread_mutex_lock(&philo->hands[direction].fork->mutex);
	philo->hands[direction].fork->is_held = ft_false;
	pthread_mutex_unlock(&philo->hands[direction].fork->mutex);
	philo->hands[direction].is_holding = ft_false;
}
