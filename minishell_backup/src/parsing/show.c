#include "minishell.h"

// Affiche les arguments des commandes contenues dans info
void show_cmd(t_infos **infos)
{
            int i = 0;
            int j = 0;
            puts("");
            // (*infos)->cmd[i]
            puts("--- parcours de args--");
            while (i < (*infos)->cmd_nb)
            {

                ft_putstr_fd(" \n ", 1);
                j = 0;
                while ((*infos)->cmd[i]->args[j] != NULL)
                {
                    ft_putstr_fd((*infos)->cmd[i]->args[j], 1);      
                              ft_putstr_fd(" | ", 1);
                    j++;
                }
                
                
                i++;
            }
}


// Affiche les arguments des commandes contenues dans info
void show_cmd_in_out(t_infos **infos)
{
            int i = 0;
            ft_putstr_fd("\n--- parcours des type de infile outfile --\n", 1);
            while (i < (*infos)->cmd_nb)
            {
                ft_putstr_fd(" \n ", 1);
                    ft_putstr_fd("infile : ", 1);
                    ft_putnbr_fd((*infos)->cmd[i]->intype, 1);
                    ft_putstr_fd(" ET outfile : ", 1);
                    ft_putnbr_fd((*infos)->cmd[i]->outtype, 1);
                i++;
            }
            ft_putstr_fd("\n--- fin du parcours --\n", 1);

}



void show_cmd_args(t_cmd *cmd)
{
    int i;

    i = 0;
    puts("\n --- affichage des args de la commande  ----");
    while(cmd->args[i] != NULL)
    {
        ft_putstr_fd(cmd->args[i], 1);
        puts("\n-");
        i++;
    }
    puts("--- fin de l'affichage --- ");



}

void    show_fd(t_infos *infos)
{
    int i;
    i = 0;
    while (i < infos->cmd_nb)
    {

        ft_putstr_fd("\n ------ COMMMANDE numero : ", 1);
        ft_putnbr_fd(i, 1);
        ft_putstr_fd("\n fd in de la commande : ", 1);
        ft_putnbr_fd((infos->cmd[i]->fd_in), 1);
        ft_putstr_fd("\n fd out de la commande : ", 1);
        ft_putnbr_fd((infos->cmd[i]->fd_out), 1);
        ft_putstr_fd("\n --------------------- \n", 1);
        i++;
    }
}