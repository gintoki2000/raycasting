#ifndef LEVEL_PARSER_H
#define LEVEL_PARSER_H

#include "types.h"

static int	parse_resolution(level_data_t	*level_data, const char	*line);
static int	parse(level_data_t	*level_data, int fd);

level_data_t *load_level_data(const char *file);

#endif // LEVEL_PARSER_H
