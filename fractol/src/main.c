/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 10:55:15 by aalshafy          #+#    #+#             */
/*   Updated: 2024/02/18 10:55:20 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(int ac, char **av)
{
	t_fractol	fractol;

	parse_args(ac, av, &fractol);
	init(&fractol, av);
	fractol_render(&fractol);
	init_events(&fractol);
	mlx_loop(fractol.mlx);
	return (0);
}

void	parse_args(int ac, char **av, t_fractol *fractol)
{
	if (ac == 2 && (!ft_strcmp(av[1], "mandelbrot")))
		fractol->name = av[1];
	else if (ac == 4 && (!ft_strcmp(av[1], "julia")))
	{
		validate_julia_args(av);
		fractol->name = av[1];
	}
	else
		error(WRONG_INPUT);
}

void	validate_julia_args(char **av)
{
	int	i;

	i = -1;
	while (av[2][++i])
	{
		if (!ft_isdigit(av[2][i]) && av[2][i] != '.')
		{
			if ((av[2][i] == '-' || av[2][i] == '+') && i == 0)
				continue ;
			else
				error(WRONG_INPUT);
		}
	}
	i = -1;
	while (av[3][++i])
	{
		if (!ft_isdigit(av[3][i]) && av[3][i] != '.')
		{
			if ((av[3][i] == '-' || av[3][i] == '+') && i == 0)
				continue ;
			else
				error(WRONG_INPUT);
		}
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
