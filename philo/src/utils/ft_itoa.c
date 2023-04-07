/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:01:23 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/06 15:03:26 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>

static t_size	get_digits(int n)
{
	if (0 <= n && n < 10)
		return (1);
	else
		return (get_digits(n / 10) + 1);
}

static char	*set_itoa(char *s, int n)
{
	if (-10 < n && n < 0)
		*s++ = '-';
	else if (10 <= n || n <= -10)
		s = set_itoa(s, n / 10);
	*s++ = '0' + ((n > 0) - (n < 0)) * (n % 10);
	return (s);
}

char	*ft_itoa(int n)
{
	char	*ret;

	ret = (char *)malloc((get_digits(n) + 1) * sizeof(char));
	if (!ret)
		return (0);
	set_itoa(ret, n);
	ret[get_digits(n)] = 0;
	return (ret);
}
