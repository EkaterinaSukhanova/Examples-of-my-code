#include <iostream>
#include <cmath>
#include "polygon.hpp"
using namespace std;

Point::Point(double a, double b):x(a),y(b)
{}

Point::Point()
{}

void Point::print()
{
	cout << "( " << x << " ; " << y << " )" << "\n";
}


Polygon::Polygon():amount_points(0), mass_points(0)
{
}

Polygon::Polygon(Point* points, int amount)
{
	amount_points = amount;
	mass_points = new Point[amount_points];
	for(int i = 0; i < amount_points; ++i)
	{
		mass_points[i] = points[i];
	}
}

Polygon::~Polygon()
{
	if(mass_points != 0)
	{
		delete[] mass_points;
		mass_points = 0;
		amount_points = 0;
	}
}

void Polygon::info_points()
{
	if(amount_points == 0)
	{
		cout << "No points" << "\n";
	}
	else
	{
		for(int i = 0; i < amount_points; ++i)
		{
			cout << i+1 << ". (" << mass_points[i].x << " ; "
				<< mass_points[i].y << ")" << "\n";
		}
	}
	return;
}

double Polygon::meth_line(int index_point1, int index_point2)
{
	double line =
	sqrt(pow((mass_points[index_point1].x - mass_points[index_point2].x), 2)
	+ pow((mass_points[index_point1].y - mass_points[index_point2].y), 2));
	return line;
}

double Polygon::meth_perimetr()
{
	double perimetr = 0;
	if (amount_points < 2)
	{
		cout << "Not enough points" << "\n";
		return 1;
	}
	for(int i = 0; i < amount_points; ++i)
	{
		double line = 0;
		if(i == amount_points-1)
		{
			line = meth_line(i,0);
		}
		else
		{
			line = meth_line(i,i+1);
		}
		perimetr += line;
	}
	return perimetr;
}

double Polygon::area_of_polygon()
{
	double area = 0;
	double res = 0;
	double s = 0;
	for(int i = 0; i < amount_points; ++i)
	{
		if(i == 0)
		{
			s = 
			mass_points[i].x * 
			(mass_points[amount_points - 1].y - mass_points[i + 1].y);
			// если i == 0, то y[i+1] заменяется на y[n-1]
			res += s;
		}
		else if(i == amount_points-1)
		{
			s = 
			mass_points[i].x * (mass_points[i - 1].y - mass_points[0].y);
			// если i == 0, то y[i+1] заменяется на y[n-1]
			res += s;
		}
		else
		{
			s = 
			mass_points[i].x * (mass_points[i - 1].y - mass_points[i+1].y);
			res += s;
		}
	}
	area = abs(res/2);
	return area;
}

int Polygon::get_type_of_polygon()
{
	return amount_points;
}


Squere::Squere(Point* points, int amount):
	Polygon(points, amount)
{
	side = meth_line(0,1);
}

double Squere::area_of_polygon()
{
	return pow(side, 2);
}

double Squere::meth_diagonal()
{
	double diag = side * sqrt(2);
	return diag;
}


Triangle::Triangle(Point* points, int amount):
	Polygon(points, amount)
{
	side1 = meth_line(0,1);
	side2 = meth_line(1,2);
	side3 = meth_line(2,0);
}

double Triangle::area_of_polygon()
{
	double perimetr = meth_perimetr();
	double half_p = perimetr/2;
	double area = sqrt(half_p * (half_p - side1) * (half_p - side2) * (half_p - side3));
	return area;
}

Point Triangle::cross_medians()
{
	double x = (mass_points[0].x + mass_points[1].x + mass_points[2].x)/3;
	double y = (mass_points[0].y + mass_points[1].y + mass_points[2].y)/3;
	Point point_medians(x,y);
	return point_medians;
}

double Triangle::line_medians(int first_point_side)
{
	switch(first_point_side)
	{
		case 0:
			{
				double median1 = sqrt(2 * pow(side2, 2) + 2 * pow(side3, 2) -
						pow(side1, 2))/2;
				return median1;
			}
		case 1:
			{
				double median2 = sqrt(2 * pow(side1, 2) + 2 * pow(side3, 2) - 
						pow(side2,2))/2;
				return median2;
			}
		case 2:
			{
				double median3 = sqrt(2 * pow(side1, 2) + 2 * pow(side2, 2) -
						pow(side3,2))/2;
				return median3;
			}				
	}
}

double Triangle::line_bisector(int first_point_side)
{
	double perimetr = meth_perimetr();
	double half_p = perimetr/2;
	switch(first_point_side)
	{
		case 0:
			{
				double bis1 = 
				2 * sqrt(side2 * side3 * half_p * (half_p - side1)) / 
				(side2 + side3);
				return bis1;
			}
		case 1:
			{
				double bis2 = 
				2 * sqrt(side1 * side3 * half_p * (half_p - side2)) /
				(side1 + side3);
				return bis2;
			}
		case 2:
			{
				double bis3 = 
				2 * sqrt(side1 * side2 * half_p * (half_p - side3)) /
				(side1 + side2);
				return bis3;
			}				
	}

}

Point Triangle::cross_bisectors()
{
	double x = 
	(side2 * mass_points[0].x + side3 * mass_points[1].x + side1 * mass_points[2].x)
       	/ (side1 + side2 + side3);
	
	double y = 
	(side2 * mass_points[0].y + side3 * mass_points[1].y + side1 * mass_points[2].y)
	/ (side1 + side2 + side3);

	Point point_bisectors(x, y);
	return point_bisectors;
}

void demonstration_squere(Squere** mass_squere, int n)
{
	for(int i = 0; i < n; ++i)
	{
		cout << "Diagonal of squere #" << i+1 << ": " << "\n" << 
			mass_squere[i]->meth_diagonal() << "\n";
	}
}

void demonstration_triangle(Triangle** mass_triangle, int n)
{
	for(int i = 0; i < n; ++i)
	{
		Point cross = mass_triangle[i]->cross_medians(); 
		cout << "Coordinates crossing of medians triangle#" << i+1 << ": " << "\n"; 
		cross.print();
	
		cout << "Length medians triangle#" << i+1 << ": "<< "\n" 
			<<mass_triangle[i]->line_medians(0) 
			<< " " << mass_triangle[i]->line_medians(1) << " " 
			<< mass_triangle[i]->line_medians(2) << "\n";
	
		cout << "Length bisectors triangle#" << i+1<< ": " << "\n"  
			<< mass_triangle[i]->line_bisector(0)
		       	<< " " << mass_triangle[i]->line_bisector(1) << " " 
			<< mass_triangle[i]->line_bisector(2) << "\n";
	
		cross = mass_triangle[i]->cross_bisectors();
		cout << "Coordinates crossing of bisectors triangle#" << i+1 << ": " << "\n";
		cross.print();
	}
}

void demonstration_polygon(Polygon** mass, int n)
{
	for(int i = 0; i < 4; ++i)
	{
		cout << "Areas: " << mass[i]->area_of_polygon()<< "\n";
		cout << "Type of polygon (Amount of points): " << 
				mass[i]->get_type_of_polygon()<< "\n";
	}
}

int testing_methods()
{
	Point points_for_square1[4] = {Point(1,1), Point(3,1), Point(3,3), Point(1,3)};
	Point points_for_square2[4] = {Point(2,2), Point(2,0), Point(0,0), Point(0,2)};
	Point points_for_triangle1[3] = {Point(0,2), Point(2,0), Point(1,0)};
	Point points_for_triangle2[3] = {Point(0,3), Point(3,0), Point(0,0)};

	Squere s1(points_for_square1, 4);
	Squere s2(points_for_square2, 4);
	Triangle t2(points_for_triangle2, 3);
	Triangle t1(points_for_triangle1, 3);

	// Создать массив указателей на объекты базового класса
	int N = 100;
	Polygon** mass = new Polygon*[N];// mass[4];
	if (!mass)
	{
		cout << "can't allocate bytes";
		return 1;
	}

	//Заполнить этот массив объектами производных классов.
	mass[0] = &s1;
	mass[1] = &t1;
	mass[2] = &s2;
	mass[3] = &t2;
	
	//работа методов базового класса для разных типов многоугольников
	demonstration_polygon(mass, 4);
	
	delete[] mass;

	//работа собственных методов производных классов
	Squere** mass_squere = new Squere*[N];
	if (!mass_squere)
	{
		cout << "can't allocate bytes";
		return 1;
	}

	mass_squere[0] = &s1;
	mass_squere[1] = &s2;

	demonstration_squere(mass_squere, 2);

	delete[] mass_squere;
	
	Triangle** mass_triangle = new Triangle*[N];
	if (!mass_triangle)
	{
		cout << "can't allocate bytes";
		return 1;
	}

	mass_triangle[0] = &t1;
	mass_triangle[1] = &t2;
	
	demonstration_triangle(mass_triangle, 2);

	delete[] mass_triangle;
	return 0;
}



