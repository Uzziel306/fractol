/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolis <asolis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 19:30:19 by asolis            #+#    #+#             */
/*   Updated: 2017/08/26 15:24:17 by asolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/keys.h"

void	set(t_hammer *f)
{
	f->mv.zoom = 1;
	f->mv.movex = -0.5;
	f->mv.movey = 0;
	f->p.maxi = 100;
	f->p.colormax = 0X00000000;
	f->p.color = 2;
	f->p.mouse_on = 0;
	f->p.creal = -0.7;
	f->p.cimag = 0.27015;
	f->mv.xfactor = 0;
	f->mv.yfactor = 0;
}

void	put_text(char *str, int i, int j, t_hammer *f)
{
	mlx_string_put(f->mlx.mlx, f->mlx.win, 0 + i, 0 + j, 0xFFFFFF, str);
}

void	text(t_hammer *f)
{
	put_text("ITERTAIONS:", 0, 0, f);
	put_text(ft_itoa(f->p.maxi), 125, 0, f);
	put_text("ZOOM:", 0, 20, f);
	put_text(ft_itoa(f->mv.zoom), 125, 20, f);
	put_text("X", 0, 40, f);
	put_text(ft_itoa(f->mv.zoom), 125, 40, f);
}

int		main(int argc, char **argv)
{
	t_hammer f;

	ft_bzero(&f, sizeof(t_hammer));
	set(&f);
	if (argc == 2)
	{
		if (get_fractol(&f, argv[1]))
		{
			f.mlx.mlx = mlx_init();
			f.mlx.win = mlx_new_window(f.mlx.mlx, WIDTH, HEIGHT, "FRACTOL");
			ft_draw(&f);
			mlx_hook(f.mlx.win, MOTION, PTR_MOTION, mouse_move, &f);
			mlx_mouse_hook(f.mlx.win, mouse_zoom, &f);
			mlx_key_hook(f.mlx.win, key_hook, &f);
			mlx_loop(f.mlx.mlx);
		}
	}
	else
		ft_printfcolor
("%s", "usage: ./fractol [mandelbrot / julia / burningship / one_ring]\n", 91);
	return (0);
}
