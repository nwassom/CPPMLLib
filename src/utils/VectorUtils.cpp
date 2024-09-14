// vector_utils.cpp

#include "../../include/utils/vector_utils.h"

/*
	Calculates and return euclidean distance of two points in n-dimension space
*/
double euclideanDistance(const std::vector<double>& v1, const std::vector<double>& v2)
{
	int dimension = v1.size();
	double distance = 0.0;

	for (int i = 0; i < dimension; i++)
	{
		double diff = v1[i] - v2[i];
		distance += diff * diff;
	}

	return sqrt(distance);
}

/*
	Calculates and return manhattan distance of two points in n-dimension space
*/
double manhattanDistance(const std::vector<double>& v1, const std::vector<double>& v2)
{
	int dimension = v1.size();
	double distance = 0.0;

	for (int i = 0; i < dimension; i++)
	{
		double diff = abs(v1[i] - v2[i]);
		distance += diff;
	}

	return distance;
}