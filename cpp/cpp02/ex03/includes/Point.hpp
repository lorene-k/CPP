/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:04:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/11/25 21:16:31 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP

# define POINT_HPP

# include <iostream>
# include <Fixed.hpp>

class   Point
{
private:
        const Fixed _x;
        const Fixed _y;

public:
        Point();
        Point(const float x, const float y);
        Point(const Point &point);
        Point &operator=(const Point &point);
        ~Point();

        Fixed getX() const;
        Fixed getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);


#endif // ******************************************************** POINT_HPP //