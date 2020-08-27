#ifndef TYPES_H
#define TYPES_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <mlx.h>

#include "ioutils.h"
#include "level-parser.h"



typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
typedef signed char s8;

typedef struct level_data
{
	u32 window_width;
	u32 window_height;
	u16 num_rows;
	u16 num_cols;
	const char* window_title;
	const u8* map;
	const u8* NO_texture;
	const u8* SO_texture;
	const u8* WE_texture;
	const u8* EA_texture;
	const u8* S_texture;
	u32 floor_color;
	u32 ceiling_color;
	char	player_dir;
	u32	player_x0;
	u32	player_y0;
} level_data_t;

typedef struct context {
  void *window_ptr;
  void *mlx_ptr;
} context_t;

#endif // TYPES_H
