#include "types.h"

int main(int argc, char** argv)
{
  level_data_t* level_data;

	if ((level_data = load_level_data("./map.cub")) == NULL)
      return (-1);
  if (argc == 3 && ft_check_format(argv[1], ".cub") && ft_check_arg(argv[2], "--save"))
  {
		// TODO: init, sau do save man hinh
  }
	else if (argc == 2 && ft_check_format(argv[1], ".cub"))
  {
		// TODO: init, sau do chay game
  }
	else
	  write(2, "Error : Invalid arguments\n", 26);
  free(level_data);
  return (0);
}
