/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:31:39 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/18 20:22:52 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_table		table;

	if (argc != 5 && argc != 6)
	{
		raise_error("usage: ./philo n_philos t_die t_eat t_sleep [n_eat]\n");
		return (1);
	}
	if (!set_table_manners(&table, argc, argv))
	{
		raise_error("error: invalid number for table manners\n");
		return (1);
	}

	pid_t	pid;
	sem_t	*sem;

	pid = fork();
	printf("forked %d\n", pid);
	if (pid < 0)
	{
		printf("fork failed\n");
		return (1);
	}
	else if (pid == 0)
	{
		sem = sem_open("test", O_CREAT, 0600, 2);
		printf("child waiting\n");
		sem_wait(sem);
		printf("child now playing\n");
		sem_post(sem);
		sem_close(sem);
		sem_unlink("test");
	}
	else
	{
		sem = sem_open("test", O_CREAT, 0600, 2);
		printf("parent waiting\n");
		sem_wait(sem);
		printf("parent now playing\n");
		sem_post(sem);
		sem_close(sem);
		sem_unlink("test");
	}
	return (0);
}
