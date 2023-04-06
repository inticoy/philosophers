/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table_manner.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:17:28 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/06 13:35:13 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_bool	validate_table_manners(t_manner manners)
{
	if (manners.num_philos > 0 \
		&& manners.num_eat >= -1 \
		&& manners.time_die > 0 \
		&& manners.time_eat > 0 \
		&& manners.time_sleep > 0)
		return (ft_true);
	else
		return (ft_false);
}

t_bool	set_table_manners(t_table *table, int argc, char **argv)
{
	table->manners.num_philos = ft_atoi(argv[1]);
	table->manners.time_die = ft_atoi(argv[2]);
	table->manners.time_eat = ft_atoi(argv[3]);
	table->manners.time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->manners.num_eat = ft_atoi(argv[5]);
	else
		table->manners.num_eat = -1;
	return (validate_table_manners(table->manners));
}
