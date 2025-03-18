#include "fractol.h"

int map_val(int value, int input_min, int input_max, int output_min, int output_max)
{
    double ratio;

    if (input_max == input_min)
        return output_min;
    ratio = (double)(value - input_min) / (input_max - input_min);
    return (int)(output_min + ratio * (output_max - output_min));
}

int shift_color(int color, int offset)
{
    int r = (color >> 16) & 0xFF;
    int g = (color >> 8) & 0xFF;
    int b = color & 0xFF;

    r = (r + offset) % 256;
    g = (g + offset) % 256;
    b = (b + offset) % 256;

    return (r << 16) | (g << 8) | b;
}

int get_color(int iteration, int max_iter, int offset)
{
    if (iteration == max_iter)
        return CLR_BLACK;
    int base_color = map_val(iteration, 0, max_iter, CLR_BLACK, CLR_WHITE);
    return shift_color(base_color, offset);
}
