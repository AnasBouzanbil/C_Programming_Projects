/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:11:58 by abouzanb          #+#    #+#             */
/*   Updated: 2022/12/28 13:50:51 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_error(char **argv, int i)
{
	write(2, "pipex: command not found: ", 26);
	write(2, argv[i], ft_strlen(argv[i]));
	exit(1);
}

void	call_child_two(int *fd, char **argv, char **env)
{
	char	*cmd;
	int		fd2;

	fd2 = open(argv[4], O_CREAT | O_RDWR, 0666);
	if (fd2 == -1)
		exit(1);
	dup2(fd2, 1);
	dup2(fd[0], 0);
	close(fd[1]);
	cmd = is_valid(argv[3], env);
	if (cmd == NULL)
		cmd_error(argv, 3);
	execve(cmd, ft_split(argv[3], ' '), env);
	exit(1);
}

void	call_child_one(int *fd, char **argv, char **env)
{
	char	*cmd;
	int		fd1;

	fd1 = open(argv[1], O_RDWR, 0666);
	if (fd1 == -1)
	{
		write (2, " pipex: no such file or directory: ", 35);
		write(2, argv[1], ft_strlen(argv[1]));
		write(2, "\n", 1);
		exit(1);
	}
	dup2 (fd1, 0);
	dup2(fd[1], 1);
	close(fd[0]);
	cmd = is_valid(argv[2], env);
	if (cmd == NULL)
		cmd_error(argv, 2);
	execve(cmd, ft_split(argv[2], ' '), env);
	exit(1);
}

int	main(int argc, char *argv[], char *env[])
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (argc == 5)
	{
		pipe(fd);
		pid1 = fork();
		if (pid1 == 0)
			call_child_one(fd, argv, env);
		pid2 = fork();
		if (pid2 == 0)
			call_child_two(fd, argv, env);
		close(fd[1]);
		close(fd[0]);
		waitpid(pid1, 0, 0);
		waitpid(pid2, 0, 0);
		return (0);
	}
	else
		write(2, "pipex : please check the agruments\n", 38);
	return (1);
}
