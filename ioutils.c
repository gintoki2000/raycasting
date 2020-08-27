#include "types.h"

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
    (*line_ptr)[i] = buff[i];
  return k;
}

int		ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_check_arg(char *argv, char *name)
{
	int i;

	i = 0;
	while (argv[i] == name[i])
	{
		if (argv[i] == '\0' && name[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int		ft_check_format(char *argv, char *format)
{
	int		argv_l;
	int		format_l;

	argv_l = ft_strlen(argv);
	format_l = ft_strlen(format);
	if (argv_l < format_l)
		return (0);
	else
		return (ft_check_arg(argv + format_l - 1, format));
}

int 	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

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
