/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_timeval.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:37:54 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/21 16:38:27 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "philosophers.h"

t_timeval	get_timeval(void)
{
	t_timeval	tv;

	gettimeofday(&tv, FT_NULL);
	return (tv);
}
