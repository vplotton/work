#include "zappy_graph.h"

static void ft_pause(t_env *env)
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    SDL_BlitSurface(env->display->ground, NULL, env->display->windows, env->display->g_pos);
    SDL_Flip(env->display->windows);
    }
    printf("post video\n");
}

int main ( int argc, char** argv )
{
    t_env           *env;
    t_display       *display;
   // redirect error file to console
    freopen("CON", "w", stdout);
    freopen("CON", "r", stdin);
    freopen("CON", "w", stderr);
    argc += 1;
    (void)argv;
    // init env, thx bugmaster vianney
    if (init(&env) == FALSE)
		return (-1);
    printf("post init vianney\n");
    display = (t_display*)malloc(sizeof(t_display));
    env->display = display;
 // initialize SDL video and make new windows
    if (ft_init_video(env) < 0)
        return (-1);
        printf("post init video\n");
    // load an image
    //while (1)
        //ft_anim_player(env, sprite);
   // return (1);
    ft_load_ground(env);
    //SDL_FillRect (env.display->windows, NULL, SDL_MapRGB(env.display->windows->format, 0,255,255));
    //SDL_BlitSurface(env.display->ground, NULL, env.display->windows, env.display->g_pos);
    //SDL_Flip(env.display->windows);
    printf("post load img\n");
  //  ft_interface(env);
    ft_display_ground(env);
    printf("post display\n");
    ft_pause(env);
    // all is well ;)



    SDL_FreeSurface(env->display->ground);
    SDL_Quit();
    printf("Exited cleanly\n\n");
    return 0;
}

