// LinearRegression.cpp

#include "LinearRegression.h"

#include <numeric>
#include <cmath>
#include <stdexcept>


/*
	Can further optimize by changing the way the means are calculated and save rather than
	calculate multiple times
*/

// Empty constructor 
LinearRegression::LinearRegression() : slope_m(0), intercept_c(0)
{
	if (x.size() != y.size()) 
	{
    	throw std::invalid_argument("Input vectors x and y must have the same length.");
	}
}

// Constructor
LinearRegression::LinearRegression(const std::vector<double>& x, const std::vector<double>& y)
	: x(x), y(y), slope_m(0), intercept_c(0)
{
	if (x.size() != y.size()) 
	{
    	throw std::invalid_argument("Input vectors x and y must have the same length.");
	}
}

// Method to set the x and y vectors
void LinearRegression::setData(const std::vector<double>& x, const std::vector<double>& y)
{
	this->x = x;
	this->y = y;
}

/*

*/
void LinearRegression::calculateCoefficients()
{
	// Calc mean x & y
	double x_mean = std::accumulate(x.begin(), x.end(), 0.0) / x.size();
	double y_mean = std::accumulate(y.begin(), y.end(), 0.0) / y.size();

	// Calc num and denom for the slope
	double numerator = 0.0;
	double denominator = 0.0;

	for (size_t i = 0; i < x.size(); i++)
	{
		numerator += (x[i] - x_mean) * (y[i] - y_mean);
		denominator += std::pow(x[i] - x_mean, 2);
	}

	// Calc slope & intercept
	slope_m = numerator / denominator;
	intercept_c = y_mean - (slope_m * x_mean);
}

/*

*/
double LinearRegression::predict(double x) const
{
	return slope_m * x + intercept_c;
}

double LinearRegression::calculateRSquared() const
{
	double y_mean = std::accumulate(y.begin(), y.end(), 0.0) / y.size();

	double ss_total = 0.0;
	double ss_residual = 0.0;

	for (size_t i = 0; i < y.size(); i++)
	{
		double y_predict = predict(x[i]);
		ss_total += std::pow(y[i] - y_mean, 2);
		ss_residual += std::pow(y[i] - y_predict, 2);
	}

	return 1.0 - (ss_residual / ss_total);
}

double LinearRegression::getSlope() const
{
	return slope_m;
}

double LinearRegression::getIntercept() const
{
	return intercept_c;
}