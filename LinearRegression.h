
// LinearRegression.h

#ifndef LINEARREGRESSION_H
#define LINEARREGRESSION_H

#include <vector>

class LinearRegression
{
	private:	

		std::vector<double> x;
		std::vector<double> y;
		double slope_m;
		double intercept_c;
		double mean_y;

	public:

		LinearRegression();
		LinearRegression(const std::vector<double>& x, const std::vector<double>& y);

		void setData(const std::vector<double>& x, const std::vector<double>& y);

		void calculateCoefficients();

		void calculateYMean();

		double predict(double x) const;

		double calculateRSquared() const;

		double getSlope() const;
		double getIntercept() const;

};

#endif