#include "fractol.h"

int main()
{
	t_fractol	fractol;
	mlx_create(&fractol, HEİGHT, WİDTH, "fractol");
	draw(&fractol);
	controls(&fractol);
	mlx_loop(fractol.mlx);
}