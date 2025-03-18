#include "fractol.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

void	mlx_create(t_fractol *fractol, int height, int width, char *title)
{
	fractol->mlx = mlx_init();
	fractol->mlx_win = mlx_new_window(fractol->mlx, width, height, title);
	fractol->canvas = malloc(sizeof(t_data));
	fractol->canvas->img = mlx_new_image(fractol->mlx, width, height);
	fractol->canvas->addr = mlx_get_data_addr(fractol->canvas->img,
		&fractol->canvas->bits_per_pixel, 
		&fractol->canvas->line_length,
		&fractol->canvas->endian);
}

void	initialize_fractol(t_fractol *fractol, int argc, char **argv)
{
	fractol->min_real = -2.0;
	fractol->max_real = 2.0;
	fractol->min_imag = -2.0;
	fractol->max_imag = 2.0;
	fractol->zoom = 1.0;
	fractol->offset_x = 0.0;
	fractol->offset_y = 0.0;
	fractol->max_iter = 100;
	fractol->julia_re = 0.285;
	fractol->julia_im = 0.01;
	if (argc == 4)
	{
		fractol->julia_re = ft_atof(argv[2]);
		fractol->julia_im = ft_atof(argv[3]);
	}
}

void draw_fractal(t_fractol *f, void (*compute_pixel)(t_fractol *, int, int))
{
    int x;
    int y;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            compute_pixel(f, x, y);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(f->mlx, f->mlx_win, f->canvas->img, 0, 0);
}
