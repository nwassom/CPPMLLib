#ifndef POINT_H
#define POINT_H

class Point
{
	public:
		Point(const std::vector<double>& coordinates);
		std::vector<double> getCoordinates() const;

	private:
		std::vector<double> coordinates;
};

#endif