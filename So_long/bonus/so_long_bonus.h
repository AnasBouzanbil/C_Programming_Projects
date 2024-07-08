/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:12:31 by abouzanb          #+#    #+#             */
/*   Updated: 2022/12/08 22:36:48 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <stdint.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>

# define BHCYN "\e[1;96m"
# define RESET "\e[0m"
# define BHMAG "\e[1;95m"
# define URED "\e[4;31m"

typedef struct so_long
{
	char	*oneline;
	char	**map;
	char	*t_pathname;
	char	**fake_map;
	int		fd;
	int		p;
	int		c;
	int		fake_c;
	int		fake_door;
	int		e;
	int		x;
	int		length;
	int		raws;
	int		roaws;
}t_path;
typedef struct mllx
{
	void	*mlx_win;
	void	*mlx;
	void	*img;
	void	*win;
	void	*player;
	void	*walls;
	void	*coll;
	void	*door;
	void	*space;
	int		raw_id;
	int		lenth_id;
	t_path	*str;
}t_map;

char	*gnl_strjoin(char *storage, char *reading);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	**ft_split(char *str, char cut);
size_t	ft_strlen(const char *str);
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(const char *str1, const char *str2);
void	set_images(t_map *ptr, t_path *str);
void	scaning_t_map(t_path *str);
int		check_key(int key, t_map *str);
int		ft_atoi(const char *s);
void	ft_putnbr_fd(int k, int fd);
int		ft_close(int i);
void	get_id(t_map *str);
void	check_char(t_path *str);
void	is_valid(t_path *str);
void	ft_putchar_fd(char c, int fd);
void	isit_valid(t_path *str);
void	check_t_path_name(t_path *str);
void	location(int *raw, int *p, t_path *str);
void	read_t_map(t_path *str);
int		rest(t_path *str);
void	check_other_char(t_path *str);
char	*ft_itoa(int a);
#endif
