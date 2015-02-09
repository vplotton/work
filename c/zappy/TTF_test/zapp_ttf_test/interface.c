#include "zappy_graph.h"
// remplacer player par le nombre de team defini au lancement du serveur
//mettre un cahr ** avec le nom des team dans proto ?

static void  ft_init_itf(t_env    *env)
{
    t_interface itf;
    int         i;
    int         j;

    i = 0;
    itf.team = (t_team*)malloc(sizeof(t_team) * PLAYERS);
    printf("init interface 1 ok\n");
    while (i < PLAYERS)
    {
        printf("init interface goooo ok\n");
        itf.team[i].trsc = (int*)malloc(sizeof(int) * 7);
        printf("init interface i=%d ok\n", i);
        itf.team[i].lvl = (int*)malloc(sizeof(int) * 8);
        printf("init interface i=%d ok\n", i);
        j = 0;
        while (j < 7)
        {
            printf("init interface j=%d ok\n", j);
            itf.team[i].trsc[j] = 0;
            itf.team[i].lvl[j] = 0;
            printf("init interface j=%d ok\n", j);
            j++;
        }
        itf.team[i].lvl[++j] = 0;
        itf.team[i].name = ft_strdup("tourte");
        itf.team[i].nb_ply = 0;
        i++;
    }
    env->itf = &itf;
}

static void     ft_get_team_info(t_player player, t_team *team)
{
    int     i;

    i = 0;
    printf("team infooooooooooooo\n");
    team->lvl[player.lvl] += 1;
    while (i < 7)
    {
        team->trsc[i] += player.rsrc[i];
        i++;
    }
    team->nb_ply++;
}

static void    ft_read_team(t_env *env, int x, int y)
{
    int     i;
    int     j;

    j = 0;
    i = 0;
    while (i < MAX_PLAYER)
    {
        j = 0;
        if (env->map[y][x].ids[i] == TRUE)
        {
             while (j < PLAYERS && ft_strcmp(env->pl[i].team, env->itf->team[j].name) != 0)
                   j++;
            ft_get_team_info(env->pl[i], &(env->itf->team[j]));
        }
        i++;
    }
}


void    ft_interface(t_env  *env)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    ft_init_itf(env);
    printf("init interface ok\n");
    while (i < HEIGHT)
    {
        j = 0;
        while (j < WIDTH)
        {
            ft_read_team(env,j, i);
            j++;
        }
        i++;
    }
        printf(" %d player dans la team %s avec %d ressource[5] et %d level[0]\n",
               env->itf->team[1].nb_ply,  env->itf->team[1].name,  env->itf->team[1].trsc[5], env->itf->team[1].lvl[0] );
}
/*
void    ft_draw_interface(t_env *env)
{
    ft_read_team();

}
*/
