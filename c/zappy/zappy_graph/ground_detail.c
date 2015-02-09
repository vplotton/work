/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ground_detail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 19:34:14 by cycharbo          #+#    #+#             */
/*   Updated: 2014/06/26 22:48:30 by cycharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy_graph.h"

SDL_Surface		**ft_init_flower(SDL_Surface **flower)
{
	flower = (SDL_Surface**)malloc(sizeof(SDL_Surface*) * 6);
	flower[0] = SDL_LoadBMP("img/fleur2.bmp");
	SDL_SetColorKey(flower[0], SDL_SRCCOLORKEY,
			SDL_MapRGB(flower[0]->format, 255, 255, 0));
	flower[1] = SDL_LoadBMP("img/fleur1.bmp");
	SDL_SetColorKey(flower[1], SDL_SRCCOLORKEY,
			SDL_MapRGB(flower[1]->format, 255, 255, 0));
	flower[2] = SDL_LoadBMP("img/fleur3.bmp");
	SDL_SetColorKey(flower[2], SDL_SRCCOLORKEY,
			SDL_MapRGB(flower[2]->format, 255, 255, 0));
	flower[3] = SDL_LoadBMP("img/fleur4.bmp");
	SDL_SetColorKey(flower[3], SDL_SRCCOLORKEY,
			SDL_MapRGB(flower[3]->format, 255, 255, 0));
	flower[4] = SDL_LoadBMP("img/fleur5.bmp");
	SDL_SetColorKey(flower[4], SDL_SRCCOLORKEY,
			SDL_MapRGB(flower[4]->format, 255, 255, 0));
	flower[5] = SDL_LoadBMP("img/fleur1.bmp");
	SDL_SetColorKey(flower[5], SDL_SRCCOLORKEY,
			SDL_MapRGB(flower[5]->format, 255, 255, 0));
	return (flower);
}
