/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_is_dining.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:32:34 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/10 16:33:31 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_is_dining(t_table *table, t_bool is_dining)
{
	pthread_mutex_lock(&table->mutex_dining);
	table->is_dining = is_dining;
	pthread_mutex_unlock(&table->mutex_dining);
}
