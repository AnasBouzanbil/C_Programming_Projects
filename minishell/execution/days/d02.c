/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d02.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 22:35:11 by abouzanb          #+#    #+#             */
/*   Updated: 2023/04/17 22:07:12 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void	read_here_doc(int *fd, t_file *str)
{
	char	*ptr;

	while (1)
	{
		ptr = readline("> ");
		if (ptr == NULL)
		{
			close(fd[1]);
			close(fd[0]);
			exit (0);
		}
		if (my_strcmp(str->name, ptr) == 0)
		{
			close(fd[1]);
			close(fd[0]);
			exit(0);
		}
		if (str->x == 1)
			ptr = expand_do(ptr);
		write(fd[1], ptr, my_strlen(ptr));
		write(fd[1], "\n", 1);
		free(ptr);
	}
}

int	handle_here_doc(t_file *str)
{
	int		fd[2];
	int		x;
	int		i;

	pipe(fd);
	x = fork();
	if (x == 0)
	{
		signal(SIGINT, SIG_DFL);
		read_here_doc(fd, str);
	}
	else
	{
		str->here_doc = dup(fd[0]);
		close(fd[1]);
		close(fd[0]);
		waitpid(x, &i, 0);
		if (WIFSIGNALED(i) == 1)
		{
			g_data.exit_status = 1;
			return (1);
		}
	}
	return (0);
}

void	handle_input(t_file *file)
{
	int	fds;

	fds = open(file->name, O_RDWR, 0644);
	if (fds == -1)
	{
		perror("open");
		exit(1);
	}
	dup2(fds, 0);
	close(fds);
}

void	handle_append(t_file *file)
{
	int	fds;

	fds = open(file->name, O_CREAT | O_APPEND | O_RDWR, 0644);
	if (fds == -1)
	{
		perror("open");
		exit(1);
	}
	dup2(fds, 1);
	close(fds);
}

void	handle_output(t_file *file)
{
	int	fds;

	fds = open(file->name, O_CREAT | O_RDWR, 0644);
	if (fds == -1)
	{
		perror("open");
		exit(1);
	}
	dup2(fds, 1);
	close(fds);
}
