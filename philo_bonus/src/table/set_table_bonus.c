/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:56:25 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/21 17:46:46 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philosophers_bonus.h"

static char	*get_sem_name(int i)
{
	char	*number;
	char	*sem_name;

	number = ft_itoa(i);
	if (!number)
		exit(1);
	sem_name = ft_strjoin("/sem/", number);
	if (!sem_name)
		exit(1);
	free(number);
	return (sem_name);
}

void	set_table(t_table *table)
{
	const int	num_philos = table->manners.num_philos;
	char		*sem_name;
	int			i;

	sem_unlink("/sem/print");
	table->sem_print = sem_open("/sem/print", O_CREAT, 0644, 1);
	sem_unlink("/sem/forks");
	table->forks = sem_open("/sem/forks", O_CREAT, 0644, num_philos);
	i = 0;
	table->times = (t_sem **)malloc(table->manners.num_philos * sizeof(t_sem));
	while (i < table->manners.num_philos)
	{
		sem_name = get_sem_name(i);
		sem_unlink(sem_name);
		table->times[i] = sem_open(sem_name, O_CREAT, 0644, num_philos);
		free(sem_name);
		i++;
	}
	table->philos = (t_pid *)malloc(num_philos * sizeof(t_pid));
	table->philo.id = 0;
	table->philo.eat_count = 0;
	table->time_start = get_time();
	table->philo.time_last_eat = get_timeval();
}
