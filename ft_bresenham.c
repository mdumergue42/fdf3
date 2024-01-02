/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:41:15 by madumerg          #+#    #+#             */
/*   Updated: 2024/01/02 18:22:04 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
# define WINDOW_WIDTH 700
# define WINDOW_HEIGHT 400
  #include <stdio.h>

void	ft_bresenham(t_vars vars, t_bresenham math)
{
	int	E;
	int	NE;

	math.dx = abs(math.x2 - math.x1);
	math.dy = abs(math.y2 - math.y1);
	math.x = math.x1;
	math.y = math.y1;
	E = 2 * math.dy;
	NE = 2 * (math.dy - math.dx);
	mlx_set_image_pixel(vars.mlx, vars.img, math.x, math.y, 0xFFFFFFFF);

	while (math.x <= math.x2)
	{
		printf("DX :%d\n", math.dx);
		printf("DY :%d\n", math.dy);
		printf("Y1 :%d\n", math.y);
		printf("Y2 :%d\n", math.y2);
		printf("x2 :%d\n", math.x2);
		printf("NE :%d\n", NE);
		printf("D :%d\n", math.d);
		if (math.d <= 0)
		{
			math.d += E;
			printf("E :%d\n", E);
			math.x += 1;
			printf("x :%d\n", math.x);
			mlx_set_image_pixel(vars.mlx, vars.img, math.x, math.y, 0xFFFF0000);
			math.d = math.d + 2 * math.dy - 2 * math.dx;
		}
		else if (math.d > 0)
		{
			printf("test y%d\n", math.y);
			math.d += NE;
			math.y += 1;
			math.x += 1;
			mlx_set_image_pixel(vars.mlx, vars.img, math.x, math.y, 0xFFFF0000);
			math.d = math.d + 2 * math.dy - 2 * math.dx;
		}
		
	}
}

int	ft_close(int keycode, void *vars)
{
	t_vars *v;

	v = (t_vars *) vars;
	printf("%d\n", keycode);
	if (keycode == 0)
	{
		mlx_loop_end(v->mlx);
		mlx_destroy_image(v->mlx, v->img);
		mlx_destroy_window(v->mlx, v->win);
		mlx_destroy_display(v->mlx);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int ft_update(void *quelquechose)
{
	return (0);
}

int ft_keyboard(int keycode, void *vars)
{
	t_vars *v;

	v = (t_vars *) vars;
	printf("%d\n", keycode);
	if (keycode == 41)
	{
		ft_close(0, vars);
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;
	t_map	map;
	t_bresenham	math = {0, 20, -2, 60};

	printf("init x1 : %d\n", math.x1);
	printf("init x2 : %d\n", math.x2);
	printf("init y1 : %d\n", math.y1);
	printf("init y2 : %d\n", math.y2);

	vars.mlx = mlx_init();	
	vars.win = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	mlx_loop_hook(vars.mlx, ft_update, &vars);
	mlx_on_event(vars.mlx, vars.win, 5, ft_close, (void *) &vars);
	mlx_on_event(vars.mlx, vars.win, 4, ft_close, (void *) &vars);
	mlx_on_event(vars.mlx, vars.win, 2, ft_close, (void *) &vars);
	mlx_on_event(vars.mlx, vars.win, 0, ft_keyboard, (void *) &vars);
	vars.img = mlx_new_image(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	ft_bresenham(vars, math);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, math.x, math.y);
	mlx_loop(vars.mlx);
	free(vars.mlx);
}