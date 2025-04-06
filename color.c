/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agedikog <gedikoglu_27@icloud.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:27:45 by agedikog          #+#    #+#             */
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
}
