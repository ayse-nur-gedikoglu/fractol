/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agedikog <gedikoglu_27@icloud.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:27:23 by agedikog          #+#    #+#             */
/*   Updated: 2025/03/19 18:03:29 by agedikog         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"

static void parse_fractal_mode(t_fractol *f, int argc, char **argv)
{
    if (argc == 2 && (ft_strncmp(argv[1], "mandelbrot", 10) == 0) && argv[1][10] == '\0')
        f->mode = 0;
    else if ((ft_strncmp(argv[1], "julia", 5) == 0)  && argv[1][5] == '\0')
    {
        if (argc != 4 || !julia_arg_check(argv[2]) || !julia_arg_check(argv[3]))
            print_error("Usage: ./fractol julia [real] [imag]");        
        f->mode = 1;
    }
    else if (argc == 2 && (ft_strncmp(argv[1], "burning", 7) == 0) && argv[1][7] == '\0')
        f->mode = 2;
    else
        print_error("argv[0] = ./program_name argv[1] = mandelbrot or julia or burning");
}

void initialize_draw(t_fractol *f)
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

    if(argc == 1 || argc > 4)
        print_error("Wrong number of arguments\nargv[0] = ./program_name argv[1] = mandelbrot or julia or burning");
    initialize_fractol(&f, argc, argv);
    parse_fractal_mode(&f, argc, argv);
    mlx_create(&f, HEIGHT, WIDTH, "fractol");
    if (!f.mlx_win)
        print_error("Error initializing window!");
    initialize_draw(&f);
    register_hooks(&f);
    mlx_loop(f.mlx);
    free_fractol(&f);
    return (0);
}

