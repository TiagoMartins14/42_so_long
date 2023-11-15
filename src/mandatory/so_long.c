/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:59:47 by tiaferna          #+#    #+#             */
/*   Updated: 2023/11/15 11:58:20 by tiaferna         ###   ########.fr       */
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

int shade_trgb(int color, double shade)
{
	int	shade_color;

	shade_color = create_trgb((int)(get_t(color) * shade), (int)(get_r(color) * shade), (int)(get_g(color) * shade), (int)(get_b(color) * shade));
	
	return (shade_color);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int	x;
	int	y;
	int	reset_x;
	int color;

	x = 200;
	y = 200;
	reset_x = x;
	color = create_trgb(0, 255, 0, 0);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "so_long");
	img.img = mlx_new_image(mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	while (y <= 300)
	{
		color = create_trgb(0, 255, 0, 0);
		x = reset_x;
		while (x <= 300)
		{
			color = shade_trgb(color, 1);
			if (x> 210)
				color = shade_trgb(color, 0.8);
			if (x > 225)
				color = shade_trgb(color, 0.6);
			if (x > 250)
				color = shade_trgb(color, 0.4);
			if (x > 275)
				color = shade_trgb(color, 0.2);
			if (x > 290)
				color = shade_trgb(color, 0.0);
			my_mlx_pixel_put(&img, x, y, color);
			mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
			x++;
		}
		y++;
	}
	mlx_loop(mlx);
}
