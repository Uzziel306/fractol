/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolis <asolis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 19:37:02 by asolis            #+#    #+#             */
/*   Updated: 2017/08/21 19:42:52 by asolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "../Libft/libft.h"

# define WIDTH		480
# define HEIGHT		360
# define PTR_MOTION	(1L<<6)
# define MOTION		6

typedef struct				s_mlx
{
	void					*win;
	void					*mlx;
}							t_mlx;

typedef struct				s_mv
{
	double					zoom;
	double					movex;
	double					movey;
	double					xfactor;
	double					yfactor;
}							t_mv;

typedef struct				s_p
{
	long double				pr;
	long double				pi;
	long double				nre;
	long double				ore;
	long double				nim;
	long double				oim;
	long double				creal;
	long double				cimag;
	int						maxi;
	unsigned int			colormax;
	int						color;
	int						mouse_on;
}							t_p;

typedef struct				s_frac
{
	int						mandela;
	int						julia;
	int						ship;
	int						ring;
	int						master;
}							t_frac;

typedef struct				s_hammer
{
	t_mlx					mlx;
	t_frac					frac;
	t_p						p;
	t_mv					mv;
}							t_hammer;

/*
** main.c
*/
int							main(int argc, char **argv);
void						ft_draw(t_hammer *f);
int							get_fractol(t_hammer *f, char *fractol);
void						text(t_hammer *f);
void						set(t_hammer *f);
void						set_xy(t_hammer *f);
/*
** julia.c
*/
void						ft_julia(t_hammer *f, intmax_t x, intmax_t y);
/*
** ship.c
*/
void						ft_ship(t_hammer *f, intmax_t x, intmax_t y);

/*
** color.c
*/
unsigned int				draw_color(int i, int maxi, t_hammer *f);

/*
** mandelbrot.c
*/
void						ft_mandela(t_hammer *f, intmax_t x, intmax_t y);

/*
** key.c
*/
int							key_hook(int key, t_hammer *f);
int							mouse_move(int x, int y, t_hammer *f);
int							mouse_zoom(int key, int x, int y, t_hammer *f);

/*
** zoom.c
*/
void						zoomit(t_hammer *f, int key);
void						move(t_hammer *f, int key);

/*
** one_ring.c
*/
void						one_ring(t_hammer *f, intmax_t x, intmax_t y);
#endif
