#ifndef TYPES_H
#define TYPES_H
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
	const char* window_title;
	const u8* map;
} level_data_t;

typedef struct context {
  void *window_ptr;
  void *mlx_ptr;
} context_t;



#endif // TYPES_H
