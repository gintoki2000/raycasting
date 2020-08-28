#include "ioutils.h"

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

int		ft_strncmp(const char *s1, const char *s2, int n)
{
	int i;

	i = 0;
	if (n <= 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	if ((unsigned char)s1[i] - (unsigned char)s2[i])
		return (0);
	else
		return (1);
}
