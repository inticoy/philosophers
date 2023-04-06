/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:39:58 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/06 14:50:36 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

void	create_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->manners.num_philos)
	{
		pthread_create(&table->threads[i], \
						FT_NULL, \
						act_philo, \
						&table->philos[i]);
		i++;
	}
}
