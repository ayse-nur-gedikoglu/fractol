#include "fractol.h"

static void process_movement(int keycode, t_fractol *f)
{
    double shift = 0.1 * (f->max_real - f->min_real);
    if (keycode == MOVE_LEFT) {
        f->min_real -= shift;
        f->max_real -= shift;
    }
    else if (keycode == MOVE_RIGHT) {
        f->min_real += shift;
        f->max_real += shift;
    }
    else if (keycode == MOVE_UP) {
        f->min_imag -= shift;
        f->max_imag -= shift;
    }
    else if (keycode == MOVE_DOWN) {
        f->min_imag += shift;
        f->max_imag += shift;
    }
}

static void process_settings(int keycode, t_fractol *f)
{
    if (keycode == INCREASE_ITER)
        f->max_iter += 10;
    else if (keycode == DECREASE_ITER) {
        if (f->max_iter > 10)
            f->max_iter -= 10;
    }
    else if (keycode == RESET_VIEW)
        reset_view(f);
    else if (keycode == COLOR_SHIFT)
        f->color_offset = (f->color_offset + 10) % 256;
}

static void update_fractal(t_fractol *f)
{
    if (f->mode == 0)
        mandelbrot(f);
    else if (f->mode == 1)
        julia(f);
    else if (f->mode == 2)
        burning_ship(f);
}

int key_hook(int keycode, t_fractol *f)
{
    if (keycode == EXIT_KEY)
        return close_window(f);
    
    process_movement(keycode, f);
    process_settings(keycode, f);
    update_fractal(f);
    
    mlx_put_image_to_window(f->mlx, f->mlx_win, f->canvas->img, 0, 0);
    return 0;
}

int mouse_hook(int button, int x, int y, t_fractol *f)
{
    double mouse_re;
    double mouse_im;
    double factor;

    mouse_re = f->min_real + ((double)x / WIDTH) * (f->max_real - f->min_real);
    mouse_im = f->min_imag + ((double)y / HEIGHT) * (f->max_imag - f->min_imag);
    if (button == ZOOM_IN)
        factor = 0.9;
    else if (button == ZOOM_OUT)
        factor = 1.1;
    else
        return (0);
    f->min_real = mouse_re + (f->min_real - mouse_re) * factor;
    f->max_real = mouse_re + (f->max_real - mouse_re) * factor;
    f->min_imag = mouse_im + (f->min_imag - mouse_im) * factor;
    f->max_imag = mouse_im + (f->max_imag - mouse_im) * factor;
    if (f->mode == 0)
        mandelbrot(f);
    else if (f->mode == 1)
        julia(f);
    else if (f->mode == 2)
        burning_ship(f);
    mlx_put_image_to_window(f->mlx, f->mlx_win, f->canvas->img, 0, 0);
    return (0);
}
