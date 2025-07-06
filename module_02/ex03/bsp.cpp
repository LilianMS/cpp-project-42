#include "Point.hpp"

/*
	Triangle area formula:

		Area = |x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)| / 2

	We will calculate:
		total_area of ABC
		area1 of PBC
		area2 of APC
		area3 of ABP
	If:
		area1 + area2 + area3 == total_area → point is inside
*/

static Fixed area(Point const& p1, Point const& p2, Point const& p3) {
	Fixed result = (p1.getX() * (p2.getY() - p3.getY())
				+ p2.getX() * (p3.getY() - p1.getY())
				+ p3.getX() * (p1.getY() - p2.getY())) / Fixed(2);
	return (result < 0 ? result * -1 : result);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed total = area(a, b, c);
	Fixed area1 = area(point, b, c);
	Fixed area2 = area(a, point, c);
	Fixed area3 = area(a, b, point);

	if (area1 == 0 || area2 == 0 || area3 == 0)
		return (false);

	return (area1 + area2 + area3 == total);
}

/*
	Checks if the point is strictly inside (not on the edges):
	---->  if (area1 == 0 || area2 == 0 || area3 == 0)

*/