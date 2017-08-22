/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolis <asolis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 19:29:54 by asolis            #+#    #+#             */
/*   Updated: 2017/08/21 19:34:12 by asolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/keys.h"

void					ft_draw(t_hammer *f)
{
	intmax_t		x;
	intmax_t		y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (f->frac.mandela == 1)
				ft_mandela(f, x, y);
			else if (f->frac.julia == 1)
				ft_julia(f, x, y);
			else if (f->frac.ship == 1)
				ft_ship(f, x, y);
			else if (f->frac.ring == 1)
				one_ring(f, x, y);
			x++;
		}
		y++;
	}
	text(f);
}

void					set_xy(t_hammer *f)
{
	if (f->frac.julia == 1)
	{
		f->mv.xfactor = -0.371875;
		f->mv.yfactor = -0.616667;
		f->mv.zoom = 0.724213;
	}
	else if (f->frac.ring == 1)
	{
		f->mv.xfactor = -0.493750;
		f->mv.yfactor = -1.179167;
		f->mv.zoom = 0.724213;
	}
}

int						get_fractol(t_hammer *f, char *fractol)
{
	if (!ft_strcmp(fractol, "mandelbrot"))
		f->frac.mandela = 1;
	else if (!ft_strcmp(fractol, "julia"))
		f->frac.julia = 1;
	else if (!ft_strcmp(fractol, "burningship"))
		f->frac.ship = 1;
	else if (!ft_strcmp(fractol, "one_ring"))
		f->frac.ring = 1;
	else
	{
		ft_printfcolor
("usage: ./fractol [mandelbrot /julia /burningship/one_ring]\n", 91);
		return (0);
	}
	set_xy(f);
	return (1);
}
