# include "SDL-1.2.15/include/SDL.h"

int	main(int ac, char **av)
{
	SDL_Surface*	hello = NULL;
	SDL_Surface*	screen = NULL;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Init(SDL_INIT_VIDEO);
	screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
	hello = SDL_SWSURFACE_LoadBMP("img/player.bmp");

	SDL_BlitSurface(hello, NULL, screen, NULL);
	SDL_Flip(screen);
	SDL_Delay(2000);
	SDL_FreeSurface(hello);
	SDL_Quit();
	return (0);
	(void)ac;
	(void)av;
}
