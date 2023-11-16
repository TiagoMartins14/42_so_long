/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:59:47 by tiaferna          #+#    #+#             */
/*   Updated: 2023/11/16 13:07:08 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../../mlx_linux/mlx.h"

/* int	is_map_rectangular(int	fd_map)
{	
	int	base_val;
	int	len;

	base_val = ft_strlen(get_next_line(fd_map));
	len = 1;
	while (len)
	{
		len = ft_strlen(get_next_line(fd_map));
		if (len == -1)
			break ;
		if (base_val != len)
		{
			perror("Invalid map size.");
			exit(1);
		}
	}
	return (0);	
} */

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int shade_trgb(int color, double shade) //not wrking correctly yet
{
	int	shade_color;

	shade_color = create_trgb((int)(get_t(color) * shade), (int)(get_r(color) * shade), (int)(get_g(color) * shade), (int)(get_b(color) * shade));
	
	return (shade_color);
}

int	close_win(int keycode, t_vars *vars)
{
	ft_printf("%d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit (0);
	}
	return (0);
}

int	mouse_enter_hook(void)
{
	static int count = 1;
	printf("%d\n", count++);
	return (0);
}

void drawCircle(t_data img, int xc, int yc, int x, int y) 
{ 
	
    my_mlx_pixel_put(&img, xc+x, yc+y, 255); 
    my_mlx_pixel_put(&img, xc-x, yc+y, 255); 
    my_mlx_pixel_put(&img, xc+x, yc-y, 255); 
    my_mlx_pixel_put(&img, xc-x, yc-y, 255); 
    my_mlx_pixel_put(&img, xc+y, yc+x, 255); 
    my_mlx_pixel_put(&img, xc-y, yc+x, 255); 
    my_mlx_pixel_put(&img, xc+y, yc-x, 255); 
    my_mlx_pixel_put(&img, xc-y, yc-x, 255); 
} 
  
// Function for circle-generation 
// using Bresenham's algorithm 
void circleBres(t_data img, int xc, int yc, int r) 
{
    int x = 0, y = r; 
    int d = 3 - 2 * r; 
    drawCircle(img, xc, yc, x, y); 
    while (y >= x) 
    { 
        // for each pixel we will 
        // draw all eight pixels 
          
        x++; 
  
        // check for decision parameter 
        // and correspondingly  
        // update d, x, y 
        if (d > 0) 
        { 
            y--;  
            d = d + 4 * (x - y) + 10; 
        } 
        else
            d = d + 4 * x + 6; 
        drawCircle(img, xc, yc, x, y); 
        //delay(50); 
    } 
} 

int	move_right(int keycode, t_vars vars, t_data img, int xc, int yc, int r)
{
	ft_printf("%d\n", keycode);
	if (keycode ==  100)
	{
		circleBres(img, ++xc, ++yc, r);
		mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	}
	return (0);
}

int	main(void)
{
	t_data	img;
	t_vars	vars;
	int	x;
	int	y;
	int	reset_x;
	int reset_y;
	int color;	
	x = 0;
	y = 0;
	reset_x = x;
	reset_y = y;
	color = create_trgb(0, 255, 0, 0);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "so_long");
	img.img = mlx_new_image(vars.mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	// int	red = 255;
	// int	green = 0;
	// int	blue = 0;
	/* while(1)
	{
		y = reset_y;
		while (y <= 500)
		{
			x = reset_x;
			while (x <= 500)
			{
				color = create_trgb(0, red, green, blue);
				my_mlx_pixel_put(&img, x, y, color);
				x++;
			}
			y++;
		}
		if (red > 0 && blue == 0)
		{
			green++;
			red--;
		}
		if (green > 0 && red == 0)
		{
			blue++;
			green--;
		}
		if (blue > 0 && green == 0)
		{
			red++;
			blue--;
		}
		mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
		usleep(100000);
		ft_printf("%d %d %d\n", red, green, blue);
	} */
	int xc = 250;
	int yc = 250;
	int r = 200;
	circleBres(img, xc, yc, r);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, move_right, &vars);
	//mlx_hook(vars.win, 2, 1L<<0, close_win, &vars);
	mlx_hook(vars.win, 6, 1L<<6, mouse_enter_hook, &vars);
	mlx_loop(vars.mlx);
}
