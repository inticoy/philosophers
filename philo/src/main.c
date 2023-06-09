/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:31:39 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/17 02:38:55 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_table		table;

	if (argc != 5 && argc != 6)
	{
		raise_error("usage: ./philo n_philos t_die t_eat t_sleep [n_eat]\n");
		return (1);
	}
	if (!set_table_manners(&table, argc, argv))
	{
		raise_error("error: invalid number for table manners\n");
		return (1);
	}
	set_table(&table);
	if (!create_threads(&table))
	{
		raise_error("error: fail to create threads\n");
		return (1);
	}
	await_threads(&table);
	del_table(&table);
	return (0);
}
