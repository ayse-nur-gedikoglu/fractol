/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agedikog <gedikoglu_27@icloud.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:27:55 by agedikog          #+#    #+#             */
/*   Updated: 2025/04/02 12:53:56 by agedikog         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"

static void	zoom(t_fractol *f, int x, int y, int direction)
{
	double	mouse_re;
	double	mouse_im;
	double	zoom;

	if (direction == 1)
		zoom = 0.9;
	else
		zoom = 1.1;
	mouse_re = f->min_real + ((double)x / WIDTH) * (f->max_real - f->min_real);
	mouse_im = f->min_imag + ((double)y / HEIGHT) * (f->max_imag - f->min_imag);
	f->min_real = mouse_re + (f->min_real - mouse_re) * zoom;
	f->max_real = mouse_re + (f->max_real - mouse_re) * zoom;
	f->min_imag = mouse_im + (f->min_imag - mouse_im) * zoom;
	f->max_imag = mouse_im + (f->max_imag - mouse_im) * zoom;
}

int	mouse_hook(int button, int x, int y, t_fractol *f)
{
	if (button == ZOOM_IN)
		zoom(f, x, y, 1);
	else if (button == ZOOM_OUT)
		zoom(f, x, y, -1);
	else
		return (0);
	initialize_draw(f);
	return (0);
}

static void	handle_movement(int keycode, t_fractol *f)
{
	double shift = 0.1 * (f->max_real - f->min_real);

	if (keycode == MOVE_LEFT)
	{
		f->min_real -= shift;
		f->max_real -= shift;
	}
	else if (keycode == MOVE_RIGHT)
	{
		f->min_real += shift;
		f->max_real += shift;
	}
	else if (keycode == MOVE_UP)
	{
		f->min_imag -= shift;
		f->max_imag -= shift;
	}
	else if (keycode == MOVE_DOWN)
	{
		f->min_imag += shift;
		f->max_imag += shift;
	}
}

static void	handle_settings(int keycode, t_fractol *f)
{
	if (keycode == INCREASE_ITER)
		f->max_iter += 10;
	else if (keycode == DECREASE_ITER && f->max_iter > 10)
		f->max_iter -= 10;
	else if (keycode == RESET_VIEW)
		reset_view(f);
	else if (keycode == COLOR_SHIFT)
		f->color_offset = (f->color_offset + 10) % 256;
}

int	key_hook(int keycode, t_fractol *f)
{
	if (keycode == EXIT_KEY)
		close_window(f);
	handle_movement(keycode, f);
	handle_settings(keycode, f);
	initialize_draw(f);
	return (0);
}
