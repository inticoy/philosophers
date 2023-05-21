/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:02:27 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/21 00:29:42 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philosophers.h"

void	del_table(t_table *table)
{
	char	*number;
	int		i;

	sem_close(table->sem_print);
	sem_close(table->forks);
	sem_unlink("/sem/print");
	sem_unlink("/sem/forks");
	i = 0;
	while (table->manners.num_philos)
	{
		sem_close(table->philos[i].sem);
		number = ft_itoa(i);
		sem_unlink(number);
		free(number);
	}
	free(table->philos);
}
