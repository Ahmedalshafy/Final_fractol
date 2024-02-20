/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 09:14:53 by aalshafy          #+#    #+#             */
/*   Updated: 2024/02/18 11:00:56 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	pixel_iterat(int x, int y, t_fractol *fractol)

{
	t_complex	z;
	int			i;
	int			color;

	i = 0;
	z.x = (map(x, -2, +2, WIDTH) * fractol->zoom) + fractol->shift_x;
	z.y = (map(y, +2, -2, HEIGHT) * fractol->zoom) + fractol->shift_y;
	if (!ft_strcmp(fractol->name, "mandelbrot"))
		fractol->mouse = z;
	while (i < fractol->iterations)
	{
		z = sum_complex(square_complex(z), fractol->mouse);
		if ((z.x * z.x) + (z.y * z.y) > fractol->escape_value)
		{
			color = coloring(BLACK, fractol->current_colour, (double)i
					/ fractol->iterations);
			my_pixel_put(&fractol->img, x, y, color);
			return ;
		}
		++i;
	}
	my_pixel_put(&fractol->img, x, y, WHITE);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

t_complex	sum_complex(t_complex a, t_complex b)
{
	t_complex	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	return (result);
}

int	coloring(int color1, int color2, double t)
{
	int	r;
	int	g;
	int	b;

	r = (int)((1 - t) * ((color1 >> 16) & 0xFF) + t * ((color2 >> 16) & 0xFF)
			* 5);
	g = (int)((1 - t) * ((color1 >> 8) & 0xFF) + t * ((color2 >> 8) & 0xFF)
			* 5);
	b = (int)((1 - t) * (color1 & 0xFF) + t * (color2 & 0xFF) * 5);
	r = (int)(r + (255 - r) * t * 1.5);
	g = (int)(g + (255 - g) * t * 0.2);
	b = (int)(b + (255 - b) * t * 5);
	return ((r << 16) | (g << 8) | b);
}

int	julia_track(int x, int y, t_fractol *fractol)
{
	if (!ft_strcmp(fractol->name, "julia"))
	{
		if (!fractol->flag)
		{
			fractol->mouse.x = (map(x, -1, +1, WIDTH) * fractol->zoom)
				+ fractol->shift_x;
			fractol->mouse.y = (map(y, +1, -1, HEIGHT) * fractol->zoom)
				+ fractol->shift_y;
			fractol_render(fractol);
		}
	}
	return (0);
}
