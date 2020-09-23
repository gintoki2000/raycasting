#include "config.h"

int		check_arg(char *av, char *name)
{
	int i;

	i = 0;
	while (av[i] == name[i])
	{
		if (av[i] == '\0' && name[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int		check_format(char *av, char *format)
{
	int		av_l;
	int		format_l;

	av_l = ft_strlen(av);
	format_l = ft_strlen(format);
	if (av_l < format_l)
		return (0);
	else
		return (check_arg(av + av_l - format_l, format));
}

int		ft_strncmp2(const char *s1, const char *s2, int n)
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
