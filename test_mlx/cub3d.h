#ifndef    CUB3D_H
#define CUB3D_H

#include <mlx.h>
#include <unistd.h>
#include <math.h>

#define PI 3.14159265
#define TWO_PI 6.28318530

#define TILE_SIZE 64
#define MAP_NUM_ROWS 7
#define MAP_NUM_COLS 5


#define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
#define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)


#define KEY_ESC 53

typedef struct t_graphic
{
	void	*mlx;
	void	*window;
}	s_graphic;

typedef struct t_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int 	line_length;
	int		endian;
}	s_img;

typedef struct	t_player
{
	float x;
	float y;
	float w;// width, height of player
	float h;
	int		turnDirection; // -1 for left, +1 for right
	int		walkDirection; // -1 for backward, +1 forward
	float	rotationAngle;
	float	walkSpeed; // how fast going front back
	float	turnSpeed; // how fast turning angle direction
} 	s_player;

typedef struct t_grid
{
	int x;
	int y;
	int  tileX;
	int  tileY;
} 	s_grid;

typedef struct t_all
{
	s_graphic	graphic;
	s_player	player;
	s_img		img;
	s_grid		grid;
}	s_all;

int		initializeWindow(s_graphic *graphic);
void	destroyWindow(s_all *all);

void	setup(s_player *player);
void	update(s_player *player);

int		oneKeyPressed(int keycode, s_all *all);
int		render(s_all *all);

void	my_mlx_put_pixel(s_img *img, int x, int y, int color);
void	draw_player(s_all *all, int color);
void	draw_map(s_all *all, int color_wall, int color_space);
void	draw_grid(s_all *all, int color);



#endif

