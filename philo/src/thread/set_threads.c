/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_threads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 11:51:38 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/15 17:22:40 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>

void	set_threads(t_table *table)
{
	table->threads = (t_pthread *)malloc((table->manners.num_philos + 1) \
														* sizeof(t_pthread));
}
