/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_gettypes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:04:02 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/21 17:23:22 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

void     ft_getspecchar(t_token *token, char *line, int *i)
{
    if (ft_isoperator(line[*i])) //DO FUNCTION
    {
        get_operator_value(token, line, i);
        //get_operator_type
    }
    else if (ft_ispunctuation(line[*i])) //DO FUNCTION
    {
        token->value = line[*i];
        //get_punctuation_type
    }
}

void     ft_getconstant(t_token *token, char *line, int *i)
{
    if (ft_isalpha(line[*i]))
    {
        get_alpha_value(token, line, i);
        //get_alpha_type(token, line, i);
    }
    else if (ft_isdigit(line[*i]))
    {
        get_digit_value(token, line, i);
        //get_num_type
    }
}

/* LEXER
    TYPES
    - constants (integers, doubles, characters, strings)
    - operators (arithmetic, logical, relational)
    - punctuation (commas, semicolons, braces)
    - keywords (reserved words with predefined meanings like if, while, return) */


operators :
**
&&
||
!=
=
!
+
/
%
-
< 
>
>>
<<

