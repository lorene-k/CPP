// #include "minishell.h"

// static void free_split_new(char **split)
// {
//     int i;
//     i = 0;
//     while(split[i] != NULL)
//     {
//         free(split[i]);
//         i++;
//     }
//     free(split);
// }


// int count_pipes_new(char *s)
// {
//     int i;
//     int words;

//     words = 0;
// 	i = 0;
// 	while (s[i])
// 	{
//         if(s[i] == '|')
//             words++;
// 		i++;
// 	}
// 	return (words);
// }


// // Duplique le tableau de variable d'environnement (envp) en créant un nouveau malloc
// char **dup_env_new(t_infos *infos)
// {
//     int i;
//     char **new;

//     i = 0;
//     while (infos->new_envp[i]!=NULL)
//         i++;
//     new = calloc(sizeof(char *), (i + 1));
//     i = 0;
//     while (infos->new_envp[i]!=NULL)
//     {
//         new[i] = strdup(infos->new_envp[i]);
//         i++;
//     }
//     new[i] = NULL;
//     return (new);
// }

// // Crée la structure infos et y associe quelques valeurs
// void create_infos(t_infos **infos, char *str, char **envp)
// {
//     char *path;

//     *infos = ft_calloc(sizeof(t_infos), 1);
//     if (!(*infos))
//         free_and_show_error(infos);
//     (*infos)->pipes_nb = count_pipes_new(str);
//     (*infos)->new_envp = envp;
//     (*infos)->new_envp = dup_env_new(*infos);
//     if (!(*infos)->new_envp)
//         free_and_show_error(infos);
//     path = get_env_var((*infos), "PATH");
//     if (!path)
//         free_and_show_error(infos);
// 	(*infos)->paths = ft_split(path, ':');
//     free(path);
//     if (!(*infos)->paths)
//         free_and_show_error(infos);
    

//     // AJOUTE
//     (*infos)->input = str;
// }



// // Modifie la structure infos (comme create_infos mais appelé lors du deuxieme tour dans le while du main)
// void update_infos(t_infos **infos, char *str, char **envp)
// {
//     char *path;

//     if (*infos != NULL)
//     {
//     (*infos)->pipes_nb = count_pipes_new(str);
//     // (*infos)->new_envp = envp;
//     // (*infos)->new_envp = dup_env_new(*infos);
//     // if (!(*infos)->new_envp)
//     //     free_and_show_error(infos);
//         if ((*infos)->paths != NULL)
//             free_split_new((*infos)->paths);


//     path = get_env_var((*infos), "PATH");
//     if (!path)
//         free_and_show_error(infos);
// 	(*infos)->paths = ft_split(path, ':');
//     free(path);
//     if (!(*infos)->paths)
//         free_and_show_error(infos);

//     // AJOUTE
//     (*infos)->input = str;
//     }

// }


// // Crée les tokens (lexing) a partir de l'input puis crée les structures cmd en y insérant les arguments
// void create_cmds(char *str, t_infos **infos)
// {
//     char    **cmd_tokens;

//     char *tmp;




//     // MON CODE (FONCTIONNE)
//     cmd_tokens = generate_tokens_array_new(str); // MON CODE (et non celui de loerene)
//     int i = 0;
//     while(cmd_tokens[i])
//     {
// 	    tmp = replace_str_var(*infos, cmd_tokens[i]); // EXPANSION !!!!
//         free(cmd_tokens[i]);
//         cmd_tokens[i] = tmp;
//         i++;
//     }


//     // LE CODE DE LORENE (NE FONCTIONE PAS : LEAKS)
//     // cmd_tokens = generate_tokens_array(str, *infos); // LE CODE DE LORENE (erreur : il y a des leaks)



//     if (cmd_tokens == NULL)
//         free_and_show_error(infos);
//     create_commands(cmd_tokens, infos);
//     free_cmd_tokens(cmd_tokens);
// }

// // Modifie les commandes en ajoutant et modifiant des valeurs a l'intérieur de leur structure
// void modify_cmds(t_infos **infos, char **envp)
// {
//     set_default_cmd_values(infos); // OK
//     set_infile_outfile(infos);  // OK
//     set_in_out_pipes_and_normal(infos); // OK
//     set_all_cmd_path(infos, envp); //// OK
// }


// // Prepare en initialisant la structure infosm initialisant les variables denvironnement, creant les commandes
// int parse(char  *str, t_infos **infos, char **envp)
// {

//     // A FAIRE : checker l'input pour voir si il y a de erreurs
    
//     // Cree la structure infos avec les variables denvironnement
//     if (!(*infos))
//     {
//         //write(1, "ERR", 3);
//         create_infos(infos, str, envp); // Si premiere fois
//     }
//     else
//     {
//         write(1, "ERR", 3);
        
//         update_infos(infos, str, envp); // si deuxieme boucle dans main (while)
//     }


//     create_cmds(str, infos);

//     show_cmd(infos);
    

    
//     modify_cmds(infos, envp);


//             //char *toto = ft
//              //   char *test = replace_str_var(infos, ft_strdup("$PWD et $?"));
//               //  ft_putendl_fd(test, 1);


//     //show_cmd(infos);
//     show_cmd_in_out(infos);
//     //show_cmd_args((*infos)->cmd[0]);
//     return (1);
// }



#include "minishell.h"

static int	count_pipes_new(char *s)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '|')
			words++;
		i++;
	}
	return (words);
}

static char	**dup_env_new(t_infos *infos)
{
	int		i;
	char	**new;

	i = 0;
	while (infos->new_envp[i] != NULL)
		i++;
	new = calloc(sizeof(char *), (i + 1));
	if (!new)
		return (protect_memory(infos, 0, 0), NULL);
	i = 0;
	while (infos->new_envp[i] != NULL)
	{
		new[i] = strdup(infos->new_envp[i]);
		if (!new[i])
			return (protect_memory(infos, 0, new), NULL);
		i++;
	}
	new[i] = NULL;
	return (new);
}

static int	create_infos(t_infos **infos, char *str, char **envp)
{
	char	*path;

	*infos = ft_calloc(sizeof(t_infos), 1);
	if (!(*infos))
		return(protect_memory(*infos, 0, 0));
	(*infos)->pipes_nb = count_pipes_new(str);
	(*infos)->new_envp = envp;
	(*infos)->new_envp = dup_env_new(*infos);
	if (!(*infos)->new_envp)
		return(protect_memory(*infos, 0, 0)); //CHECK
	path = get_env_var((*infos), "PATH");
	if (!path)
		return(protect_memory(*infos, 0, 0)); //CHECK
	(*infos)->paths = ft_split(path, ':');
	free(path);
	if (!(*infos)->paths)
		return (protect_memory(0, 0, 0));
	(*infos)->input = str;
	(*infos)->printed_error = 0;
	return (0);
}

static int	create_cmds(char *str, t_infos **infos)
{
	char	**cmd_tokens;
    char *tmp;
	int i;

	cmd_tokens = generate_tokens_array(str, *infos);

	i = -1;
    cmd_tokens = generate_tokens_array_new(str); // MON CODE (et non celui de loerene)
	if (!cmd_tokens)
		return (1);
	while (cmd_tokens[++i])
		printf("TEST : token value %d = %s\n", i, cmd_tokens[i]);
	exit(0);
    while(cmd_tokens[i])
    {
	    tmp = replace_str_var(*infos, cmd_tokens[i]); // EXPANSION !!!!
        free(cmd_tokens[i]);
        cmd_tokens[i] = tmp;
        i++;
    }
	create_commands(cmd_tokens, infos);
	free_cmd_tokens(cmd_tokens);
	return ((*infos)->return_code);
}

static int	modify_cmds(t_infos **infos, char **envp)
{
	set_default_cmd_values(infos);
	set_infile_outfile(infos); // LE IF A ETE SUPPRIME PAR IDRISS (ERREUR SINON)
	set_in_out_pipes_and_normal(infos);
	return (set_all_cmd_path(infos, envp));
}

int	parse(char *str, t_infos **infos, char **envp)
{
	if (ft_strlen(str) == 0 || create_infos(infos, str, envp))
		return (free(str), 1);
	if (create_cmds((*infos)->input, infos) || modify_cmds(infos, envp))
		return (1);
	// show_cmd(infos); //TEST
	// show_cmd_in_out(infos); //TEST
	return (0);
}
