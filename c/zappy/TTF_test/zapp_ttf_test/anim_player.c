#include "zappy_graph.h"

void    ft_anim_player(t_env *env, t_sprite sprite)
{
    int     width = 256;
    int     height = 448;
    SDL_Rect    anm[4];
   // t_sprite    sprite;


//    SDL_SetColorKey( &sprite.image, SDL_SRCCOLORKEY, SDL_MapRGB( sprite.image->format, 255, 0, 0 ) );
    sprite.height = height / 8;
    sprite.width =  width / 14;

    anm[0].x = 0;
    anm[0].y = 0;
    anm[0].w = 128/4;
    anm[0].h =  128/4;

    SDL_BlitSurface( sprite.image,&anm[0], env->display->windows, &anm[0]);
    SDL_Flip(env->display->windows);
    SDL_Delay(30);
    anm[1].x =  128/4 * 1;
    anm[1].y = 128/4;
    anm[1].w = 128/4;
    anm[1].h = 128/4;
    SDL_BlitSurface( sprite.image, &anm[1], env->display->windows, &anm[0]);
    SDL_Flip(env->display->windows);
    SDL_Delay(30);
    anm[2].x =  128/4* 2;
    anm[2].y = 128/4;
    anm[2].w =  128/4;
    anm[2].h =  128/4;
    SDL_BlitSurface( sprite.image, &anm[2], env->display->windows, &anm[0]);
    SDL_Flip(env->display->windows);
   // SDL_FreeSurface(sprite.image);
    SDL_Delay(30);
}
