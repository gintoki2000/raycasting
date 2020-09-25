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

void	parse_map(t_info *info, int fd, char *line)
{
	char *map_tmp;

	map_tmp = ft_strdup(line);
	map_tmp = ft_strjoin(map_tmp, ".");
	free(line);
	line = NULL;
	while (get_next_line(fd, &line) && ft_isdigit(line[0]))
	{
		map_tmp = ft_strjoin(map_tmp, line);
		map_tmp = ft_strjoin(map_tmp, ".");
		free(line);
		line = NULL;
	}
	// Need to check whether the map is valid or not? If not, return error right here
	// Có thể để một struct riêng về m map tại đây?
	info->num_rows = ft_count_words(map_tmp, '.');
	info->map = ft_split(map_tmp, '.');
	info->num_cols = ft_strlen(info->map[0]);
	free(map_tmp);
	map_tmp = NULL;
}


int *parse_info(int fd, t_info *info)
{
	char *line = NULL;
	while (get_next_line(fd, &line) && line[0] != '1')
	{
		if (line[0] == 'R')
			parse_resolution(info, line);
		else if (ft_strncmp2(line, "NO", 2) || ft_strncmp2(line, "SO", 2) || ft_strncmp2(line, "WE", 2) || ft_strncmp2(line, "EA", 2) )
			parse_texture(info, line);
		else if (line[0] == 'S' && line[1] != 'O')
			parse_texture_sprite(info, line);
		else if (line[0] == 'F' || line[0] == 'C')
			parse_color(info, line);
/*		else
			ft_error();
*/
		free(line);
		line = NULL;
	}
	parse_map(info, fd, line); // cái này phải xem lại, need to check validity of the map.


		
	
	return (0);
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
	info->floor_color = 0;
	info->ceiling_color = 0;
	
	info->north_texture = NULL;
	info->south_texture = NULL;
	info->east_texture = NULL;
	info->west_texture = NULL;

	info->sprite_texture = NULL;
	info->map = NULL;
	
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
		//Todo: raycasting. inspired: ft_management_program
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

	int i = 0;
	//unsigned long len_info_map = sizeof(info.map);
	//unsigned long len_info_map_element = sizeof(info.map[0]);
	//unsigned long len = len_info_map / len_info_map_element;
	int l = ft_strlen(*info.map);
	int l2 = ft_strlen(*(info.map + 3));
	while (i < info.num_rows)
	{
		printf("map line %2d: |%s|\n", i, info.map[i]);
		i++;
	}
	
	printf("map.info length = %d\n", l);
	printf("map.info length = %d\n", l2);
	printf("info num row = %d\n", info.num_rows);
	printf("info num col = %d\n", info.num_cols);
	return (0);
}
	