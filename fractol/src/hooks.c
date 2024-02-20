/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 09:08:24 by aalshafy          #+#    #+#             */
/*   Updated: 2024/02/18 09:50:03 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	colour_shift(t_fractol *fract)
{
	static int	colours[] = {WHITE, PASTELPINK, GREEN, BLUE, MAGENTA, LIME,
		ORANGE, PURPLE, AQUA, PINK, ELECTRIC, LIGHTENING,
		LAVA, YELLOW, PASTELYELLOW};
	static int	colour_index = 0;

	colour_index = (colour_index + 1) % (sizeof(colours) / sizeof(colours[0]));
	fract->current_colour = colours[colour_index];
	fractol_render(fract);
}

int	key_handler(int keysym, t_fractol *fractol)
{
	if (keysym == K_ESC)
		destroy_mlx(fractol);
	if (keysym == K_LEFT)
		fractol->shift_x += (0.1 * fractol->zoom);
	else if (keysym == K_RIGHT)
		fractol->shift_x -= (0.1 * fractol->zoom);
	else if (keysym == K_UP)
		fractol->shift_y -= (0.1 * fractol->zoom);
	else if (keysym == K_DOWN)
		fractol->shift_y += (0.1 * fractol->zoom);
	else if (keysym == Q)
		fractol->iterations += 10;
	else if (keysym == W)
		fractol->iterations -= 10;
	return (key_handler_2(keysym, fractol));
}

int	key_handler_2(int keysym, t_fractol *fractol)
{
	if (keysym == R)
		reset(fractol);
	if (keysym == 69)
		fractol->zoom *= 0.95;
	else if (keysym == 78)
		fractol->zoom *= 1.05;
	if (keysym == SPACE)
		fractol->flag = !fractol->flag;
	if (keysym == 8)
		colour_shift(fractol);
	mlx_clear_window(fractol->mlx, fractol->win);
	fractol_render(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		fractol->zoom *= 0.95;
		update_zoom_center(fractol, x, y);
	}
	else if (button == 5)
	{
		fractol->zoom *= 1.05;
		update_zoom_center(fractol, x, y);
	}
	fractol_render(fractol);
	return (0);
}
