#include "minishell.h"



void signal_handler(int signo)
{
    if(signo == SIGINT)
    {
        sig_id = 128 + SIGINT;
        write(1, "\n", 1);
        rl_replace_line("", 0); // Pour effacer si texte dans pipeline
        rl_on_new_line();
        rl_redisplay();
    }

}



void signal_handler_execution(int signo)
{
    if(signo == SIGINT)
    {

        ft_putendl_fd("DANS EXECUTION SIG", 1);
        sig_id = 128 + SIGINT;
//        write(1, "\n", 1);
        rl_replace_line("", 0); // Pour effacer si texte dans pipeline
  //      rl_on_new_line();
        rl_redisplay();
    }

}



void signal_handler_heredoc(int signo)
{    if(signo == SIGINT)
    {
        sig_id = 128 + SIGINT;
        //write(1, "\n", 1);
        rl_replace_line("", 0); // Pour effacer si texte dans pipeline
        rl_on_new_line();
        rl_redisplay();
        rl_done = 1;
    }

}


int sig_event()
{
    return (0);
}

// APPELE A LA FIN DU heredoc et au debut du programme
void signals_init()
{
        // UNIQUEMENT POUR LE HEREDOC
        //rl_event_hook = sig_event;

        signal(SIGINT, signal_handler);
        //signal(SIGTERM, signal_handler);
        signal(SIGQUIT, SIG_IGN);
}


// APPELE AVANT EXECUTION
void signals_init_execution()
{
        // UNIQUEMENT POUR LE HEREDOC
        //rl_event_hook = sig_event;

        signal(SIGINT, signal_handler_execution);
        //signal(SIGTERM, signal_handler);
        signal(SIGQUIT, SIG_IGN);
}


// APPELE avant dentrer dans le heredoc
// POUR MARCHER il faut mettre une condition sig_id == 0 dans le while du heredoc
void signals_init_heredoc()
{
        //sig_id = 0; // FAUX A REVOIR
        rl_event_hook = sig_event;
        signal(SIGINT, signal_handler_heredoc);
        //signal(SIGTERM, signal_handler);
        signal(SIGQUIT, SIG_IGN);

}
