#include "Point.hpp"

static float triangleArea(const Point a, const Point b, const Point c)
{
	return fabsf(
		(a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
		 b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) +
		 c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()))
		/ 2.0f
	);
}

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
	float total = triangleArea(a, b, c);
	float area1 = triangleArea(point, a, b);
	float area2 = triangleArea(point, b, c);
	float area3 = triangleArea(point, c, a);

	return (area1 > 0 && area2 > 0 && area3 > 0) &&
			(fabsf((area1 + area2 + area3) - total) < 0.0001f);
}
