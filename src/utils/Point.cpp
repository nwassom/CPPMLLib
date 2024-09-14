// point.cpp

#include "../../include/utils/point.h"

Point::Point(const std::vector<double>& coordinates) : coordinates(coordinates) {}

std::vector<double> Point::getCoordinates() const 
{
	return coordinates;
}