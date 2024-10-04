/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:11:03 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/10/04 17:09:15 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"


int main(void) {
    // Create a game instance
    t_game *game = malloc(sizeof(t_game));
    if (!game) {
        perror("Failed to allocate memory for game");
        return EXIT_FAILURE;
    }

    initialize_game(game);

    // Initialize the mlx instance
    game->mlx_p = mlx_init(S_W, S_H, "Raycaster", true);
    if (!game->mlx_p) {
        perror("Failed to initialize MLX");
        return EXIT_FAILURE;
    }

    // Set the player position in the game structure
    game->p_x = game->ply->x;
    game->p_y = game->ply->y;

    // Cast rays from the player's position
    cast_rays(game);

    // Render the game here if needed
    // ...

    // Clean up memory
    for (int i = 0; i < game->h_map; i++) {
        free(game->map[i]);
    }
    free(game->map);
    free(game->ply);
    free(game->ray);
    mlx_terminate(game->mlx_p); // Clean up the mlx instance
    free(game);

    return 0;
}
