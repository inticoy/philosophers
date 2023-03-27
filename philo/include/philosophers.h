/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:31:05 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/27 16:47:24 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

typedef unsigned long long	t_size;

enum e_file_descriptor
{
	STDIN = 0,
	STDOUT = 1,
	STDERR = 2
};

//		error
void	raise_error(char *msg);

//		utils
void	ft_putstr_fd(char *s, int fd);
t_size	ft_strlen(const char *s);

#endif