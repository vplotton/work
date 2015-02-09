#include "zappy_graph.h"

int ft_init_video(t_env *env)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        ft_putstr("Unable to init SDL:");
        ft_putstr(SDL_GetError());
        return (-1);
    }
    env->display->windows = SDL_SetVideoMode(D_WIDTH, D_HEIGHT, 16, SDL_HWSURFACE);
    if (env->display->windows == NULL)
    {
        ft_putstr("Unable to make windows:");
        ft_putstr(SDL_GetError());
        return (-1);
    }
    return (1);
}

int     ft_load_ground(t_env *env)
{
    SDL_Rect        *pos;
    SDL_Surface     *ground;

    pos = (SDL_Rect*)malloc(sizeof(SDL_Rect));
    pos->x = 0;
    pos->y = 0;
    env->display->g_pos = pos;
    ground = SDL_LoadBMP("img/ground.bmp");
    env->display->ground = ground;
    if (!env->display->ground)
    {
        printf("Unable to load ground: %s\n", SDL_GetError());
        return 1;
    }
    printf("post initney\n");
    return (1);
}
