#include "zappy_graph.h"

static void check_player(t_env *env, int x, int y, SDL_Surface *img)
{
    int     i;
    SDL_Surface     *player;
    SDL_Rect        pos;
    //SDL_Surface     *original_pict;
    pos.x = 0;
    pos.y = 0;
    pos.w = 30;
    pos.h = 30;
    i = 0;
   //original_pict = img;

    while(i < MAX_PLAYER)
    {
        if (env->map[y][x].ids[i] == TRUE)
        {
            printf("player\n");
            player = SDL_LoadBMP("img/player.bmp");
            SDL_BlitSurface(player, NULL, img, &pos);
            SDL_FreeSurface(player);
            return ;
        }
        i++;
    }
    player = SDL_LoadBMP("img/ground.bmp");
    SDL_BlitSurface(player, NULL, img, &pos);
    SDL_FreeSurface(player);
}

static  void check_rsc(t_env *env, int x, int y)
{
    int             i;
    SDL_Rect        pos;
    SDL_Surface     *img;
    int             j;

    pos.w = 10;
    pos.h = 10;
    i = 0;
    pos.y = y * 50;
    while( i < 7)
    {
            if (env->map[y][x].rsrc[i] == 1)
            {
                //printf("coord x =%d y = %d\n", x, y);
                if (i < 5)
                    pos.x = x * 50 + i * 10;
                else if (i == 5)
                {
                    pos.y = y * 50 + 12;
                    pos.x = 0;
                    j = 0;
                }
                else
                    pos.x = x * 50 + j * 10;
               // printf("x =%d y = %d\n", pos.x, pos.y);
                img = SDL_LoadBMP("img/rsc1.bmp");
                SDL_BlitSurface(img, NULL, env->display->windows, &pos);

            }
            i++;
    }

}

int         ft_display_ground(t_env *env)
{
    int     i;
    int     j;

    j = 0;
    i = 0;
    env->display->g_pos->w = WGROUND;
    env->display->g_pos->h = HGROUND;
    //changer le 50 par taille de la texture
    while (i < HEIGHT)
    {
        j = 0;
        //printf("1ndpost i = %d j = %d\n", i, j);
        env->display->g_pos->y = i * HGROUND;
        //printf("2ndpost i = %d j = %d\n", i, j);
        //printf("post i = %d j = %d\ et x = %d y = %d\n", i,j,  (int)env->display->g_pos->x, (int)env->display->g_pos->y);
        while (j < WIDTH)
        {
            env->display->g_pos->x = j * WGROUND;
            //printf("2ndpost i = %d j = %d et x = %d y = %d\n", i, j,  (int)env->display->g_pos->x, (int)env->display->g_pos->y);
            SDL_BlitSurface(env->display->ground, NULL, env->display->windows, env->display->g_pos);

            check_rsc(env, j, i);
            check_player(env, j, i, env->display->ground);
            j++;
        }
        //printf("outpost i = %d j = %d\ et x = %d y = %d\n", i,j,  (int)env->display->g_pos->x, (int)env->display->g_pos->y);
        i++;
    }
                printf("blit\n");
    printf("end i = %d j = %d et x = %d y = %d\n", i,j,  (int)env->display->g_pos->x, (int)env->display->g_pos->y);
    SDL_Flip(env->display->windows);
    return (1);
}

