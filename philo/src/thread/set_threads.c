/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_threads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 11:51:38 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/09 11:55:50 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>

void	set_threads(t_table *table)
{
	table->threads = (pthread_t *)malloc((table->manners.num_philos + 1) \
														* sizeof(pthread_t));
	pthread_mutex_init(&table->mutex_print, FT_NULL);
}