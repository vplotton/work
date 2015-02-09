/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_zappy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 01:39:07 by jbernabe          #+#    #+#             */
/*   Updated: 2014/06/11 03:39:08 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy_graph.h"
#include "SDL-1.2.15/include/SDL.h"
#include "SDL_ttf-2.0.11/SDL_ttf.h"

const int SCREEN_BPP = 32;

int	main(int ac, char **av)
{
	SDL_Surface *screen;
	SDL_Surface	*player;
	SDL_Surface *img_fond;
	SDL_Surface *dunky;
	SDL_Rect	post_fond;
	SDL_Rect	dunky_post;

	post_fond.x = 0;
	post_fond.y = 0;
	dunky_post.x = 500;
	dunky_post.y = 260;

	img_fond = NULL;
	screen = NULL;
	player = NULL;
	screen = SDL_SetVideoMode(D_WIDTH, D_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
	SDL_WM_SetIcon(SDL_LoadBMP("../pack_images_sdz/sdl_icone.bmp"), NULL);
	SDL_WM_SetCaption("Zappy menu test", NULL);
	img_fond = SDL_LoadBMP("../pack_images_sdz/lac_en_montagne.bmp");
	SDL_BlitSurface(img_fond, NULL, screen, &post_fond);
	dunky = SDL_LoadBMP("../pack_images_sdz/zozor.bmp");
	SDL_SetColorKey(dunky, SDL_SRCCOLORKEY, SDL_MapRGB(dunky->format, 0, 0, 255));
	/*this line is to do a transparence*/
	SDL_SetAlpha(dunky, SDL_SRCALPHA, 190);
	SDL_BlitSurface(dunky, NULL, screen, &dunky_post);
	SDL_Flip(screen);
	pause();
	SDL_FreeSurface(img_fond);
	SDL_FreeSurface(dunky);
	SDL_Quit();
	return (0);
	(void)ac;
	(void)av;
}