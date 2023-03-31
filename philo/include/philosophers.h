/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:31:05 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/31 14:32:03 by gyoon            ###   ########.fr       */
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

typedef enum e_bool
{
	ft_false = 0,
	ft_true = 1,
}	t_bool;

typedef struct s_time
{
	int	die;
	int	eat;
	int	sleep;
}	t_time;

typedef struct s_number
{
	int	eat;
	int	philosophers;
}	t_number;

typedef struct s_manner
{
	t_time		time;
	t_number	number;
}	t_manner;

typedef struct s_table
{
	t_manner	manner;
}	t_table;

//		error
void	raise_error(char *msg);

//		table
t_bool	set_table_manners(t_table *table, int argc, char **argv);

//		utils
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
t_size	ft_strlen(const char *s);

#endif