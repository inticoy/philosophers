/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:56:25 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/21 12:38:40 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philosophers.h"

void	set_table(t_table *table)
{
	const int	num_philos = table->manners.num_philos;
	char		*number;
	char		*sem_name;
	int			i;

	sem_unlink("/sem/print");
	table->sem_print = sem_open("/sem/print", O_CREAT, 0644, 1);
	// printf("sem print : %p\n", table->sem_print);
	table->time_start = get_time();
	sem_unlink("/sem/forks");
	table->forks = sem_open("/sem/forks", O_CREAT, 0644, num_philos);
	table->philos = (t_philo *)malloc(num_philos * sizeof(t_philo));
	i = 0;
	while (i < num_philos)
	{
		number = ft_itoa(i);
		sem_name = ft_strjoin("/sem/", number);
		sem_unlink(sem_name);
		table->philos[i].sem = sem_open(sem_name, O_CREAT, 0644, 1);
		printf("set : sem %s\n", sem_name);
		free(number);
		free(sem_name);
		printf("set : ptr %p\n", table->philos[i].sem);
		table->philos[i].pid = 0;
		table->philos[i].id = i + 1;
		table->philos[i].eat_count = i + 1;
		table->philos[i].time_last_eat = table->time_start;
		i++;
	}
}
