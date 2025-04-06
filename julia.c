/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agedikog <gedikoglu_27@icloud.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:28:11 by agedikog          #+#    #+#             */
/*   Updated: 2025/03/19 18:40:04 by agedikog         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"

void compute_julia_pixel(t_fractol *f, int x, int y)
{
    t_burn  j;

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
        pixel_put(f->canvas, x, y, get_color(j.i, f->max_iter, f->color_offset));
    else
        pixel_put(f->canvas, x, y, CLR_BLACK);
}


void julia(t_fractol *f)
{
    draw_fractal(f, compute_julia_pixel);
}
