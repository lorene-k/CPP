/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:51:00 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/03/08 10:18:39 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_lay	init_lay(void)
{
	t_lay	lay;

	lay.row = 0;
	lay.col = 0;
	lay.exit = 0;
	lay.coll = 0;
	lay.play = 0;
	return (lay);
}

t_check	init_check(void)
{
	t_check	check;

	check.inv_char = 0;
	check.inv_coll = 0;
	check.inv_exit = 0;
	check.inv_play = 0;
	check.inv_row = 0;
	check.inv_walls = 0;
	return (check);
}
