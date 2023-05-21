/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table_manners_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:17:28 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/21 17:46:46 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static t_bool	check_arg_digit(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (!argv[i][j])
			return (ft_false);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (ft_false);
			j++;
		}
		i++;
	}
	return (ft_true);
}

static t_bool	validate_table_manners(t_manner manners)
{
	if (manners.num_philos > 0 \
		&& manners.num_eat >= 0 \
		&& manners.time_die > 0 \
		&& manners.time_eat > 0 \
		&& manners.time_sleep > 0)
		return (ft_true);
	else
		return (ft_false);
}

t_bool	set_table_manners(t_table *table, int argc, char **argv)
{
	if (!check_arg_digit(argc, argv))
		return (ft_false);
	table->manners.num_philos = ft_atoi(argv[1]);
	table->manners.time_die = ft_atoi(argv[2]);
	table->manners.time_eat = ft_atoi(argv[3]);
	table->manners.time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		table->manners.has_num_eat = ft_true;
		table->manners.num_eat = ft_atoi(argv[5]);
	}
	else
	{
		table->manners.has_num_eat = ft_false;
		table->manners.num_eat = 0;
	}
	return (validate_table_manners(table->manners));
}
