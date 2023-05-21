/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have_dinner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:56:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/20 23:49:31 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>

t_bool	have_dinner(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->manners.num_philos)
	{
		table->philos[i].pid = fork();
		if (table->philos[i].pid < 0)
			return (ft_false);
		else if (table->philos[i].pid == 0)
		{
			table->id = i + 1;
			exec_philo(table);
		}
		i++;
	}
	exec_admin(table);
	return (ft_true);
}
