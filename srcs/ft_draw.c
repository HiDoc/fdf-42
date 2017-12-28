/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 11:12:34 by fmadura           #+#    #+#             */
/*   Updated: 2017/12/28 19:23:32 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_pix_put(t_grid *grid, t_point *point, int xmod, int ymod)
{
	mlx_pixel_put(grid->mlx,
			grid->win,
			point->x + xmod,
			point->y + ymod,
			point->color);
}

static void ft_draw_notflat(t_grid *grid, int x, int y)
{
	int AB;
	int AC;
	int BC;
	int i;
	int j;

	i = 2;
	AB = ft_distance(grid->grid[y][x], grid->grid[y][x + 1]);
	AC = ft_distance(grid->grid[y][x], grid->grid[y + 1][x + 1]);
	BC = ft_distance(grid->grid[y][x + 1], grid->grid[ y+ 1][x + 1]);
	int cmp = grid->grid[y][x]->z - grid->grid[y][x + 1]->z;
	while (i < AB)
	{
		j = 2;
		while (j < BC)
		{
			if ((cmp != 0 ||(i < RES && j < RES)) && (i >= j / (BC / RES)))
			ft_pix_put(grid, grid->grid[y][x], i + j / (BC / RES), j - (cmp < 0 ? i : 0));
			j++;
		}
		i++;
	}
}

static void ft_draw_notflat2(t_grid *grid, int x, int y)
{
	int AB;
	int BC;
	int i;
	int j;

	i = 2;
	AB = ft_distance(grid->grid[y][x], grid->grid[y + 1][x]);
	BC = ft_distance(grid->grid[y + 1][x], grid->grid[y + 1][x + 1]);
	int cmp = grid->grid[y + 1][x]->z - grid->grid[y + 1][x + 1]->z;
	while (i < BC)
	{
		j = 2;
		while (j < AB)
		{
			if ((cmp != 0 || (j < RES && i < RES)) && (i < j / (AB / RES)))
				ft_pix_put(grid, grid->grid[y][x], i + j / (AB / RES), j - (cmp < 0 ? i : 0));
			j++;
		}
		i++;
	}
}

static void ft_draw_line_one(t_grid *grid, t_point *p1, t_point *p2, int dir)
{
	int i;
	int pas;
	int cmp;

	i = 0;
	cmp = p1->z - p2->z;
	pas = ft_distance(p1, p2) / RES;
	while (i / pas < RES)
	{
		if (!(cmp))
			ft_pix_put(grid, p1, i / pas, dir ? i : 0);
		else
			ft_pix_put(grid, p1, i / pas, cmp > 0 ? i : -i);
		i++;
	}
}

int			ft_draw_lines(t_grid *grid)
{
	int		y;
	int		x;

	y = 0;
	while (y < grid->size_y)
	{
		x = 0;
		while (x < grid->size_x)
		{
			if (x + 1 < grid->size_x)
				ft_draw_line_one(grid, grid->grid[y][x], grid->grid[y][x + 1], 0);
			if (y + 1 < grid->size_y)
				ft_draw_line_one(grid, grid->grid[y][x], grid->grid[y + 1][x], 1);
			if (y + 1 < grid->size_y && x + 1 < grid->size_x)
			{
			//	if (grid->grid[y][x]->z == grid->grid[y][x + 1]->z
			//		&& grid->grid[y + 1][x]->z == grid->grid[y][x]->z
			//		&& grid->grid[y][x]->z == grid->grid[y + 1][x + 1]->z)
			//		ft_draw_flat(grid, x, y);
			//	else
			//	{
					ft_draw_notflat(grid, x, y);
					ft_draw_notflat2(grid, x, y);
			//	}
			}
			x++;
		}
		y++;
	}
	return (1);
}

int			ft_draw(char *file)
{
	t_grid	*grid;

	if ((grid = (ft_read(file))) == NULL)
		return (0);
	ft_draw_lines(grid);
	mlx_loop(grid->mlx);
	return (1);
}
