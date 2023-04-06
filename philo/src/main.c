/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:31:39 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/06 14:56:18 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

int	main(int argc, char **argv)
{
	t_table		table;

	if (argc != 5 && argc != 6)
		raise_error("usage: ./philo n_philos t_die t_eat t_sleep [n_eat]\n");
	if (!set_table_manners(&table, argc, argv))
		raise_error("error: invalid number for table manners\n");
	set_philos(&table);
	set_forks(&table);
	create_threads(&table);
	await_threads(&table);
	return (0);
}