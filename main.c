#include "level-parser.h"
#include <stdlib.h>


int main(int argc, char** argv)
{
  level_data_t* level_data;

  if ((level_data = load_level_data("./map.cub")) == NULL)
  {
    return -1;
  }

  free(level_data);
  return 0;
}
