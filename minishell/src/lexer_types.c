/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:18:36 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/23 18:48:00 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

void    get_type(t_token *token, int type)
{
    if (type == 1)
        get_alpha_type(token);
    if (type == 2)
        get_digit_type(token);
    if (type == 3)
        get_operator_type(token);
    if (type == 4)
        get_punctuation_type(token);
}
