/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agedikog <gedikoglu_27@icloud.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:27:45 by agedikog          #+#    #+#             */
/*   Updated: 2025/03/19 00:35:02 by agedikog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int map_val(int value, int input_min, int input_max, int output_min, int output_max)
{
    double  ratio;
    
    if (input_max == input_min)
        return output_min;
    ratio = (double)(value - input_min) / (input_max - input_min);
    return (int)(output_min + ratio * (output_max - output_min));
}

int shift_color(int color, int offset)
{
    int r;
    int g;
    int b;

    r = (color >> 16) & 0xFF;
    g = (color >> 8) & 0xFF;
    b = color & 0xFF;

    r = (r + offset + 256) % 256;
    g = (g + offset + 256) % 256;
    b = (b + offset + 256) % 256;

    if (r < 0) r += 256;
    if (g < 0) g += 256;
    if (b < 0) b += 256;

    return ((r << 16) | (g << 8) | b);
}

int get_color(int iteration, int max_iter, int offset)
{
    if (iteration == max_iter)
        return CLR_BLACK;
    int base_color = map_val(iteration, 0, max_iter, CLR_BLACK, CLR_WHITE);
    return shift_color(base_color, offset);
}
