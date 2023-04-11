/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:10:31 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/11 15:14:58 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>

void	del_table(t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&table->mutex_print);
	while (i < table->manners.num_philos)
	{
		pthread_mutex_destroy(&table->philos[i].mutex);
		pthread_mutex_destroy(&table->forks[i].mutex);
		i++;
	}
	free(table->philos);
	free(table->forks);
	free(table->threads);
}
