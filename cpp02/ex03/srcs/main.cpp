/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:09:17 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/11/29 15:00:06 by lkhalifa         ###   ########.fr       */
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

static void print_point(const Point &point)
{
    std::cout << RESET << "Point (" << point.getX() << ", " << point.getY() << "): ";
}

int main()
{
    Point a(0, 0);
    Point b(5, 0);
    Point c(0, 5);

    Point insidePoint1(1, 1);
    Point insidePoint2(2, 2);
    Point outsidePoint(6, 6);
    Point edgePoint(2.5, 0);
    Point vertexPoint(0, 0);

    print_point(insidePoint1);
    std::cout << (bsp(a, b, c, insidePoint1) ? GREEN "Inside" : RED "Outside") << std::endl;
    print_point(insidePoint2);
    std::cout << (bsp(a, b, c, insidePoint2) ? GREEN "Inside" : RED "Outside") << std::endl;
    print_point(outsidePoint);
    std::cout << (bsp(a, b, c, outsidePoint) ? GREEN "Inside" : RED "Outside") << std::endl;
    print_point(edgePoint);
    std::cout << (bsp(a, b, c, edgePoint) ? GREEN "Inside" : RED "Outside") << std::endl;
    print_point(vertexPoint);
    std::cout << (bsp(a, b, c, vertexPoint) ? GREEN "Inside" : RED "Outside") << RESET << std::endl;


    //TEST pos
    // std::cout << getSign(outsidePoint, a, b) << std::endl;
    // std::cout << getSign(outsidePoint, b, c) << std::endl;
    // std::cout << getSign(outsidePoint, c, a) << std::endl;
    return 0;
}
