/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msleep_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:11:27 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/21 17:46:46 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
#include <unistd.h>

int	msleep(unsigned int microseconds)
{
	t_time	start;
	int		i;

	start = get_time();
	i = 0;
	while (i < 1000)
	{
		if (get_time() - start >= microseconds)
			break ;
		usleep(microseconds);
		i++;
	}
	return (0);
}
