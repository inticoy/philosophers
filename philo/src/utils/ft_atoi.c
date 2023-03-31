/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:50:15 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/30 20:14:14 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static const char	*skip_space(const char *str)
{
	while (*str == '\t' || *str == '\n' || *str == '\v' \
			|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	return (str);
}

int	ft_atoi(const char *str)
{
	long long	ret;
	long long	minus;

	ret = 0;
	minus = 1;
	str = skip_space(str);
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (*str != '\0')
	{
		if ('0' <= *str && *str <= '9')
			ret = (10 * ret) + (*str - '0');
		else
			break ;
		str++;
		if (minus > 0 && ret < 0)
			return (-1);
		else if (minus < 0 && ret < 0)
			return (0);
	}
	return ((int)(minus * ret));
}
