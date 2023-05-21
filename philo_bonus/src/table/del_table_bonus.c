/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_table_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:02:27 by gyoon             #+#    #+#             */
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

void	del_table(t_table *table)
{
	char	*sem_name;
	int		i;

	sem_close(table->sem_print);
	sem_close(table->forks);
	sem_unlink("/sem/print");
	sem_unlink("/sem/forks");
	i = 0;
	while (i < table->manners.num_philos)
	{
		sem_name = get_sem_name(i);
		sem_close(table->times[i]);
		sem_unlink(sem_name);
		i++;
	}
	free(table->times);
	free(table->philos);
}
