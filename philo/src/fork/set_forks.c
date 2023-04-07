/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_forks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:00:36 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/07 15:02:50 by gyoon            ###   ########.fr       */
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
		table->forks[i].owner = 0;
		table->philos[i].left = &table->forks[i];
		if (i == table->manners.num_philos - 1)
			table->philos[i].right = &table->forks[0];
		else
			table->philos[i].right = &table->forks[i + 1];
		i++;
	}
	return (ft_true);
}
