#include "types.h"
#include "level_parser.h"
#include "ioutils.h"
#include "get_next_line.h"


int main(int ac, char** av)
{
	level_data_t* level_data;

	level_data = malloc(sizeof(level_data));
	level_data = NULL;

	if (ac < 4) 
	{
		if (ft_check_format(av[1], ".cub"))
		{
			level_data = load_level_data(av[1]);
			if (level_data == NULL)
				return (-1); // nen co mot function bao loi
			if (ac == 3 && ft_check_arg(av[2], "--save"))
			{
				// TODO: init, sau do save man hinh
				// save_screen(level_data);
			}
			else if (ac == 2)
			{
				// TODO: init, sau do chay game
			}
		}
		else
			write(2, "Error : Invalid arguments\n", 26);
	}
	else
		write(2, "Error : Invalid arguments\n", 26);
	free(level_data);
	level_data = NULL;
	return (0);
}
