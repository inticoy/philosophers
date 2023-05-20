/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have_dinner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:56:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/19 23:54:26 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>

t_bool	have_dinner(t_table *table)
{
	t_pid	*pids;
	int		i;

	pids = (t_pid *)malloc(table->manners.num_philos * sizeof(t_pid));
	i = 0;
	while (i < table->manners.num_philos)
	{
		pids[i] = fork();
		if (pids[i] < 0)
			return (ft_false);
		else if (pids[i] == 0)
		{
			table->philo.id = i;
			break ;
		}
		i++;
	}
	if (pids[table->philo.id] == 0)
		exec_philo(table);
	else
	{
		waitpid(pids[0], NULL, 0);
	}
	// else
	// 	exec_host(table);
	free(pids);
	return (ft_true);
}
