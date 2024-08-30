#include "minishell.h"


int sig_id = 0;



char  *get_input(t_infos **infos)
{
    char    *input;
    
        input = readline("\033[1;32mminishell$\033[0m ");
        if (!input)
        {
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

    input = ft_calloc(sizeof(char), 512);
    ft_putstr_fd("prompt test> ", 1);
    if (read(0, input, 511) == 0)
    {
        free_infos(infos); // A APPELER UNIQUEMENT SI ON QUITTE LE PROGRAMME DEFINITIVEMENT
        ft_putendl_fd("\nexit", 1);
        free(input);
        exit(0);
    }
    (*ft_strchr(input, '\n')) = '\0';
    return input;
}




// int main(int argc, char **argv, char **envp)
// {
//     char *input;
//     t_infos *infos;

//     infos = NULL;


//     //signals_init_heredoc();

//     // ft_putendl_fd("\033[1;36mminishell$\033[0m", 1);

//    while (1) {

//     signals_init();

//         //sig_id = 777;

//     //input = get_input_test(&infos);
//     input = get_input(&infos); // OBLIGATOIRE POUR LES SIGNAUX ET LE HEREDOC ET LES COMMANDES BLOCANteS COMME CAT



//         parse(input, &infos, envp);


//         create_all_fd(&infos);

//         execute(&infos);


//         //test_env(infos, envp); // Leak ici

//         // Erreur ne marche pas SI readline et initenv (dans parsing.h) et test_env() A CORRIGER AJD
//         //free_infos(&infos); // A APPELER UNIQUEMENT SI ON QUITTE LE PROGRAMME DEFINITIVEMENT


//         free_infos_while(&infos);

//         //break;


//         // rl_replace_line("aaaaa", 0);


//         // test_env(infos, envp);
//         // a faire : vérifier que le parsing a réussi, sinon le malloc a pété, il faut tout free et arreter le programm
//         // Si on enleve le break puis ctrl + C pour arreter le prog, c'est NORMAL d'avoir un leak car le inptut n'eest pas free.
//         //  free_all(&infos, input);
//     // A FAIRE : gérer AUSSI la sortie 2 (sortie d'erreur) avec dup2
//     //free(input);
      
//     }
//     return (0);
// }



// int	main(int argc, char **argv, char **envp)
// {
// 	char 	*input;
// 	t_infos *infos;

// 	infos = NULL;
// 	while (1)
// 	{
// 		sig_init();
// 		input = get_input();
// 		if (!parse(input, &infos, envp))
// 		{
// 			create_all_fd(&infos);
// 			execute(&infos);
// 		}
// 		free_infos_while(&infos);
// 	}
// 	return (0);
// }


int	main(int argc, char **argv, char **envp)
{
	char 	*input;
	t_infos *infos;

	infos = NULL;
    signals_init_heredoc();
	while (1)
	{
		signals_init();
		//input = get_input(&infos);
        input = get_input_test(&infos);
		if (!parse(input, &infos, envp))
        {
			create_all_fd(&infos);
			execute(&infos);
		free_infos_while(&infos);
        }
	}
	return (0);
}