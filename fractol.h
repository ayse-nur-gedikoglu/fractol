#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <X11/X.h>
# include "minilibx-linux/mlx.h"

# define HEIGHT 600
# define WIDTH 800

# define EXIT_KEY        65307
# define MOVE_LEFT       65361
# define MOVE_RIGHT      65363
# define MOVE_UP         65362
# define MOVE_DOWN       65364
# define INCREASE_ITER   43
# define DECREASE_ITER   45
# define RESET_VIEW      114
# define COLOR_SHIFT     99

# define ZOOM_IN         4
# define ZOOM_OUT        5

# define CLR_BLACK       0x000000
# define CLR_WHITE       0xFFFFFF

typedef struct s_burn {
    double c_re;
    double c_im;
    double z_re;
    double z_im;
    double tmp;
    int    i;
} t_burn;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_data;

typedef struct s_fractol
{
    void    *mlx;
    void    *mlx_win;
    t_data  *canvas;
    double  min_real;
    double  max_real;
    double  min_imag;
    double  max_imag;
    double  zoom;
    double  offset_x;
    double  offset_y;
    int     max_iter;
    double  julia_re;
    double  julia_im;
	int     mode;
    int     color_offset;
} t_fractol;

void	pixel_put(t_data *data, int x, int y, int color);
void	mlx_create(t_fractol *f, int height, int width, char *title);
void	draw_fractal(t_fractol *f, void (*compute_pixel)(t_fractol *, int, int));
void	background_colour(t_fractol *f, int color);

void	mandelbrot(t_fractol *f);
void	julia(t_fractol *f);
void	burning_ship(t_fractol *f);

void	compute_pixel(t_fractol *f, int x, int y);
void	compute_julia_pixel(t_fractol *f, int x, int y);
void	compute_burning_pixel(t_fractol *f, int x, int y);

int		map_val(int value, int input_min, int input_max, int output_min, int output_max);
int		shift_color(int color, int offset);
int		get_color(int iteration, int max_iter, int offset);

double	ft_fabs(double x);
double	ft_atof(const char *str);
void	print_error(char *str);
void	initialize_fractol(t_fractol *f, int argc, char **argv);
int		ft_strncmp(const char *s1, const char *s2, size_t n)

int		close_window(t_fractol *f);
int		key_hook(int keycode, t_fractol *f);
int		mouse_hook(int button, int x, int y, t_fractol *f);
void	register_hooks(t_fractol *f);

#endif
