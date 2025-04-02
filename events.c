/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agedikog <gedikoglu_27@icloud.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:27:58 by agedikog          #+#    #+#             */
/*   Updated: 2025/04/02 19:36:41 by agedikog         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"

void	register_hooks(t_fractol *f)
{
	mlx_hook(f->mlx_win, KeyPress, KeyPressMask, key_hook, f);
	mlx_hook(f->mlx_win, ButtonPress, ButtonPressMask, mouse_hook, f);
	mlx_hook(f->mlx_win, DestroyNotify, StructureNotifyMask, close_window, f);
}

int	close_window(t_fractol *f)
{
	free_fractol(f);
	exit(0);
	return (0);
}

void	reset_view(t_fractol *f)
{
	f->min_real = -2.0;
	f->max_real = 2.0;
	f->min_imag = -2.0;
	f->max_imag = 2.0;
	f->max_iter = 500;
	f->color_offset = 100;
}
