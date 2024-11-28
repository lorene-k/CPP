/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:09:17 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/11/25 20:30:41 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float getSign(const Point &p1, const Point &p2, const Point &p3)
{
    return ((p1.getX().toFloat() - p3.getX().toFloat()) * (p2.getY().toFloat() - p3.getY().toFloat())) - 
           ((p2.getX().toFloat() - p3.getX().toFloat()) * (p1.getY().toFloat() - p3.getY().toFloat()));
}

static bool isVertice(const Point &a, const Point &b, const Point &c, const Point point)
{
    if ((point.getX() == a.getX() && point.getY() == a.getY())
        || (point.getX() == b.getX() && point.getY() == b.getY())
        || (point.getX() == c.getX() && point.getY() == c.getY()))
        return (true);
    return (false);
}

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
    float   pos1, pos2, pos3;
    bool    negative, positive;

    pos1 = getSign(point, a, b);
    pos2 = getSign(point, b, c);
    pos3 = getSign(point, c, a);

    if (isVertice(a, b, c, point)
        || (pos1 == 0 || pos2 == 0 || pos3 == 0))
        return (false);

    negative = (pos1 < 0) || (pos2 < 0) || (pos3 < 0);
    positive = (pos1 > 0) || (pos2 > 0) || (pos3 > 0);
    return !(negative && positive);
}

int main()
{
    Point a(0, 0);
    Point b(5, 0);
    Point c(0, 5);

    // Tests
    Point insidePoint(1, 1);
    Point outsidePoint(6, 6);
    Point edgePoint(2.5, 0);
    Point vertexPoint(0, 0);

    std::cout << "Point (1, 1): "
              << (bsp(a, b, c, insidePoint) ? "Inside" : "Outside") << std::endl;

    std::cout << "Point (6, 6): "
              << (bsp(a, b, c, outsidePoint) ? "Inside" : "Outside") << std::endl;

    std::cout << "Point (2.5, 0): "
              << (bsp(a, b, c, edgePoint) ? "Inside" : "Outside") << std::endl;

    std::cout << "Point (0, 0): "
              << (bsp(a, b, c, vertexPoint) ? "Inside" : "Outside") << std::endl;

    return 0;
}

