#include "fractol.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if(x > 0 && x < WİDTH && y > 0 && y < HEİGHT)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

void	mlx_create(t_fractol *fractol, int height, int width, char *title)
{
	fractol->mlx = mlx_init();
	fractol->mlx_win = mlx_new_window(fractol->mlx, width, height, title);
	fractol->canvas->img = mlx_new_image(fractol->mlx, width, height);
	fractol->canvas->addr = mlx_get_data_addr(fractol->canvas->img, &fractol->canvas->bits_per_pixel, &fractol->canvas->line_length,
		&fractol->canvas->endian);
}
