/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolis <asolis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 19:29:46 by asolis            #+#    #+#             */
/*   Updated: 2017/08/26 15:24:40 by asolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/keys.h"

unsigned int			draw_color(int i, int maxi, t_hammer *f)
{
	unsigned int	color;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;

	if (i == maxi)
		return (f->p.colormax);
	red = (i * 10) * f->p.color;
	green = (150 - (i * 2)) * f->p.color;
	blue = (310 - (i * 10)) * f->p.color;
	color = (red << 16) + (green << 8) + blue;
	return (color);
}
