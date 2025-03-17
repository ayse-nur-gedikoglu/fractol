#include "fractol.h"

void	background_colour(t_fractol *fractol, int color)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(x < WİDTH)
	{
		y = 0;
		while(y < HEİGHT)
		{
			pixel_put(fractol->canvas, x, y, color);
			y++;
		}
		x++;
	}
}

void	draw(t_fractol *fractol)
{
	background_colour(fractol, CLR_BLUE);
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->canvas->img, 0, 0);
}
