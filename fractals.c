#include "fractol.h"

void	compute_mandelbrot_pixel(t_fractol *f, int x, int y)
{
	t_burn	m;
	
	m.c_re = f->min_real + ((double)x / WIDTH) * (f->max_real - f->min_real);
	m.c_im = f->min_imag + ((double)y / HEIGHT) * (f->max_imag - f->min_imag);
	m.z_re = 0;
	m.z_im = 0;
	m.i = 0;
	while ((m.z_re * m.z_re + m.z_im * m.z_im) <= 4 && m.i < f->max_iter)
	{
		m.tmp = m.z_re * m.z_re - m.z_im * m.z_im + m.c_re;
		m.z_im = 2 * m.z_re * m.z_im + m.c_im;
		m.z_re = m.tmp;
		m.i++;
	}
	if (m.i < f->max_iter)
		pixel_put(f->canvas, x, y, get_color(m.i, f->max_iter,
				f->color_offset));
	else
		pixel_put(f->canvas, x, y, CLR_BLACK);
}

void	compute_julia_pixel(t_fractol *f, int x, int y)
{
	t_burn	j;

	j.z_re = f->min_real + ((double)x / WIDTH) * (f->max_real - f->min_real);
	j.z_im = f->min_imag + ((double)y / HEIGHT) * (f->max_imag - f->min_imag);
	j.i = 0;
	while ((j.z_re * j.z_re + j.z_im * j.z_im) <= 4 && j.i < f->max_iter)
	{
		j.tmp = j.z_re * j.z_re - j.z_im * j.z_im + f->julia_re;
		j.z_im = 2 * j.z_re * j.z_im + f->julia_im;
		j.z_re = j.tmp;
		j.i++;
	}
	if (j.i < f->max_iter)
		pixel_put(f->canvas, x, y, get_color(j.i, f->max_iter,
				f->color_offset));
	else
		pixel_put(f->canvas, x, y, CLR_BLACK);
}


void	compute_burning_pixel(t_fractol *f, int x, int y)
{
	t_burn	b;

	b.c_re = f->min_real + ((double)x / WIDTH) * (f->max_real - f->min_real);
	b.c_im = f->min_imag + ((double)y / HEIGHT) * (f->max_imag - f->min_imag);
	b.z_re = 0;
	b.z_im = 0;
	b.i = 0;
	while ((b.z_re * b.z_re + b.z_im * b.z_im) <= 4 && b.i < f->max_iter)
	{
		b.tmp = b.z_re;
		b.z_re = fabs(b.z_re * b.z_re - b.z_im * b.z_im + b.c_re);
		b.z_im = fabs(2 * b.tmp * b.z_im + b.c_im);
		b.i++;
	}
	if (b.i < f->max_iter)
		pixel_put(f->canvas, x, y, get_color(b.i, f->max_iter,
				f->color_offset));
	else
		pixel_put(f->canvas, x, y, CLR_BLACK);
}
