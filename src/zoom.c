/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 19:30:56 by asolis            #+#    #+#             */
/*   Updated: 2017/08/21 19:30:57 by asolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/keys.h"

void		zoomit(t_hammer *f, int key)
{
	if (key == KEY_PAGEUP && f->mv.zoom > 0)
		f->mv.zoom *= 1.3;
	else if (key == KEY_PAGEDOWN && f->mv.zoom > 0)
		f->mv.zoom /= 1.3;
	else if (key == PADPLUS)
		f->p.maxi *= 1.2;
	else if (key == PADMINUS)
		f->p.maxi /= 1.2;
}

void		move(t_hammer *f, int key)
{
	if (key == UPARROW)
		f->mv.movey -= 0.1 / f->mv.zoom;
	else if (key == DOWNARROW)
		f->mv.movey += 0.1 / f->mv.zoom;
	else if (key == LEFTARROW)
		f->mv.movex -= 0.1 / f->mv.zoom;
	else if (key == RIGHTARROW)
		f->mv.movex += 0.1 / f->mv.zoom;
}
