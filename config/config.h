/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 13:28:29 by thi-nguy          #+#    #+#             */
/*   Updated: 2020/09/22 12:17:15 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
#define CONFIG_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "gnl/get_next_line.h"

typedef struct s_info
{
	int window_w;
	int window_h;
	int num_rows;
	int num_cols;
	char **map;
	char *north_texture;
	char *south_texture;
	char *west_texture;
	char *east_texture;
	char *sprite_texture;
	int floor_color;
	int ceiling_color;
	char	player_dir;
	int	player_x0;
	int player_y0;
} t_info;

typedef struct s_mlx 
{
  void *win_ptr;
  void *ptr;
} t_mlx;

int	check_arg(char *av, char *name);
int	check_format(char *av, char *format);
int	ft_strncmp2(const char *s1, const char *s2, int n);

int	run_program(int save, char **av/*, t_mlx *mlx*/);
void	init_info(t_info *info);
int	*parse_info(int fd, t_info *info);
int 	ft_open(const char *av, t_info *info);
//void	save_screen(t_info *info, t_mlx *mlx);

void	parse_texture_sprite(t_info *info, char *line);
void	parse_texture(t_info *info, char *line);
void	parse_color(t_info *info, char *line);
void 	parse_resolution(t_info *info, char *line);
void	parse_map(t_info *info, int fd, char *line);
#endif
