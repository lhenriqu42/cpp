/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:44:42 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/05 10:44:43 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Point.h"
#include <vector>

// Algoritmo de Bresenham para linhas
static void drawLine(std::vector<std::vector<char> > &grid, Point start, Point end, char ch = '.')
{
	int x0 = start.getX().toInt();
	int y0 = start.getY().toInt();
	int x1 = end.getX().toInt();
	int y1 = end.getY().toInt();

	bool steep = std::abs(y1 - y0) > std::abs(x1 - x0);

	if (steep)
	{
		std::swap(x0, y0);
		std::swap(x1, y1);
	}

	if (x0 > x1)
	{
		std::swap(x0, x1);
		std::swap(y0, y1);
	}

	int dx = x1 - x0;
	int dy = std::abs(y1 - y0);
	int error = dx / 2;
	int ystep = (y0 < y1) ? 1 : -1;

	int y = y0;
	for (int x = x0; x <= x1; ++x)
	{
		if (steep)
			grid[x][y] = ch;
		else
			grid[y][x] = ch;

		error -= dy;
		if (error < 0)
		{
			y += ystep;
			error += dx;
		}
	}
}

static void drawTriangleAndPoint(const Point a, const Point b, const Point c, const Point point)
{

	Fixed Xmax = Fixed::max(Fixed::max(a.getX(), point.getX()), Fixed::max(b.getX(), c.getX()));
	Fixed Xmin = Fixed::min(Fixed::min(a.getX(), point.getX()), Fixed::min(b.getX(), c.getX()));
	Fixed Ymax = Fixed::max(Fixed::max(a.getY(), point.getY()), Fixed::max(b.getY(), c.getY()));
	Fixed Ymin = Fixed::min(Fixed::min(a.getY(), point.getY()), Fixed::min(b.getY(), c.getY()));

	// Offsets para normalizar os valores negativos
	int offsetX = 0;
	int offsetY = 0;

	if (Xmin.toInt() < 0)
		offsetX = std::abs(Xmin.toInt());
	if (Ymin.toInt() < 0)
		offsetY = std::abs(Ymin.toInt());

	int width = Xmax.toInt() + offsetX + 1;
	int height = Ymax.toInt() + offsetY + 1;

	// Cria a grade
	std::vector<std::vector<char> > grid(height, std::vector<char>(width, ' '));

	// Normaliza os pontos
	int ax = a.getX().toInt() + offsetX;
	int ay = a.getY().toInt() + offsetY;
	int bx = b.getX().toInt() + offsetX;
	int by = b.getY().toInt() + offsetY;
	int cx = c.getX().toInt() + offsetX;
	int cy = c.getY().toInt() + offsetY;
	int px = point.getX().toInt() + offsetX;
	int py = point.getY().toInt() + offsetY;


	drawLine(grid, Point(ax, ay), Point(bx, by));
	drawLine(grid, Point(bx, by), Point(cx, cy));
	drawLine(grid, Point(cx, cy), Point(ax, ay));
	grid[py][px] = 'x';
	grid[ay][ax] = 'A';
	grid[by][bx] = 'B';
	grid[cy][cx] = 'C';

	std::string color;
	// Imprime a grade
	for (int y = height - 1; y >= 0; --y)
	{
		for (int x = 0; x < width; ++x)
		{
			color = CYN;
			if (grid[y][x] == 'x')
				color = MAG;
			std::cout << color << grid[y][x] << ' ' << RESET;				
		}
		std::cout << std::endl;
	}
}

static float area(const Point p1, const Point p2, const Point p3)
{
	float area;

	// Shoelace algorithm
	// Area A = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2)]/2
	area = ((p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat())) + (p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat())) + (p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat()))) / 2;

	if (area >= 0)
		return (area);
	else
		return (area * -1);
}

bool bsp(const Point a, const Point b, const Point c, const Point point)
{

	drawTriangleAndPoint(a, b, c, point);

	float d0, d1, d2, d3;
	bool ret_val = false;

	d0 = area(a, b, c);
	d1 = area(point, a, b);
	d2 = area(point, b, c);
	d3 = area(point, a, c);

	if (d1 == 0 || d2 == 0 || d3 == 0)
		ret_val = false;
	else if (d1 + d2 + d3 == d0)
		ret_val = true;

	return (ret_val);
}