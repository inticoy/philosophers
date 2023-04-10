/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:01:49 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/10 17:10:43 by gyoon            ###   ########.fr       */
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
		table->philos[i].table = table;
		table->philos[i].status = READY;
		table->philos[i].id = i + 1;
		table->philos[i].eat_count = 0;
		table->philos[i].time_last_eat = 0;
		table->philos[i].left.fork = FT_NULL;
		table->philos[i].left.is_holding = ft_false;
		table->philos[i].right.fork = FT_NULL;
		table->philos[i].right.is_holding = ft_false;
		i++;
	}
	return (ft_true);
}
