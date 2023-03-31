/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table_manners.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:17:28 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/31 14:31:51 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_bool	validate_table_manners(t_manner manner)
{
	if (manner.number.philosophers > 0 \
		&& manner.number.eat >= -1 \
		&& manner.time.die > 0 \
		&& manner.time.eat > 0 \
		&& manner.time.sleep > 0)
		return (ft_true);
	else
		return (ft_false);
}

t_bool	set_table_manners(t_table *table, int argc, char **argv)
{
	table->manner.number.philosophers = ft_atoi(argv[1]);
	table->manner.time.die = ft_atoi(argv[2]);
	table->manner.time.eat = ft_atoi(argv[3]);
	table->manner.time.sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->manner.number.eat = ft_atoi(argv[5]);
	else
		table->manner.number.eat = -1;
	return (validate_table_manners(table->manner));
}
