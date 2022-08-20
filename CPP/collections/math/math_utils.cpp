//Definition in implementation file .cpp
#include "math_utils.h"

namespace utilz {

double area(double length, double width) {
	return length * width;
}

double area(double length) {
	return length * length;
}

double area(Rectangle rectangle) {
	return rectangle.length * rectangle.width;
}

double pow(double base, int exp) {
	int total = 1;
	for (int i = 0; i < exp; i++)
	{
		total = total * base;
	}
	return total;
}
}