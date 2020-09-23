/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 11:42:07 by thi-nguy          #+#    #+#             */
/*   Updated: 2020/09/22 12:16:26 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	parse_texture(t_info *info, char *line)
{
	char **tab;
	
	tab = ft_split(line, ' ');

	if (tab[0][0] == 'N')
		info->north_texture = ft_strdup(tab[1]);
	else if (tab[0][0] == 'S')
		info->south_texture = ft_strdup(tab[1]);
	else if (tab[0][0] == 'E')
		info->east_texture = ft_strdup(tab[1]);
	else if (tab[0][0] == 'W')
		info->west_texture = ft_strdup(tab[1]);
	free(tab);
	tab = NULL;
}

void parse_resolution(t_info *info, char *line)
{
	char **tab;
	
	tab = ft_split(line, ' ');
	info->window_w = ft_atoi(tab[1]);
	info->window_h = ft_atoi(tab[2]);
	free(tab);
	tab = NULL;
}

void	parse_texture_sprite(t_info *info, char *line)
{
	char **tab;
	
	tab = ft_split(line, ' ');
	info->sprite_texture = ft_strdup(tab[1]);
	free(tab);
	tab = NULL;
}


void	parse_color(t_info *info, char *line)
{
	char **tab;
	int red;
	int green;
	int blue;
	int color_int;
	
	tab = ft_split(line + 2, ',');
	red = ft_atoi(tab[0]);
	green = ft_atoi(tab[1]);
	blue = ft_atoi(tab[2]);

	color_int = 65536 * red + 256 * green + blue;
	if (line[0] == 'F')
		info->floor_color = color_int;
	else if (line[0] == 'C')
		info->ceiling_color = color_int;
	free(tab);
	tab = NULL;
}


int *parse_info(int fd, t_info *info)
{
	char *line = NULL;
	while (get_next_line(fd, &line))
	{
		if (line[0] == 'R')
			parse_resolution(info, line);
		else if (ft_strncmp2(line, "NO", 2) || ft_strncmp2(line, "SO", 2) || ft_strncmp2(line, "WE", 2) || ft_strncmp2(line, "EA", 2) )
			parse_texture(info, line);
		else if (line[0] == 'S')
			parse_texture_sprite(info, line);
		else if (line[0] == 'F' || line[0] == 'C')
			parse_color(info, line);
/*		else if (line[0] == '1') // cái này phải xem lại
		{
			parse_map(info, line);
			return (0);
		}
		else
			ft_error();
*/
		free(line);
		line = NULL;
	}
	return 0;
}


int 	ft_open(const char *av, t_info *info)
{
	int fd;

	fd  = open(av, O_RDONLY);
	if (fd < 0)
		return (0);
	if (parse_info(fd, info) != 0)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}


void	init_info(t_info *info)
{
	info->window_w = 0;
	info->window_h = 0;
	
	info->north_texture = NULL;
	info->south_texture = NULL;
	info->east_texture = NULL;
	info->west_texture = NULL;

	info->sprite_texture = NULL;
	
}

/*
void	save_screen(t_info *info, t_mlx *mlx)
{
	// Todo
}
*/
int	run_program(int save, char **av/*, t_mlx *mlx*/)
{
	t_info	info;

	init_info(&info);
	if (!ft_open(av[1], &info))
		return (0);
	if (save == 1)
	{
		//Todo:
		//save_screen(&info, mlx);
	}
	else
	{
		//Todo: 
	}
	//Check parsing:
	printf("width = %d\n", info.window_w);
	printf("height = %d\n", info.window_h);
	printf("north_texture = %s\n", info.north_texture);
	printf("south_texture = %s\n", info.south_texture);
	printf("west_texture = %s\n", info.west_texture);
	printf("east_texture = %s\n", info.east_texture);
	printf("sprite_texture = %s\n", info.sprite_texture);
	printf("ceiling_color = %d\n", info.ceiling_color);
	printf("floor_color = %d\n", info.floor_color);
	return (0);
}
	