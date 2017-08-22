/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolis <asolis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 19:30:02 by asolis            #+#    #+#             */
/*   Updated: 2017/08/21 19:34:42 by asolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/keys.h"

void		ft_julia(t_hammer *f, intmax_t x, intmax_t y)
{
	int i;
	int	color;

	i = 0;
	f->p.creal = f->mv.xfactor;
	f->p.cimag = f->mv.yfactor;
	f->p.nre = 1.5 * (x - WIDTH / 2) /
		(0.5 * f->mv.zoom * WIDTH) + f->mv.movex;
	f->p.nim = (y - HEIGHT / 2) / (0.5 * f->mv.zoom * HEIGHT) + f->mv.movey;
	while (i < f->p.maxi && f->p.nre * f->p.nre + f->p.nim * f->p.nim < 4)
	{
		f->p.ore = f->p.nre;
		f->p.oim = f->p.nim;
		f->p.nre = f->p.ore * f->p.ore - f->p.oim * f->p.oim + f->p.creal;
		f->p.nim = 2 * f->p.ore * f->p.oim + f->p.cimag;
		i++;
	}
	color = draw_color(i, f->p.maxi, f);
	mlx_pixel_put(f->mlx.mlx, f->mlx.win, x, y, color);
}
