/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:01:49 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/08 16:19:17 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>

t_bool	set_philos(t_table *table)
{
	int			i;

	table->philos = (t_philo *)malloc(table->manners.num_philos \
														* sizeof(t_philo));
	if (!table->philos)
		return (ft_false);
	i = 0;
	while (i < table->manners.num_philos)
	{
		pthread_mutex_init(&table->philos[i].mutex, FT_NULL);
		table->philos[i].status = READY;
		table->philos[i].id = i + 1;
		table->philos[i].num_eat = 0;
		table->philos[i].left = FT_NULL;
		table->philos[i].right = FT_NULL;
		table->philos[i].manners = &table->manners;
		table->philos[i].time_start = &table->time_start;
		i++;
	}
	return (ft_true);
}
