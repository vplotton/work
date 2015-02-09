/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_test2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 23:36:56 by jbernabe          #+#    #+#             */
/*   Updated: 2014/06/12 04:52:49 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "zappy_graph.h"
#include "SDL-1.2.15/include/SDL.h"
#include "SDL_ttf-2.0.11/SDL_ttf.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;
SDL_Surface *message = NULL;
SDL_Surface *screen = NULL;
SDL_Surface	*player = NULL;
SDL_Surface *img_fond = NULL;
SDL_Surface *font = NULL;

int 	init_sdl()
{
	if (SDL_Init(SDL_INIT_VIDEO)) == -1)
		return (-1);
	if (!(screen = SDL_SetVideoMode(D_WIDTH, D_HEIGHT, SCREEN_BPP, SDL_SWSURFACE)))
		return (-1);
	if(TTF_Init() == -1)
        return (-1);    
    return (0);
}

int 		load_files()
{
	if (!(img_fond = SDL_LoadBMP("../pack_images_sdz/lac_en_montagne.bmp")))
		return (-3);
	if (!(player = SDL_LoadBMP("img_menu/pikachu.bmp")))
		return (-2);
	if (!(font = TTF_OpenFont( "ttf_img/lazy.ttf", 28 );))
}

int	main(int ac, char **av)
{
	SDL_Rect	post_fond;
	SDL_Event	envent;	
	int 		counter;

	post_fond.x = 0;
	post_fond.y = 0;
	counter = 1;

	SDL_Color textColor = { 255, 255, 255 };
	SDL_WM_SetIcon(SDL_LoadBMP("../pack_images_sdz/sdl_icone.bmp"), NULL);
	SDL_WM_SetCaption("Zappy menu test", NULL);
	
	SDL_BlitSurface(img_fond, NULL, screen, &post_fond);
	message = TTF_RenderText_Solid(font, "Pequeno test ttf", textColor);
	SDL_Flip(screen);
	// while (counter != 0)
	// {
	// 	SDL_BlitSurface(player, NULL, screen, &post_fond);
	// 	//SDL_SetColorKey(dunky, SDL_SRCCOLORKEY, SDL_MapRGB(dunky->format, 0, 0, 255));
	// 	SDL_Flip(screen);
	// 	if ((envent.(int)type == SDL_Quit  || envent.type == SDLK_ESCAPE)
	// 	{
	// 		counter = 0;
	// 		break ;
	// 	}
	// }
	SDL_FreeSurface(img_fond);
	SDL_FreeSurface(player);
	SDL_FreeSurface(message);
	SDL_Quit();
	return (0);
	(void)ac;
	(void)av;
}