#include "fractol.h"

void compute_pixel(t_fractol *f, int x, int y)
{
    double c_re;
    double c_im;
    double z_re;
    double z_im;
    double tmp;
    int    i;

    c_re = f->min_real + ((double)x / WIDTH) * (f->max_real - f->min_real);
    c_im = f->min_imag + ((double)y / HEIGHT) * (f->max_imag - f->min_imag);
    z_re = 0;
    z_im = 0;
    i = 0;
    while ((z_re * z_re + z_im * z_im) <= 4 && i < f->max_iter)
    {
        tmp = z_re * z_re - z_im * z_im + c_re;
        z_im = 2 * z_re * z_im + c_im;
        z_re = tmp;
        i++;
    }
    if (i < f->max_iter)
        pixel_put(f->canvas, x, y, get_color(i, f->max_iter, f->color_offset));
    else
        pixel_put(f->canvas, x, y, CLR_BLACK);
}

void mandelbrot(t_fractol *f)
{
    draw_fractal(f, compute_pixel);
}
