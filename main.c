#include "fractol.h"

static void parse_fractal_mode(t_fractol *f, int argc, char **argv)
{
    if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
        f->mode = 0;
    else if (ft_strncmp(argv[1], "julia", 5) == 0)
    {
        if (argc != 4)
            print_error("Usage: ./fractol julia [real] [imag]");
        f->mode = 1;
        f->julia_re = ft_atof(argv[2]);
        f->julia_im = ft_atof(argv[3]);
    }
    else if (ft_strncmp(argv[1], "burning", 7) == 0)
        f->mode = 2;
    else
        print_error("Unknown fractal type!");
}

static void initial_draw(t_fractol *f)
{
    if (f->mode == 0)
        mandelbrot(f);
    else if (f->mode == 1)
        julia(f);
    else if (f->mode == 2)
        burning_ship(f);
}

int main(int argc, char **argv)
{
    t_fractol f;

    if (argc < 2 || argc > 4)
        print_error("Usage: ./fractol mandelbrot OR ./fractol julia [real] [imag] OR ./fractol burning");
    initialize_fractol(&f, argc, argv);
    mlx_create(&f, HEIGHT, WIDTH, "fractol");
    parse_fractal_mode(&f, argc, argv);
    initial_draw(&f);
    register_hooks(&f);
    mlx_loop(f.mlx);
    return (0);
}