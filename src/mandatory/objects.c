/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patatoss <patatoss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:26:12 by patatoss          #+#    #+#             */
/*   Updated: 2023/11/19 16:46:10 by patatoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player(t_image *player)
{
	player->front = "./assets/player_front.xpm";
	player->back = "./assets/player_back.xpm";
	player->right = "./assets/player_right.xpm";
	player->left = "./assets/player_left.xpm";
}
