/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 13:01:34 by fmadura           #+#    #+#             */
/*   Updated: 2018/03/22 14:40:55 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fdf_colr(t_fdf *fdf, t_point *point, int x, int y)
{
	int		rgb;
	int		scale;
	float	pos;

	(void)x;
	(void)y;
	if (!(scale = fdf->z_max - fdf->z_min))
		scale = 1;
	pos = (scale - point->z) * 100 / scale;
	rgb = fdf_color_mixer(fdf->color, fdf->color2, pos / 100);
	return (rgb);
}

int		fdf_rncg(t_fdf *fdf, t_point *point, int x, int y)
{
	int		r;
	int		g;
	int		b;

	(void)point;
	r = (unsigned char)fdf_random(fdf->rand);
	fdf->rand = fdf_random(fdf->rand + x);
	g = (unsigned char)fdf_random(fdf->rand);
	fdf->rand = fdf_random(fdf->rand + y);
	b = (unsigned char)fdf_random(fdf->rand);
	fdf->rand = fdf_random(fdf->rand);
	return ((r << 16) + (g << 8) + b);
}

int		fdf_color_mixer(int c1, int c2, float mix)
{
	float	r;
	float	g;
	float	b;

	r = ((c1 & 0xFF0000) * (1 - mix) + (c2 & 0xFF0000) * (mix));
	g = ((c1 & 0xFF00) * (1 - mix) + (c2 & 0xFF00) * (mix));
	b = ((c1 & 0xFF) * (1 - mix) + (c2 & 0xFF) * (mix));
	r = ((int)r) & 0xff0000;
	g = ((int)g) & 0xff00;
	b = ((int)b) & 0xff;
	return ((int)(r + g + b));
}
