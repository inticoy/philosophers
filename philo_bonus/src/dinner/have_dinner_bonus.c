/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have_dinner_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:56:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/21 17:46:46 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
#include <stdlib.h>

t_bool	have_dinner(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->manners.num_philos)
	{
		table->philos[i] = fork();
		if (table->philos[i] < 0)
			return (ft_false);
		else if (table->philos[i] == 0)
		{
			table->philo.id = i;
			break ;
		}
		i++;
	}
	if (table->philos[table->philo.id] == 0)
		exec_philo(table);
	else
		exec_admin(table);
	return (ft_true);
}
