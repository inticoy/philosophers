/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_admin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:36:30 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/21 11:23:17 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "philosophers.h"

static void	kill_philos(t_table *table);
void		exec_admin(t_table *table);

void	*k(void *arg)
{
	t_table	*table;
	int		status;
	int		i;

	table = (t_table *)arg;
	i = 0;
	while (i < table->manners.num_philos)
	{
		usleep(200);
		waitpid(-1, &status, 0);
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) == 1)
			{
				kill_philos(table);
				return (0);
			}
		}
		else if (WIFSIGNALED(status))
		{
			kill_philos(table);
			return (0);
		}
		i++;
	}
	return (0);
}

void	exec_admin(t_table *table)
{
	k(table);
}

static void	kill_philos(t_table *table)
{
	int	i;

	i = 0;
	printf("kill\n");
	while (i < table->manners.num_philos)
		kill(table->philos[i++].pid, SIGKILL);
	exit(0);
	return ;
}
