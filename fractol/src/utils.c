/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 09:31:51 by aalshafy          #+#    #+#             */
/*   Updated: 2024/02/18 09:59:52 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	error(char *str)
{
	ft_printf("%s \n", str);
	exit(0);
}

int	destroy_mlx(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img.img);
	mlx_destroy_window(fractol->mlx, fractol->win);
	free(fractol->mlx);
	exit(0);
}

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

double	ft_atod(char *str)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while ((*str >= 9 && *str <= 13) || 32 == *str)
		++str;
	while ('+' == *str || '-' == *str)
		if ('-' == *str++)
			sign = -sign;
	while (*str != '.' && *str)
		integer_part = (integer_part * 10) + (*str++ - 48);
	if ('.' == *str)
		++str;
	while (*str)
	{
		pow /= 10;
		fractional_part = fractional_part + (*str++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
