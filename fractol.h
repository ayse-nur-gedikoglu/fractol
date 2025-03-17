#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <X11/X.h>
# include "minilibx-linux/mlx.h"

# define HEİGHT 600
# define WİDTH 800

# define EXIT_KEY        65307
# define MOVE_LEFT       65361
# define MOVE_RIGHT      65363
# define MOVE_UP         65362
# define MOVE_DOWN       65364
# define INCREASE_ITER   43
# define DECREASE_ITER   45
# define RESET_VIEW      114

# define ZOOM_IN         4
# define ZOOM_OUT        5

# define CLR_BLACK       	0x000000
# define CLR_WHITE       	0xFFFFFF
# define CLR_RED         	0xFF0000
# define CLR_GREEN       	0x00FF00
# define CLR_BLUE        	0x0000FF
# define CLR_YELLOW      	0xFFFF00
# define CLR_CYAN        	0x00FFFF
# define CLR_PURPLE      	0x800080
# define CLR_GRAY        	0x808080
# define CLR_MAGENTA_BURST  0xFF00FF
# define CLR_LIME_SHOCK     0xCCFF00
# define CLR_NEON_ORANGE    0xFF6600
# define CLR_AQUA_DREAM     0x33CCCC
# define CLR_HOT_PINK       0xFF66B2
# define CLR_ELECTRIC_BLUE  0x0066FF
# define CLR_LAVA_RED       0xFF3300

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_fractol
{
	void	*mlx;
	t_data	*canvas;
	void	*mlx_win;
}	t_fractol;

void	pixel_put(t_data *data, int x, int y, int color);
void	mlx_create(t_fractol *fractol, int height, int width, char *title);
void	background_colour(t_fractol *fractol, int color);
void	draw(t_fractol *fractol);

#endif