/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 09:26:27 by madumerg          #+#    #+#             */
/*   Updated: 2024/01/02 12:14:38 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// C program for DDA line generation 

#include "fdf.h"
#include <math.h> 
#include <stdio.h> 
/*
// Function for finding absolute value 
int abs(int n) { return ((n > 0) ? n : (n * (-1))); } 

// DDA Function for line generation 
void ft_DDA(int X0, int Y0, int X1, int Y1, t_vars vars) 
{
	// calculate dx & dy 
	int dx = X1 - X0; 
	int dy = Y1 - Y0; 

	// calculate steps required for generating pixels 
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 

	// calculate increment in x & y for each steps 
	float Xinc = dx / (float)steps; 
	float Yinc = dy / (float)steps; 

	// Put pixel for each step 
	float X = X0; 
	float Y = Y0; 
	for (int i = 0; i <= steps; i++) { 
		mlx_pixel_put(vars.mlx, vars.win, X, Y, ft_atoi_base("FF0000", "0123456789ABCDEF"));
		// put pixel at (X,Y) 
		X += Xinc; // increment in x at each step 
		Y += Yinc; // increment in y at each step 
		//delay(100); // for visualization of line- 
					// generation step by step 
	} 
}

// Driver program 

void drawline(t_vars vars, t_bresenham math)  
{
	math.dx = math.x2 - math.x1;
	math.dy = math.y2 - math.y1;
	math.x = math.x1;
	math.y = math.y1;
	math.m = 2 * math.dy - math.dx;

	while(math.x < math.x2)  
	{  
		if(math.m >= 0)  
		{  
			mlx_set_image_pixel(vars.mlx, vars.win, math.x, math.y, ft_atoi_base("FF0000", "0123456789ABCDEF")); 
			math.y = math.y + 1;
			math.m = math.m + 2 * math.dy - 2 * math.dx;
		}  
		else  
		{  
			mlx_set_image_pixel(vars.mlx, vars.win, math.x, math.y, ft_atoi_base("FF0000", "0123456789ABCDEF"));
			math.m = math.m + 2 * math.dy;  
			math.x = math.x + 1;  
		}
		mlx_set_image_pixel(vars.mlx, vars.win, math.x1, math.x2, ft_atoi_base("FF0000", "0123456789ABCDEF"));
		mlx_set_image_pixel(vars.mlx, vars.win, math.y1, math.y2, ft_atoi_base("FF0000", "0123456789ABCDEF"));
	}
}*/

# define WINDOW_WIDTH 700
# define WINDOW_HEIGHT 400

/*int	ft_sign_of_increment(int x1, int x2, int y1, int y2)
{
	int			sign_x;
	int			sign_y;

	if (x1 < x2)
	{
		sign_x += 1;
		return (sign_x);
	}
	else
	{
		sign_x -= -1;
		return (sign_x);
	}
	if (y1 < y2)
	{
		sign_y += 1;
		return (sign_y);
	}
	else
	{
		sign_y -= -1;
		return (sign_y);
	}
}*/
/*
void	ft_bresenham(t_vars vars, t_bresenham math)
{
	t_map	map;
	int		err;
	int		i;

	math.dx = abs(math.x2 - math.x1);
	math.dy = abs(math.y2 - math.y1);
	//ft_sign_of_increment(math.x1, math.x2, math.y1, math.y2);
	math.x = math.x1;
	math.y = math.y1;
	if (math.dx > math.dy)
	{
		err = math.dx / 2;
		i = 0;
		while (i < math.dx)
		{
			math.x += math.xi;
			err += math.dy;
			if (err > math.dx)
			{
				err -= math.dx;
				math.y += math.yi;
			}
			mlx_set_image_pixel(vars.mlx, vars.win, math.x1, math.x2, ft_atoi_base("FF0000", "0123456789ABCDEF"));
			i++;
		}
	}
	else
	{
		err = math.dy / 2;
		i = 0;
		while (i < math.dy)
		{
			math.y += math.yi;
			err += math.dx;
			if (err > math.dy)
			{
				err -= math.dy;
				math.x += math.xi;
			}
			mlx_set_image_pixel(vars.mlx, vars.win, math.x1, math.x2, ft_atoi_base("FF0000", "0123456789ABCDEF"));
			i++;
		}
	}
	mlx_set_image_pixel(vars.mlx, vars.win, math.x1, math.y1, ft_atoi_base("FF0000", "0123456789ABCDEF"));
	mlx_set_image_pixel(vars.mlx, vars.win, math.x2, math.y2, ft_atoi_base("FF0000", "0123456789ABCDEF"));
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
	t_bresenham	math = {2, 2, 14, 16};

	vars.mlx = mlx_init();	
	vars.win = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	mlx_loop_hook(vars.mlx, ft_update, &vars);
	mlx_on_event(vars.mlx, vars.win, 5, ft_close, (void *) &vars);
	mlx_on_event(vars.mlx, vars.win, 4, ft_close, (void *) &vars);
	mlx_on_event(vars.mlx, vars.win, 2, ft_close, (void *) &vars);
	mlx_on_event(vars.mlx, vars.win, 0, ft_keyboard, (void *) &vars);
	ft_bresenham(vars, math);
	vars.img = mlx_new_image(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx_set_image_pixel(vars.mlx, vars.img, math.x, math.y, map.color);
	mlx_loop(vars.mlx);
	free(vars.mlx);
}*/



/*int	main(void)
{
	t_vars	vars;
	t_bresenham	math = {2, 2, 14, 16};

	vars.mlx = mlx_init();	
	vars.win = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	mlx_hook(vars.win, 2, 1L<<0, ft_close, &vars);
	drawline(vars, math);
	mlx_loop(vars.mlx);
	
	mlx_new_image(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx_set_image_pixel(vars.mlx, void* img, int x, int y, int color)

	free(vars.mlx);
}*/
