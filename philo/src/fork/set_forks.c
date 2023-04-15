/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_forks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:00:36 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/15 13:05:29 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>

t_bool	set_forks(t_table *table)
{
	int			i;

	table->forks = (t_fork *)malloc(table->manners.num_philos * sizeof(t_fork));
	if (!table->forks)
		return (ft_false);
	i = 0;
	while (i < table->manners.num_philos)
	{
		pthread_mutex_init(&table->forks[i].mutex, FT_NULL);
		table->forks[i].is_held = ft_false;
		table->philos[i].hands[LEFT].fork = &table->forks[i];
		if (i == table->manners.num_philos - 1)
			table->philos[i].hands[RIGHT].fork = &table->forks[0];
		else
			table->philos[i].hands[RIGHT].fork = &table->forks[i + 1];
		i++;
	}
	return (ft_true);
}
