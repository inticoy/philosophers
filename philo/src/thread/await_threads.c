/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   await_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:50:58 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/15 17:13:46 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

void	await_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->manners.num_philos)
	{
		pthread_join(table->threads[i], FT_NULL);
		i++;
	}
	pthread_join(table->threads[table->manners.num_philos], FT_NULL);
}
