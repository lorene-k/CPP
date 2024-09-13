#include "minishell.h"


int sig_id = 0;



char  *get_input(t_infos **infos)
{
    char    *input;
        input = readline("\033[1;32mminishell$\033[0m ");
        if (!input)
        {
            // exit(1);
            // Ctrl - D a été appuyé
            //printf("ctrl d readline");

            free_infos(infos); // A APPELER UNIQUEMENT SI ON QUITTE LE PROGRAMME DEFINITIVEMENT
            ft_putendl_fd("exit", 1);
           // free(input);
            exit(0);
        }
        add_history(input);
        return (input);
}


char    *get_input_test(t_infos **infos)
{
    char *input;

    int i;

    i = 0;

    input = ft_calloc(sizeof(char), 512);
    if(!input)
        exit(1);
    ft_putstr_fd("\033[1;32mminishell TEST$\033[0m ", 1);
    if ((i = read(0, input, 511)) == 0)
    {
        free_infos(infos); // A APPELER UNIQUEMENT SI ON QUITTE LE PROGRAMME DEFINITIVEMENT
        ft_putendl_fd("\nexit", 1);
        free(input);
        exit(0);
    }
    else if (i < 0)
    {
        free(input);
        exit(1);
    }
    
    (*ft_strchr(input, '\n')) = '\0';
    return input;
}



// // PROBLEME ICI : NE FONCTIONNE PAS AVEC LE free_infos // FONCTIONNE UNQUEMENT AVEC LE VRAI READLINE
// void test_env(t_infos *infos, char **envp)
// {
//     //init_env_var(infos, envp);
//     //printf("test");
//     //add_env_var(infos, "AAA", "TOTO TEST"); // A FAIRE : corriger les leaks
//     //remove_env_var(infos, "AAA"); // A FAIRE : corriger les leaks
//     //add_env_var(infos, "PATH", "FFF TEST"); // A FAIRE : corriger les leaks
//     char *test = replace_str_var(infos, "contenu $PATH");
//     ft_putstr_fd("Contenu test : ", 1);
//     ft_putstr_fd(test, 1);
//     ft_putstr_fd("\n", 1);
//     free(test);
//     //printf("%s", test);
// }


int main(int argc, char **argv, char **envp)
{
    char *input;
    t_infos *infos;

    infos = NULL;

    (void)argc;
    (void)argv;
    //signals_init_heredoc();

    // ft_putendl_fd("\033[1;36mminishell$\033[0m", 1);

   while (1) {
    signals_init();
    
    input = get_input_test(&infos); // ne fonctionne pas avec ctrl D et SIGINT et commande cat par ex
    // input = get_input(&infos); // OBLIGATOIRE POUR LES SIGNAUX ET LE HEREDOC ET LES COMMANDES BLOCANteS COMME CAT


       if (parse(input, &infos, envp) != 0)
       {

        // exit()

        // sig_id = 0;


        create_all_fd(&infos);

        // exit(124)

        // sig_id = 0;

        execute(&infos);

        //exit(124);

        free_infos_while(&infos);
        //break;
       }


      
    }
    return (0);
}