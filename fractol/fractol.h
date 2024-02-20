/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 07:47:47 by aalshafy          #+#    #+#             */
/*   Updated: 2024/02/18 10:29:48 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx.h"
# include "ftprintf/ft_printf.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define WIDTH 800
# define HEIGHT 800

# define WRONG_INPUT \
	"wrong inputs\nThe available Fractols are:\n\
    1- mandelbrot\n\
    2- julia X Y\n\
    "
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define MAGENTA 0xFF00FF
# define LIME 0xCCFF00
# define ORANGE 0xFF6600
# define PURPLE 0x9932CC
# define AQUA 0x33CCCC
# define PINK 0xFF66B2
# define ELECTRIC 0x0066FF
# define LIGHTENING 0x00CCFF
# define LAVA 0xFF3300
# define YELLOW 0xFFFF00
# define PASTELYELLOW 0xFFFF99
# define PASTELPINK 0xFFB6C1
# define MAGENTA_BURST 0xFF00FF
# define LIME_SHOCK 0xCCFF00
# define NEON_ORANGE 0xFF6600
# define PSYCHEDELIC_PURPLE 0x660066
# define AQUA_DREAM 0x33CCCC
# define HOT_PINK 0xFF66B2
# define ELECTRIC_BLUE 0x0066FF
# define LAVA_RED 0xFF3300

typedef struct s_complex
{
	double		x;
	double		y;
}				t_complex;

typedef struct s_img
{
	void		*img;
	char		*pixels;
	char		*addr;
	int			bpp;
	int			endian;
	int			line_len;
}				t_img;

typedef struct s_fractol
{
	char		*name;
	void		*mlx;
	void		*win;
	t_img		img;
	double		escape_value;
	int			iterations;
	int			flag;
	double		shift_x;
	double		shift_y;
	double		zoom;
	t_complex	mouse;
	int			current_colour;
}				t_fractol;

# define K_ESC 53
# define K_NUM_MULT 67
# define K_NUM_DIV 75
# define K_NUM_PLUS 69
# define K_NUM_MINUS 78
# define K_NUM_ENTER 76
# define K_NUM_0 82
# define K_UP 126
# define K_DOWN 125
# define K_LEFT 123
# define K_RIGHT 124
# define K_DIGIT_1 18
# define K_L 37
# define Q 12
# define W 13
# define SPACE 49
# define R 15

void			parse_args(int ac, char **av, t_fractol *fractol);
void			validate_julia_args(char **av);
int				ft_isdigit(int c);
void			init(t_fractol *fractol, char **av);
int				ft_strcmp(const char *s1, const char *s2);
double			ft_atod(char *s);
int				close_handler(t_fractol *fractol);
int				key_handler(int keysym, t_fractol *fractol);
int				mouse_handler(int button, int x, int y, t_fractol *fractol);
int				julia_track(int x, int y, t_fractol *fractol);
void			init_events(t_fractol *fractol);
void			reset(t_fractol *fractol);
void			fractol_render(t_fractol *fractol);
int				coloring(int colour1, int colour2, double t);
double			map(double unscaled_num, double new_min, double new_max,
					double old_max);
void			fractol_init(t_fractol *fractol);
void			init_main(t_fractol *fractol);
t_complex		sum_complex(t_complex a, t_complex b);
t_complex		square_complex(t_complex z);
int				destroy_mlx(t_fractol *fractol);
void			error(char *s);
void			pixel_iterat(int x, int y, t_fractol *fractol);
void			my_pixel_put(t_img *img, int x, int y, int color);
int				key_handler_2(int keysym, t_fractol *fractol);
void			update_zoom_center(t_fractol *fractol, int mouse_x,
					int mouse_y);

#endif