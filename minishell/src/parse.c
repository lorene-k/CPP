/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:33:09 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/28 17:57:27 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

static void lexer_tester(t_token *token) //TEST
{
    t_token *curr;
    t_token *next;
    int i;
    
    i = 0;
    curr = token;
    while (curr)
    {
        next = curr->next;
        printf("token %d value : %s\t type : %d\n\n", i, curr->value, curr->type); //TEST
        curr = next;
        i++;
    }
    exit(0);
}

void    parse_input(t_data *data, char *line)
{
    t_token *token;
    
    token = NULL;
    token = lexer(token, line);
    free(line);
    lexer_tester(token); //TEST
    (void)data;
    // parser(token, data); //PARSE TOKENS
    clear_tokens(&token);
}
