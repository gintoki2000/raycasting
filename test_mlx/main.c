
/*
#include "cub3d.h"

int	main(int ac, char **av)
{
if (ac == 3)
ft_init(av[1])
else if(ac ==2)
ft_init(av[1])
else
write(2, "Error : Invalid arguments\n", 26);
return (0);
}

*/

#include "cub3d.h"

const int	map[MAP_NUM_ROWS][MAP_NUM_COLS] =
{
	{1, 1, 1, 1, 1},
	{1, 0, 0, 0, 1},
	{1, 0, 1, 0, 1},
	{1, 0, 0, 0, 1},
	{1, 0, 0, 0, 1},
	{1, 1, 0, 0, 1},
	{1, 1, 1, 1, 1}
};

int initializeWindow(s_graphic *graphic)
{
	graphic->mlx = mlx_init();
	if (!graphic->mlx)
	{
		write(1, "Error initializing MLX.\n", 24);
		return (0);
	}
	graphic->window = mlx_new_window(
			graphic->mlx,
			WINDOW_WIDTH,
			WINDOW_HEIGHT,
			"cub3D"
			);
	if (!graphic->window)
	{
		write(1, "Error creating Window.\n", 23);
		return (0);
	}
	return (1);
}

void        destroyWindow(s_all *all)
{
	//TODO: destroy cai ma minh tao ra ban dau: theo thu tu nguoc lai:
	// renderer, window, mlx (cai nay dung quit?)
	mlx_destroy_image(all->graphic.mlx, all->img.img);
	mlx_destroy_window(all->graphic.mlx, all->graphic.window);
}

int    oneKeyPressed(int keycode, s_all *all)
{
	if (keycode == KEY_ESC)
		destroyWindow(all);
	return (0);
}

void	my_mlx_put_pixel(s_img *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    update(s_player *player)
{
	//TODO: update game objects
	player->x += 1;
	player->y += 1;
}

void draw_player(s_all *all, int color)
{
	float x, x1;
	float y, y1;

	x = all->player.x;
	y = all->player.y;
	x1 = all->player.x + all->player.w;
	y1 = all->player.y + all->player.h;

	my_mlx_put_pixel(&all->img, x, y, color);
	while(y <= y1)
	{
		y += 1;
		my_mlx_put_pixel(&all->img, x, y, color);
	}
	y = all->player.y;
	while(x <= x1)
	{
		x += 1;
		my_mlx_put_pixel(&all->img, x, y, color);
	}
	while (y <= y1)
	{
		y += 1;
		my_mlx_put_pixel(&all->img, x, y, color);
	}
	x1 = all->player.x;
	while (x > x1)
	{
		x -= 1;
		my_mlx_put_pixel(&all->img, x, y, color);
	}
}

void	draw_grid(s_all *all, int color)
{
	int x, x1;
	int y, y1;
	x = all->grid.x;
	y = all->grid.y;
	x1 = all->grid.x + all->grid.tileX;
	y1 = all->grid.y + all->grid.tileY;
	my_mlx_put_pixel(&all->img, x, y, color);
	while (x <= x1)
	{
		while (y <= y1)
		{
			y += 1;
			my_mlx_put_pixel(&all->img, x, y, color);
		}
		y = all->grid.y;
		x += 1;
	}
}

void	draw_map(s_all *all, int color_wall, int color_space)
{
	for (int i = 0; i < MAP_NUM_ROWS; i++)
	{
		for (int j = 0; j < MAP_NUM_COLS; j++)
		{
			all->grid.tileX = j * TILE_SIZE;
			all->grid.tileY = i * TILE_SIZE;
			int tileColor = map[i][j] != 0 ? color_wall : color_space;
			draw_grid(all, tileColor);
		}
	}
}

int    render(s_all	*all)
{
	if (all->img.img)
		mlx_destroy_image(all->graphic.mlx, all->img.img);

	all->img.img = mlx_new_image(all->graphic.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);

	update(&all->player);

	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel, &all->img.line_length, &all->img.endian);

	draw_map(all, 0X000080, 0XE5E5F2);
	//draw_ray;
	//draw_player(all, 0X00FF0010);
	mlx_put_image_to_window(all->graphic.mlx, all->graphic.window, all->img.img, 0, 0); //WINDOW_WIDTH, WINDOW_HEIGHT);
	return (0);
}

void    setup(s_player *player)
{
	player->x = 0; //WINDOW_WIDTH / 2;
	player->y = 0; //WINDOW_HEIGHT / 2;
	player->w = 30;
	player->h = 15;
	player->turnDirection = 0;
	player->walkDirection = 0;
	player->rotationAngle = PI / 2;
	player->walkSpeed = 100;
	player->turnSpeed = 45 * (PI / 180); //en Radian, not Degree
}

int main(void)
{
	//   s_graphic 	graphic;
	//	s_player	player;
	s_all		all;

	initializeWindow(&all.graphic);

	setup(&all.player); //initialize all info
	mlx_loop_hook(all.graphic.mlx, render, &all); // ve hinh
	mlx_key_hook(all.graphic.window, oneKeyPressed, &all); // nut bam
	mlx_loop(all.graphic.mlx);

	return (0);

}