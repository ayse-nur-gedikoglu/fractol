#include "fractol.h"

void compute_julia_pixel(t_fractol *f, int x, int y)
{
    double z_re;
    double z_im;
    double tmp;
    int    i;

    z_re = f->min_real + ((double)x / WIDTH) * (f->max_real - f->min_real);
    z_im = f->min_imag + ((double)y / HEIGHT) * (f->max_imag - f->min_imag);
    i = 0;
    while ((z_re * z_re + z_im * z_im) <= 4 && i < f->max_iter)
    {
        tmp = z_re * z_re - z_im * z_im + f->julia_re;
        z_im = 2 * z_re * z_im + f->julia_im;
        z_re = tmp;
        i++;
    }
    if (i < f->max_iter)
        pixel_put(f->canvas, x, y, get_color(i, f->max_iter, f->color_offset));
    else
        pixel_put(f->canvas, x, y, CLR_BLACK);
}

void julia(t_fractol *f)
{
    draw_fractal(f, compute_julia_pixel);
}
