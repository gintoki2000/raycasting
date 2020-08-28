#ifndef LEVEL_PARSER_H
#define LEVEL_PARSER_H

#include <sys/stat.h>
#include <fcntl.h>
#include "types.h"
#include "ioutils.h"

static int	parse_resolution(level_data_t	*level_data, const char	*line);
static int	parse(level_data_t	*level_data, int fd);
static int	parse_number(const char *str);

level_data_t *load_level_data(const char *file);

#endif
