#include "LinearRegression.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

void readCSV(const std::string& filename, std::vector<double>& x, std::vector<double>& y) 
{

	if (filename.empty()) 
	{
    	std::cerr << "No filename provided, exiting." << std::endl;
    	exit(1);
	}

	std::ifstream file(filename);
	std::string line, temp;

	if (!file.is_open()) 
	{
		std::cerr << "Couldn't Open CSV" << std::endl;
		return;
	}

	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		double x_val, y_val;

		if (std::getline(ss, temp, ','))
		{
			x_val = std::stod(temp);
		}

		if (std::getline(ss, temp, ','))
		{
			y_val = std::stod(temp);
		}

		x.push_back(x_val);
		y.push_back(y_val);
	}

	file.close();
}

double convertInchToFeet(double inches)
{
	return inches / 12.0;
}

int main()
{
	std::string filename;
	double x_val;

	std::vector<double> x;
	std::vector<double> y;


	std::cout << "Enter filename for data: ";
	std::cin >> filename;

	readCSV(filename, x, y);

	LinearRegression model(x,y);

	model.calculateCoefficients();

	std::cout << "Enter data to be predicted among: ";
	std::cin >> x_val;
	double y_predict = model.predict(x_val);

	std::cout << "Predicted y for x = " << convertInchToFeet(x_val) << ": " << convertInchToFeet(y_predict) << std::endl;
	
}
