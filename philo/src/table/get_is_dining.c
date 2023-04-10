/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_is_dining.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:30:38 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/10 16:51:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_bool	get_is_dining(t_table *table)
{
	t_bool	is_dining;

	is_dining = ft_false;
	pthread_mutex_lock(&table->mutex_dining);
	is_dining = table->is_dining;
	pthread_mutex_unlock(&table->mutex_dining);
	return (is_dining);
}
