/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_admin_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:36:30 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/21 17:46:46 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/wait.h>
#include "philosophers_bonus.h"

static void	kill_philos(t_table *table);
void		exec_admin(t_table *table);

void	exec_admin(t_table *table)
{
	int	status;
	int	i;

	i = 0;
	while (i < table->manners.num_philos)
	{
		usleep(200);
		waitpid(-1, &status, 0);
		if (status >> 8 == 1)
		{
			kill_philos(table);
			return ;
		}
		i++;
	}
	return ;
}

static void	kill_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->manners.num_philos)
		kill(table->philos[i++], SIGKILL);
	return ;
}
