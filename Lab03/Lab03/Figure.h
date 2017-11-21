#pragma once
#include <iostream>

#include "UInterface.h"

const double PI = atan(1.0) * 4;
using namespace std;

class Figure
{
public:
	virtual void getParameters() {};
	virtual void setParameters() {};
};

class Point : public Figure
{ 
protected:
	double x;
	double y;
public:
	Point(double x1 = 0.0, double y1 = 0.0) : x(x1), y(y1) {}

	virtual void getParameters()
	{
		UInterface::getID(1);
		UInterface::getPoint(x, y);
	}

	virtual void setParameters()
	{
		UInterface::getID(1);
		UInterface::setPoint(x, y);
	}

	double getX()
	{
		return x;
	}

	double getY()
	{
		return y;
	}
};

class Circle : public Point
{
protected:
	double radius;
public:

	Circle(double xCenter = 0.0, double yCenter = 0.0, double radius = 1.0) : Point(xCenter, yCenter)
	{
		this -> radius = radius;
	}

	virtual void getParameters()
	{
		UInterface::getID(2);
		UInterface::getPoint(x, y);
		UInterface::getID(3);
		UInterface::getRadius(radius);
	}

	virtual void setParameters()
	{
		UInterface::getID(2);
		UInterface::setPoint(x, y);
		UInterface::getID(3);
		UInterface::setRadius(radius);
	}

	double getXCenter()
	{
		return x;
	}

	double getYCenter()
	{
		return y;
	}

	double getRadius()
	{
		return radius;
	}
};


class Triangle : public Point
{
protected:
	double a;
	double b;
	double fi;
public:
	Triangle(double x1 = 0.0, double y1 = 0.0, double a1 = 1.0, double b1 = 1.0, double fi1 = PI/3) :
		Point(x1, y1), a(a1), b(b1), fi(fi1) {}

	virtual void getParameters()
	{
		UInterface::getID(1);
		UInterface::getPoint(x, y);
		UInterface::getID(4);
		UInterface::getLineSegment(a);
		UInterface::getID(5);
		UInterface::getLineSegment(b);
		UInterface::getID(6);
		UInterface::getAngle(fi);
	}

	virtual void setParameters()
	{
		UInterface::getID(1);
		UInterface::setPoint(x, y);
		UInterface::getID(4);
		UInterface::setLineSegment(a);
		UInterface::getID(5);
		UInterface::setLineSegment(b);
		UInterface::getID(6);
		UInterface::setAngle(fi);
	}

	double getX()
	{
		return x;
	}

	double getY()
	{
		return y;
	}

	double getFirstLineSegment()
	{
		return a;
	}

	double getSecondLineSegment()
	{
		return b;
	}

	double getAngle()
	{
		return fi;
	}
};


class Quadrilateral : public Point
{
protected:
	double diagonal1;
	double diagonal2;
	double psi;
public:

	Quadrilateral(double x1 = 0.0, double y1 = 0.0, double diagonal11 = 1, double diagonal22 = 1, double psi1 = PI/2) 
		: Point(x1, y1) , diagonal1(diagonal11), diagonal2(diagonal22), psi(psi1) {}

	virtual void getParameters()
	{
		UInterface::getID(4);
		UInterface::getPoint(x, y);
		UInterface::getID(7);
		UInterface::getLineSegment(diagonal1);
		UInterface::getID(8);
		UInterface::getLineSegment(diagonal2);
		UInterface::getID(9);
		UInterface::getAngle(psi);
	}

	virtual void setParameters()
	{
		UInterface::getID(1);
		UInterface::setPoint(x, y);
		UInterface::getID(7);
		UInterface::setLineSegment(diagonal1);
		UInterface::getID(8);
		UInterface::setLineSegment(diagonal2);
		UInterface::getID(9);
		UInterface::setAngle(psi);
	}

	double getX()
	{
		return x;
	}

	double getY()
	{
		return y;
	}

	double getFirstDiagonal()
	{
		return diagonal1;
	}

	double getSecondDiagonal()
	{
		return diagonal2;
	}

	double getAngle()
	{
		return psi;
	}
};
