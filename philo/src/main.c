/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:31:39 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/27 16:59:54 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	(void) argv;
	if (argc != 5 && argc != 6)
		raise_error("usage: ./philo n_philos t_die t_eat t_sleep [n_eat]\n");
	return (0);
}
