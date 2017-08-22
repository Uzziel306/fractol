/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolis <asolis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 19:30:11 by asolis            #+#    #+#             */
/*   Updated: 2017/08/21 19:33:41 by asolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/keys.h"

void	change_fractol(t_hammer *f, int key)
{
	f->frac.mandela = 0;
	f->frac.julia = 0;
	f->frac.ship = 0;
	f->frac.ring = 0;
	if (key == 18)
		f->frac.mandela = 1;
	else if (key == 19)
		f->frac.julia = 1;
	else if (key == 20)
		f->frac.ship = 1;
	else if (key == 21)
		f->frac.ring = 1;
	f->frac.master = 0;
	set(f);
	set_xy(f);
}

int		mouse_move(int x, int y, t_hammer *f)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT || f->p.mouse_on != 1)
		return (0);
	f->mv.xfactor = x * (1.5 / WIDTH) - 1.5;
	f->mv.yfactor = y * (1.5 / HEIGHT) - 1.5;
	ft_draw(f);
	return (0);
}

int		mouse_zoom(int key, int x, int y, t_hammer *f)
{
	if (key == 4)
	{
		f->mv.zoom *= 1.1;
		f->mv.movey += (y - HEIGHT / 2) / (HEIGHT * 2.5) / f->mv.zoom;
		f->mv.movex += (x - WIDTH / 2) / (WIDTH * 2.5) / f->mv.zoom;
	}
	else if (key == 5)
		f->mv.zoom /= 1.3;
	ft_draw(f);
	return (0);
}

int		key_hook(int key, t_hammer *f)
{
	if (key == KEY_M)
		f->p.mouse_on = 1;
	else if (key == KEY_COMMA)
		f->p.mouse_on = 0;
	else if (key == KEY_C)
		f->p.color *= 5;
	else if (key == ESC)
		exit(0);
	else if (key == KEY_PAGEUP || key == KEY_PAGEDOWN ||
		key == PADPLUS || key == PADMINUS)
		zoomit(f, key);
	else if (key == UPARROW || key == DOWNARROW ||
		key == RIGHTARROW || key == LEFTARROW)
		move(f, key);
	else if (key == 19 || key == 20 || key == 21 || key == 18)
		change_fractol(f, key);
	ft_draw(f);
	return (0);
}
