#ifndef MASS_OF_STR_HPP
#define MASS_OF_STR_HPP

struct Point
{
	Point(double a, double b);
	Point();
	void print();
	double x;
	double y;
};

class Polygon
{
public:
	Polygon();
	Polygon(Point* points, int amount);
	virtual ~Polygon();
	void info_points();
	double meth_line(int index_point1, int index_point2);
	double meth_perimetr();
	virtual double area_of_polygon();
	virtual int get_type_of_polygon();
protected:
	int amount_points;
	Point* mass_points;
};

class Squere : public Polygon
{
public:
	Squere(Point* points, int amount);
	virtual double area_of_polygon();
	double meth_diagonal();
private:
	double side;
};

class Triangle : public Polygon
{
public:
	Triangle(Point* points, int amount);
	virtual double area_of_polygon();
	Point cross_medians();
	double line_medians(int first_point_side);
	double line_bisector(int first_point_side);
	Point cross_bisectors();
private:
	double side1;
	double side2;
	double side3;
};
void demonstration_polygon(Polygon** mass, int n);
void demonstration_squere(Squere** mass_squere, int n);
void demonstration_triangle(Triangle** mass_triangle, int n);
int testing_methods();
#endif

