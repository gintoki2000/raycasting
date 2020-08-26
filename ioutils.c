#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int read_line(int fd, char** line_ptr)
{
  int  k = 0; /*byte read*/
  char buff[500];
  char c;

  if (fd < 0)
    return -1;

  while (read(fd, &c, 1) > 0)
  {
    if (c != '\n')
      buff[k++] = c;
    else
    {
      buff[k++] = '\0';
      break;
    }
  }

  *line_ptr = malloc(sizeof(char) * k);

  for (int i = 0; i < k; ++i)
  {
    *line_ptr[i] = buff[i];
  }

  return k;
}
