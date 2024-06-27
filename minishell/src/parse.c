/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:33:09 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/27 17:12:14 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

void    parse_input(t_data *data, char *line)
{
    t_token token;
    
    lexer(data, &token, line);
    printf("token value : %s\ntoken type : %d", data->token->value, data->token->type); //TEST
    exit(0);
    // parser(token, data); //PARSE TOKENS
}
