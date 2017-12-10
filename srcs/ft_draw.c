/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 11:12:34 by fmadura           #+#    #+#             */
/*   Updated: 2017/12/10 17:13:04 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_pos(int x, int y)
{
	return ((x * 20 + 300) + (y * 20));
}

int		ft_pythagore(int a, int b)
{
	return ((int)sqrt(pow(a, 2) + pow(b, 2)));
}

int		ft_draw(char *file)
{
	void	*mlx;
	void	*win;
	t_grid	*grid;
	int		x;
	int		y;
	int		tmp;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 800, "FDF");
	if ((grid = (ft_read(file))) == NULL)
		return (0);
	y = 0;
	while (y < grid->size_y)
	{
		x = 0;
		while (x < grid->size_x)
		{
			tmp = 0;
			if (x + 1 < grid->size_x)
				while (ft_pos(x, y) + tmp < ft_pos(x + 1, y))
				{
					mlx_pixel_put(mlx, win,
					ft_pos(x, y) + tmp, 
					((ft_pos(y - grid->grid[y][x + 1], 0) + ft_pos(y - grid->grid[y][x], 0)) / 2) + 100,
					0x00992255);
					tmp++;
				}
			tmp = 0;
			if (y + 1 < grid->size_y)
				while (ft_pos(y, 0) + tmp < ft_pos(y + 1, 0))
				{
					mlx_pixel_put(mlx, win, ft_pos(x, y) + tmp, ft_pos(y - grid->grid[y + 1][x], 0) + tmp + 100, 0x00551199);
					tmp++;
				}

			mlx_pixel_put(mlx, win, ft_pos(x, y), ft_pos(y - grid->grid[y][x], 0) + 100, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	ft_del_grid(grid);
	mlx_loop(mlx);
	return (1);
}
