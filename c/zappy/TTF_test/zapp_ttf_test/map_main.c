#include "SDL-1.2.15/include/SDL.h"
#include "SDL_ttf-2.0.11/SDL_ttf.h"
#include <unistd.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

SDL_Surface	*message = NULL;
SDL_Surface	*background = NULL;
SDL_Surface	*screen = NULL;

SDL_Surface		*load_image(char *filename)
{
	SDL_Surface	*loaded_image = NULL;
	SDL_Surface	*opti_img = NULL;

	loaded_image = SDL_LoadBMP(filename);//"img/ground.bmp");
	if (loaded_image != NULL)
	{
		//THIS IS TO CREAT AN IMAGE
		opti_img = SDL_DisplayFormat(loaded_image);

		SDL_FreeSurface(loaded_image);
	}
	return (opti_img);
}

void			apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *dest)
{
	//HERE I'm doing and rectangle to hold the offsets
	SDL_Rect	offset;

	offset.x = x;
	offset.y = y;

	SDL_BlitSurface(source, NULL, dest, &offset);
}

int	main(int ac, char **av)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
		return (1);

	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
	if (screen == NULL)
		return (1);
	SDL_WM_SetCaption("Zappy test", NULL);
	message = load_image("img/bebe.bmp");
	background = load_image("img/ground.bmp");
	apply_surface(0, 0, background, screen);
	apply_surface(320, 0, background, screen);
	apply_surface(320, 240, background, screen);
	apply_surface(0, 240, background, screen);
	apply_surface(180, 140, message, screen);
	if (SDL_Flip(screen) == -1)
		return (-1);
	SDL_Delay(5000);
	SDL_FreeSurface(message);
	SDL_FreeSurface(background);
	SDL_Quit();
	return (0);
	(void)ac;
	(void)av;
}