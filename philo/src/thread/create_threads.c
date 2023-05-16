/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:39:58 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/17 02:34:36 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

t_bool	create_threads(t_table *table)
{
	int	i;
	int	errno;

	i = 0;
	while (i < table->manners.num_philos)
	{
		errno = pthread_create(&table->threads[i], \
						FT_NULL, \
						act_philo, \
						&table->philos[i]);
		if (errno)
			return (ft_false);
		i++;
	}
	errno = pthread_create(&table->threads[table->manners.num_philos], \
					FT_NULL, \
					act_admin, \
					table);
	if (errno)
		return (ft_false);
	else
		return (ft_true);
}
