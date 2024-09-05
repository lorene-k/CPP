#include "minishell.h"


static void free_split_new(char **split)
{
    int i;
    i = 0;
    while(split[i] != NULL)
    {
        free(split[i]);
        i++;
    }
    free(split);
}




// APPELE LORS D'ERREUR MALLOC
void free_infos_error(t_infos *infos)
{
    if (infos != NULL)
    {
        if ((infos)->new_envp != NULL)
            free_split_new((infos)->new_envp); // PROBLEME ICI
        if ((infos)->paths != NULL)
            free_split_new((infos)->paths);
        if ((infos)->pid != NULL)
            free((infos)->pid);
        if ((infos)->input != NULL)
            free((infos)->input);
        if ((infos)->tube != NULL)
            free((infos)->tube);
        // free_create_commands(infos); // A FAIRE
        free(infos);
    }
    exit(123);
}



// APPELE LORSQU'ON QUITTE MINISHELL (ctdl D)
void free_infos(t_infos **infos)
{
    if (*infos != NULL)
    {
        if ((*infos)->new_envp != NULL)
            free_split_new((*infos)->new_envp); // PROBLEME ICI
        if ((*infos)->paths != NULL)
            free_split_new((*infos)->paths);
        if ((*infos)->pid != NULL)
            free((*infos)->pid);
        if ((*infos)->input != NULL)
            free((*infos)->input);
        if ((*infos)->tube != NULL)
            free((*infos)->tube);
        // free_create_commands(infos);
        free(*infos);
        *infos = NULL;
    }
}



// APPELE LORSQU'UNE COMMANDE NA PAS ETE TROUVEE (sexecute dans le child)
void free_infos_child(t_infos **infos)
{
    if (*infos != NULL)
    {
        if ((*infos)->new_envp != NULL)
            free_split_new((*infos)->new_envp); // PROBLEME ICI
        if ((*infos)->paths != NULL)
            free_split_new((*infos)->paths);
        if ((*infos)->pid != NULL)
            free((*infos)->pid);
        if ((*infos)->input != NULL)
            free((*infos)->input);
        if ((*infos)->tube != NULL)
            free((*infos)->tube);
        free_create_commands(infos);
        free(*infos);
        *infos = NULL;
    }
}


// APPELE LORSQU'ON ARRIVE A LA FIN DU WHILE DANS LE MAIN
void free_infos_while(t_infos **infos)
{
    if (*infos != NULL)
    {
        // if ((*infos)->paths != NULL)
        //     free_split_new((*infos)->paths);
        if ((*infos)->pid != NULL)
        {
            free((*infos)->pid);
            (*infos)->pid = NULL;
        }
        if ((*infos)->input != NULL)
        {
            free((*infos)->input);
            (*infos)->input = NULL;
        }
        if ((*infos)->tube != NULL)
        {
            free((*infos)->tube);
            (*infos)->tube = NULL;
        }
        free_create_commands(infos);
        // free(*infos);
        // *infos = NULL;
    }
}

// A FINIR !!!!!!!
// APPELE LORS DE LA FIN DU WHILE PRINCIPAL DU PROGRAMME
// void free_infos_while(t_infos **infos)
// {
//     if (*infos != NULL)
//     {
//         if ((*infos)->new_envp != NULL)
//             free_split_new((*infos)->new_envp); // PROBLEME ICI
//         if ((*infos)->paths != NULL)
//             free_split_new((*infos)->paths);
//         if ((*infos)->pid != NULL)
//             free((*infos)->pid);
//         if ((*infos)->input != NULL)
//             free((*infos)->input);
//         if ((*infos)->tube != NULL)
//             free((*infos)->tube);
//         free_create_commands(infos);
//         free(*infos);
//         *infos = NULL;
//     }
// }
