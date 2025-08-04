#include "Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point point);

int main()
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(5, 10);

	Point p1(5, 5);       // Inside
	Point p2(10, 10);     // Outside
	Point p3(5, 0);       // On edge → should return false
	Point p4(7.5, 5);     // Inside-ish
	Point p5(5, 10);      // Vertex → should return false
	Point p6(5, 4.999);   // Barely inside

	Point points[] = {p1, p2, p3, p4, p5, p6};
	const char* labels[] = {"p1", "p2", "p3", "p4", "p5", "p6"};

	for (int i = 0; i < 6; ++i)
	{
		std::cout << labels[i] << " (" << points[i].getX() << ", " << points[i].getY() << ") is ";
		if (bsp(a, b, c, points[i]))
			std::cout << "inside the triangle.";
		else
			std::cout << "outside the triangle.";
		std::cout << std::endl;
	}

	return 0;
}
