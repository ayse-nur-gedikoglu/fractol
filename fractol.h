/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agedikog <agedikog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 03:44:56 by agedikog          #+#    #+#             */
/*   Updated: 2025/03/22 03:44:56 by agedikog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define HEIGHT 800
# define WIDTH 1000

# define EXIT_KEY 65307
# define MOVE_LEFT 65361
# define MOVE_RIGHT 65363
# define MOVE_UP 65362
# define MOVE_DOWN 65364
# define INCREASE_ITER 97
# define DECREASE_ITER 115
# define RESET_VIEW 114
# define COLOR_SHIFT 99

# define ZOOM_IN 4
# define ZOOM_OUT 5

# define CLR_BLACK 0x000000
# define CLR_WHITE 0xFFFFFF

typedef struct s_burn
{
	double	c_re;
	double	c_im;
	double	z_re;
	double	z_im;
	double	tmp;
	int		i;
}	t_burn;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_fractol
{
	void	*mlx;
	void	*mlx_win;
	t_data	*canvas;
	double	min_real;
	double	max_real;
	double	min_imag;
	double	max_imag;
	double	zoom;
	double	offset_x;
	double	offset_y;
	int		max_iter;
	double	julia_re;
	double	julia_im;
	int		mode;
	int		color_offset;
}	t_fractol;

void	mlx_create(t_fractol *f, int height, int width, char *title);
void	pixel_put(t_data *data, int x, int y, int color);
void	draw_fractal(t_fractol *f, void (*compute_pixel)
			(t_fractol *, int, int));
void	initialize_fractol(t_fractol *f, int argc, char **argv);
void	free_fractol(t_fractol *f);
void	initialize_draw(t_fractol *f);

void	compute_mandelbrot_pixel(t_fractol *f, int x, int y);
void	compute_julia_pixel(t_fractol *f, int x, int y);
void	compute_burning_pixel(t_fractol *f, int x, int y);

int		shift_color(int color, int offset);
int		get_color(int iteration, int max_iter, int offset);

double	ft_atof(const char *str);
void	print_error(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		julia_arg_check(const char *str);

int		close_window(t_fractol *f);
int		key_hook(int keycode, t_fractol *f);
int		mouse_hook(int button, int x, int y, t_fractol *f);
void	register_hooks(t_fractol *f);
void	reset_view(t_fractol *f);

#endif