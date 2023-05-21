/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:02:27 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/21 16:14:09 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philosophers.h"

void	del_table(t_table *table)
{
	sem_close(table->sem_print);
	sem_close(table->forks);
	sem_close(table->death);
	sem_unlink("/sem/print");
	sem_unlink("/sem/forks");
	sem_unlink("/sem/death");
	free(table->philos);
}
