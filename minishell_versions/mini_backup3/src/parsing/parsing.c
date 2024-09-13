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


int count_pipes_new(char *s)
{
    int i;
    int words;

    words = 0;
	i = 0;
	while (s[i])
	{
        if(s[i] == '|')
            words++;
		i++;
	}
	return (words);
}


// Duplique le tableau de variable d'environnement (envp) en créant un nouveau malloc
char **dup_env_new(t_infos *infos)
{
    int i;
    char **new;

    i = 0;
    while (infos->new_envp[i]!=NULL)
        i++;
    new = ft_calloc(sizeof(char *), (i + 1));
    if(!new)
    {
        return (NULL);
    }
    i = 0;
    while (infos->new_envp[i]!=NULL)
    {
        new[i] = strdup(infos->new_envp[i]);
        i++;
    }
    new[i] = NULL;
    return (new);
}

// Crée la structure infos et y associe quelques valeurs
void create_infos(t_infos **infos, char *str, char **envp)
{
    char *path;

    int ret;

    *infos = ft_calloc(sizeof(t_infos), 1);
    if (!(*infos))
        free_infos_error(*infos);
    (*infos)->pipes_nb = count_pipes_new(str);
    (*infos)->new_envp = envp;
    (*infos)->new_envp = dup_env_new(*infos);
    if (!(*infos)->new_envp)
        free_infos_error(*infos);

    if (ret = env_var_exists(*infos, "PATH") == 1)
    {
        path = get_env_var((*infos), "PATH");
        if (!path)
            free_infos_error(*infos);
    	(*infos)->paths = ft_split(path, ':');
        free(path);
        if (!(*infos)->paths)
            free_infos_error(*infos);
    }
    else if (ret == -1)
    {
        free_infos_error(*infos);
    }
    else
    {
        path = NULL;
    }

    

    // AJOUTE
    (*infos)->input = str;
}



// Modifie la structure infos (comme create_infos mais appelé lors du deuxieme tour dans le while du main)
void update_infos(t_infos **infos, char *str, char **envp)
{
    char *path;

    if (*infos != NULL)
    {
    (*infos)->pipes_nb = count_pipes_new(str);
    // (*infos)->new_envp = envp;
    // (*infos)->new_envp = dup_env_new(*infos);
    // if (!(*infos)->new_envp)
    //     free_and_show_error(infos);
        // if ((*infos)->paths != NULL)
        //     free_split_new((*infos)->paths);


    // path = get_env_var((*infos), "PATH");
    // if (!path)
    //     free_and_show_error(infos);
	// (*infos)->paths = ft_split(path, ':');
    // free(path);
    // if (!(*infos)->paths)
    //     free_infos_error(*infos);


    // update_path(*infos);

    // AJOUTE
    (*infos)->input = str;
    }

}



// Modifie tous les arguments de toutes les commandes
void modify_all_cmd_args(t_infos **infos)
{
    int i;

    i = 0;
    t_cmd   *actual_cmd;
    while (i < (*infos)->cmd_nb)
    {
        actual_cmd = (*infos)->cmd[i];
        if (modify_args_cmd(actual_cmd, *infos) == -1)
        {
            protect_memory(*infos, NULL, NULL);
        }
        i++;
    }
}


// Crée les tokens (lexing) a partir de l'input puis crée les structures cmd en y insérant les arguments
void create_cmds(char *str, t_infos **infos)
{
    char    **cmd_tokens;

    char *tmp;




    // MON CODE (FONCTIONNE)
    cmd_tokens = generate_tokens_array(str, *infos); // MON CODE (et non celui de loerene)
    if (!cmd_tokens)
    {
                free_infos_error(*infos);

    }
    int i = 0;



    // EN PAUSE POUR TEST FUNCHECK
    // while(cmd_tokens[i]) 
    // {

    //     write(1, "P", 1);
	//     tmp = replace_str_var_new(*infos, cmd_tokens[i]); // EXPANSION !!!!
    //     if(!tmp)
    //     {
            
    //         free_infos_error(*infos);

    //     }


    //     free(cmd_tokens[i]);
    //     cmd_tokens[i] = tmp;
    //     i++;
    // }


    // LE CODE DE LORENE (NE FONCTIONE PAS : LEAKS)
    //cmd_tokens = generate_tokens_array(str, *infos); // LE CODE DE LORENE (erreur : il y a des leaks)


    if (create_commands(cmd_tokens, infos) == -1)
    {
             free_cmd_tokens(cmd_tokens);

                free_infos_error(*infos);

    }
    else
    {
     free_cmd_tokens(cmd_tokens);
    }


    modify_all_cmd_args(infos);

}




// Modifie les commandes en ajoutant et modifiant des valeurs a l'intérieur de leur structure
int modify_cmds(t_infos **infos, char **envp)
{
    
    set_default_cmd_values(infos); // OK
    set_infile_outfile(infos);  // OK
    if ((*infos)->sigint_heredoc == 1)
        return (-1);
    set_in_out_pipes_and_normal(infos); // OK
    set_all_cmd_path(infos, envp); //// OK
    return (0);
}


// Prepare en initialisant la structure infosm initialisant les variables denvironnement, creant les commandes
int parse(char  *str, t_infos **infos, char **envp)
{

    // A FAIRE : checker l'input pour voir si il y a de erreurs
    if(ft_strlen(str) == 0)
    {
        free(str);
        return (0);
    }

    // exit(123);
    
    // Cree la structure infos avec les variables denvironnement
    if (!(*infos))
    {


        //write(1, "ERR", 3);
        create_infos(infos, str, envp); // Si premiere fois


            // exit(124);

    }
    else
    {
        write(1, "ERR", 3);
        // exit(124);
        
        update_infos(infos, str, envp); // si deuxieme boucle dans main (while)
    }

        (*infos)->sigint_heredoc = 0;


    create_cmds(str, infos);

    // exit(124);


    show_cmd(infos);
    

    
    // SIGINT dans heredoc
    if (modify_cmds(infos, envp) == -1)
    {
        // printf("test erreur heredoc");
        free_infos_while(infos);
        return (0);
        // exit(1);
    }

    // exit(124);


            //char *toto = ft
             //   char *test = replace_str_var(infos, ft_strdup("$PWD et $?"));
              //  ft_putendl_fd(test, 1);


    // show_cmd(infos);
    show_cmd_in_out(infos);
    //show_cmd_args((*infos)->cmd[0]);
    return (1);
}