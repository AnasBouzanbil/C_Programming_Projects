/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:43:52 by abouzanb          #+#    #+#             */
/*   Updated: 2022/12/28 14:07:54 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	cmd_error(char **argv, int i)
{
	write(2, "pipex: command not found: ", 26);
	write(2, argv[i], ft_strlen(argv[3]));
	exit(1);
}

void	child_help_child(int *fd, char **av)
{
	char	*str;
	int		i;

	str = get_next_line(0);
	i = 0;
	while (1)
	{
		if (ft_strncmp(str, av[2], ft_strlen(av[2])) == 0 && \
		ft_strlen(av[2]) == (ft_strlen(str) - 1))
			exit(0);
		write(fd[1], str, ft_strlen(str));
		free(str);
		str = get_next_line(0);
	}
	exit(0);
}

void	call_child(int *fd, char *av[], char *env[])
{
	int		f[2];
	char	*command;
	int		i;

	if (ft_strncmp(av[1], "here_doc", ft_strlen(av[1])) != 0)
		exit(1);
	pipe(f);
	dup2(fd[1], 1);
	close(fd[0]);
	i = fork();
	if (i == 0)
		child_help_child(f, av);
	wait(0);
	command = is_valid(av[3], env);
	if (command == NULL)
		cmd_error(av, 3);
	dup2(f[0], 0);
	close(f[1]);
	execve(command, ft_split(av[3], ' '), env);
}

void	call_second_child(int *fd, int fdt, char **av, char **env)
{
	char	*str;
	char	**s;

	close(fd[1]);
	dup2(fdt, 1);
	dup2(fd[0], 0);
	str = is_valid(av[4], env);
	if (str == NULL)
		exit(1);
	s = ft_split(av[4], ' ');
	if (s == NULL)
		cmd_error(av, 4);
	if (execve(str, s, env) == -1)
		exit(1);
}

int	main(int ac, char *av[], char *env[])
{
	int	fd[2];
	int	fdt;
	int	pid;
	int	pid1;

	if (ac == 6)
	{
		fdt = open(av[5], O_CREAT | O_RDWR | O_APPEND, 0777);
		if (fdt == -1)
			exit(1);
		pipe(fd);
		pid = fork();
		if (pid == 0)
			call_child(fd, av, env);
		pid1 = fork();
		if (pid1 == 0)
			call_second_child(fd, fdt, av, env);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid, 0, 0);
		waitpid(pid1, 0, 0);
		return (0);
	}
	write(1, "pipex : please check the argumenst\n", 35);
	return (1);
}
