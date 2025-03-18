#include "fractol.h"

void compute_burning_pixel(t_fractol *f, int x, int y)
{
    t_burn b;

    b.c_re = f->min_real + ((double)x / WIDTH) * (f->max_real - f->min_real);
    b.c_im = f->min_imag + ((double)y / HEIGHT) * (f->max_imag - f->min_imag);
    b.z_re = 0;
    b.z_im = 0;
    b.i = 0;

    while ((b.z_re * b.z_re + b.z_im * b.z_im) <= 4 && b.i < f->max_iter)
    {
        b.tmp = b.z_re;
        b.z_re = ft_fabs(b.z_re * b.z_re - b.z_im * b.z_im + b.c_re);
        b.z_im = ft_fabs(2 * b.tmp * b.z_im + b.c_im);
        b.i++;
    }
    if (b.i < f->max_iter)
        pixel_put(f->canvas, x, y, get_color(b.i, f->max_iter, f->color_offset));
    else
        pixel_put(f->canvas, x, y, CLR_BLACK);
}

void burning_ship(t_fractol *f)
{
    draw_fractal(f, compute_burning_pixel);
}