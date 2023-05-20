/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:02:27 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/20 20:58:03 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philosophers.h"

void	del_table(t_table *table)
{
	sem_close(table->sem_print);
	sem_close(table->forks);
	sem_unlink("/sem/print");
	sem_unlink("/sem/forks");
	free(table->philos);
}
