/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:25:44 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/06 15:36:34 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <sys/time.h>

t_time	get_time(void)
{
	t_timeval	tv;

	gettimeofday(&tv, FT_NULL);
	return (tv.tv_usec / 1000);
}
