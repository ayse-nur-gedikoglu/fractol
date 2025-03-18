/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agedikog <gedikoglu_27@icloud.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:27:58 by agedikog          #+#    #+#             */
/*   Updated: 2025/03/18 22:20:49 by agedikog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void register_hooks(t_fractol *f)
{
    mlx_hook(f->mlx_win, KeyPress, KeyPressMask, key_hook, f);
    mlx_hook(f->mlx_win, ButtonPress, ButtonPressMask, mouse_hook, f);
    mlx_hook(f->mlx_win, DestroyNotify, StructureNotifyMask, close_window, f);
}

int close_window(t_fractol *f)
{
    if (f->canvas)
    {
        if (f->canvas->img)
            mlx_destroy_image(f->mlx, f->canvas->img);
        free(f->canvas);
    }
    if (f->mlx_win)
        mlx_destroy_window(f->mlx, f->mlx_win);
    if (f->mlx)
    {
        mlx_destroy_display(f->mlx);
        free(f->mlx);
    }
    exit(0);
    return (0);
}


void reset_view(t_fractol *f)
{
    f->min_real = -2.0;
    f->max_real = 2.0;
    f->min_imag = -2.0;
    f->max_imag = 2.0;
    f->max_iter = 100;
    f->color_offset = 0;
}
