#include "level_parser.h"

/*
static int	parse_number(const char *str)
{
	int	num;
	int i;

	num = 0;
	i = 0;
	while (ft_isdigit(str[i]))
		num = num * 10 + str[i++] - 48;
	return (num);
}

static int parse_resolution(level_data_t *level_data, const char *line)
{
	char buff[10];
	int  i = 0;

	while (!ft_isdigit(*line))
		++line;
	if (*line == '\0')
		return -1;
	while (ft_isdigit(*line))
		buff[i++] = *(line++);
	buff[i] = '\0';
	level_data->window_width = parse_number(buff);
	++line;
	i = 0;
	while (!ft_isdigit(*line))
		++line;
	if (*line == '\0')
		return -1;
	while (ft_isdigit(*line))
		buff[i++] = *(line++);
	level_data->window_height = parse_number(buff);
	return 0;
}

*/
static int parse(level_data_t *level_data, int fd)
{
	char* line = NULL;
	while (get_next_line(fd, &line))
	{
		if (line[0] == 'R')
			parse_resolution(level_data, line);
		/*
		 // TODO: parse the rest of file .cub into level_data

		else if (ft_strncmp(line, "NO", 2) || ft_strncmp(line, "SO", 2) || ft_strncmp(line, "WE", 2) || ft_strncmp(line, "EA", 2) )
			parse_texture(level_data, line);
		else if (line[0] == 'S')
			parse_texture_sprite(level_data, line);
		else if (line[0] == 'F' || line[0] == 'C')
			parse_color(level_data, line);
		else if (line[0] == '1')
		{
			parse_map(level_data, line);
			return (0);
		}
		else
			ft_error();
		*/
		free(void *)(line);
		line = NULL;
	}
	return 0;
}

level_data_t 	*load_level_data(const char *file)
{
	int fd;

	fd  = open(file, O_RDONLY);
	if (fd < 0)
		return NULL;
	if (parse(level_data, fd) == -1)
	{
		//free(level_data);
		close(fd);
		return NULL;
	}
	close(fd);
	return (level_data);
}
