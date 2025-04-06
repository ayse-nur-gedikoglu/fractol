/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agedikog <gedikoglu_27@icloud.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:28:27 by agedikog          #+#    #+#             */
/*   Updated: 2025/03/19 18:39:34 by agedikog         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"

void compute_pixel(t_fractol *f, int x, int y)
{
    t_burn m; 

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
        pixel_put(f->canvas, x, y, get_color(m.i, f->max_iter, f->color_offset));
    else
        pixel_put(f->canvas, x, y, CLR_BLACK);
}

void mandelbrot(t_fractol *f)
{
    draw_fractal(f, compute_pixel);
}
