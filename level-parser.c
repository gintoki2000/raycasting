#include "level-parser.h"
#include "ioutils.h"
#include "types.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static inline int is_number(char c) { return c >= '0' && c <= '9'; }

static int parse_number(const char* str)
{
  int num = 0;
  int i = 0;

  while (is_number(str[i]))
    num = num * 10 + str[i++] - 48;
  return num;
}

static int parse_resolution(level_data_t* level_data, const char* line)
{
  char buff[10];
  int  i = 0;

  while (!is_number(*line))
    ++line;
  if (*line == '\0')
    return -1;
  while (is_number(*line))
    buff[i++] = *(line++);
  buff[i] = '\0';
  level_data->window_width = parse_number(buff);
  ++line;
  i = 0;
  while (!is_number(*line))
    ++line;
  if (*line == '\0')
    return -1;
  while (is_number(*line))
    buff[i++] = *(line++);
  level_data->window_height = parse_number(buff);
  return 0;
}
static int parse(level_data_t* level_data, int fd)
{
  char* line = NULL;
  while (read_line(fd, &line) > 0)
  {
    if (line[0] == 'R')
    {
      parse_resolution(level_data, line);
    }
    free(line);
  }
  return 0;
}

level_data_t* load_level_data(const char* file)
{
  int fd = open(file, O_RDONLY);
  if (fd < 0)
  {
    return NULL;
  }

  level_data_t* level_data = malloc(sizeof(level_data));

  if (parse(level_data, fd) == -1)
  {
    free(level_data);
    close(fd);
    return NULL;
  }

  close(fd);

  return level_data;
}
