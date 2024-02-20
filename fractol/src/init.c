/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 08:11:39 by aalshafy          #+#    #+#             */
/*   Updated: 2024/02/18 10:38:21 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_main(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		error("mlx_init() failed");
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, fractol->name);
	if (!fractol->win)
	{
		error("mlx_new_window() failed");
		free(fractol->mlx);
	}
	fractol->img.img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->img.img)
	{
		error("mlx_new_image() failed");
		destroy_mlx(fractol);
	}
	fractol->img.addr = mlx_get_data_addr(fractol->img.img, &fractol->img.bpp,
			&fractol->img.line_len, &fractol->img.endian);
}

void	init(t_fractol *fractol, char **av)
{
	init_main(fractol);
	fractol->escape_value = 4;
	fractol->iterations = 100;
	fractol->shift_x = 0.0;
	fractol->shift_y = 0.0;
	fractol->zoom = 1.0;
	fractol->flag = 1;
	fractol->current_colour = BLUE;
	if (!ft_strcmp(fractol->name, "julia"))
		fractol->mouse = (t_complex){.x = ft_atod(av[2]), .y = ft_atod(av[3])};
	else
		fractol->mouse = (t_complex){0};
}

void	reset(t_fractol *fractol)
{
	fractol->escape_value = 4;
	fractol->iterations = 42;
	fractol->shift_x = 0.0;
	fractol->shift_y = 0.0;
	fractol->zoom = 1.0;
	fractol->flag = 0;
	if (!ft_strcmp(fractol->name, "julia"))
		fractol->mouse = (t_complex){.x = 0.4, .y = 0.4};
	else
		fractol->mouse = (t_complex){0};
	fractol_render(fractol);
}

void	init_events(t_fractol *fractol)
{
	mlx_hook(fractol->win, 2, 1L << 0, key_handler, fractol);
	mlx_hook(fractol->win, 4, 1L << 2, mouse_handler, fractol);
	mlx_hook(fractol->win, 17, 0, destroy_mlx, fractol);
	mlx_hook(fractol->win, 6, 1L << 13, julia_track, fractol);
}
