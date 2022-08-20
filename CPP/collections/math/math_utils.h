// Declarations in header file .h
#ifndef MATH_UTILS
#define MATH_UTILS   //pre-processor directive that will be processed before our code is compiled, to prevent us from including this code twice.

struct Rectangle {
	double length;
	double width;
};

namespace utilz {

double area(double length, double width);

double area(double length);

double area(Rectangle rectangle);

double pow(double base, int exp = 2);
}


#endif