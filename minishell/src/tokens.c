/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:09:59 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/21 17:23:44 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

void    init_token(t_token *token, char *value)
{
    token = malloc(sizeof(t_token));
    if (!token)
        return (NULL);
    token->value = value;
    token->type = 0;
    token->next = NULL;
    token->prev = NULL;
}

//if token > 1, lstaddback