/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:39:30 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/03/14 03:52:38 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* 
Initialization: We start by initializing an empty stack to store the points that need to be processed.
Push Operation: When we encounter a pixel that needs to be processed, we push its coordinates onto the stack.
Pop Operation: We pop a point from the stack to process it. Popping retrieves the top element of the stack and decrements the top pointer.
Flood Fill Algorithm: We use a loop to repeatedly pop points from the stack and process them until the stack is empty.

*/

void push(t_point *stack, int *top, t_point p, int size) 
{
    if (*top < size - 1) // Ensure stack is not full
        stack[++(*top)] = p; // Increment top and add the point to the stack
}

t_point pop(t_point *stack, int *top) 
{
    if (*top >= 0) 
        return stack[(*top)--]; // Return the top element and decrement top
    t_point null_point = {-1, -1}; // Return a point outside the bounds if stack is empty
    return (null_point);
}

void flood_fill(char **map, t_point size, t_point start) 
{
    t_point stack[size.x * size.y];
    int top = -1;
    push(stack, &top, start); // Push the starting point onto the stack

    while (top >= 0) 
    {                               // Continue until the stack is empty
        t_point cur = pop(stack, &top); // Pop a point from the stack
        start.x = cur.x;
        start.y = cur.y;

        // Check if the current point is within bounds and has the old color
        if (x < 0 || x >= size.x || y < 0 || y >= size.y || map[start.x][start.y] == 'F' || map[start.x][start.y] == '1' ||) 
            continue; // Skip processing this point if conditions are not met

        // Update the color of the current point
        map[start.x][start.y] = 'F';

        // Push neighboring points onto the stack
        push(stack, &top, (t_point){start.x + 1, start.y}); // Right
        push(stack, &top, (t_point){start.x - 1, start.y}); // Left
        push(stack, &top, (t_point){start.x, start.y + 1}); // Down
        push(stack, &top, (t_point){start.x, start.y - 1}); // Up
    }
}