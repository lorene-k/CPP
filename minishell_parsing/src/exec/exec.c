/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:11:32 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/16 15:59:09 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exec(t_data *data)
{
    
}

/*
- before loop : malloc fd tab + pid tab ?
- loop to create children
    IN CHILDREN
    - fork
    - open pipes
    - open files & check heredoc
    - redirect input
    - check builtins
    - exec cmd
- after loop : parent (cleanup & get exit status)
*/