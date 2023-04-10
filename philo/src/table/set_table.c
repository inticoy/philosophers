/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:22:13 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/10 21:55:12 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_table(t_table *table)
{
	pthread_mutex_init(&table->mutex_print, FT_NULL);
	table->time_start = 0;
	set_philos(table);
	set_forks(table);
	set_threads(table);
}
