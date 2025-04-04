<<<<<<< HEAD
/* ************************************************************************** */
=======
/******************************************************************************/
>>>>>>> 2c70ea8e17b7515204d2b1928307894b34966e57
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agedikog <gedikoglu_27@icloud.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:27:45 by agedikog          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/03/19 17:24:41 by agedikog         ###   ########.fr       */
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
    
    r = ((color >> 16) & 0xFF) + offset;
    g = ((color >> 8) & 0xFF) + offset;
    b = (color & 0xFF) + offset;

    return (((r % 256) << 16) | ((g % 256) << 8) | (b % 256));
}


int get_color(int iteration, int max_iter, int offset)
{
    int base_color;
    
    if (iteration == max_iter || iteration == 0)
        return CLR_BLACK;
    base_color = map_val(iteration, 1, max_iter, CLR_BLACK, CLR_WHITE);
    return shift_color(base_color, offset);
=======
/*   Updated: 2025/04/02 19:04:07 by agedikog         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"

int	shift_color(int color, int offset)
{
	int	r;
	int	g;
	int	b;

	r = ((color >> 16) & 0xFF) + offset;
	g = ((color >> 8) & 0xFF) + offset;
	b = (color & 0xFF) + offset;
	return (((r % 256) << 16) | ((g % 256) << 8) | (b % 256));
}

int	get_color(int iteration, int max_iter, int offset)
{
	int	base_color;
	double	ratio;

	if (iteration == 0)
		return (CLR_BLACK);
	ratio = (double)(iteration - 1) / (max_iter - 1);
	base_color = (int)(CLR_BLACK + ratio * (CLR_WHITE - CLR_BLACK));
	return (shift_color(base_color, offset));
>>>>>>> 2c70ea8e17b7515204d2b1928307894b34966e57
}
