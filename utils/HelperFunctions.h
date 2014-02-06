#ifndef HELPER_H
#define HELPER_H

#include "Constants.h"
#include <cmath>

static double encoderCountToInches(int encoderCount) {
	return encoderCount * INCHES_PER_COUNT;
}

/*
static double inchesToEacncoderCounts(double inches) {
	return inches / INCHES_PER_COUNT;
}*/

#endif
