/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:31:39 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/09 11:55:25 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_table		table;

	if (argc != 5 && argc != 6)
	{
		raise_error("usage: ./philo n_philos t_die t_eat t_sleep [n_eat]\n");
		return (0);
	}
	if (!set_table_manners(&table, argc, argv))
	{
		raise_error("error: invalid number for table manners\n");
		return (0);
	}
	set_philos(&table);
	set_forks(&table);
	set_threads(&table);
	create_threads(&table);
	await_threads(&table);
	return (0);
}
