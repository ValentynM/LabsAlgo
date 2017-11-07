#pragma once
#include <iostream>

#include "UInterface.h"
using namespace std;

class Image
{
public:
	virtual void getParameters() = 0;
};

class Point : public Image
{ 
protected:
	double x1_;
	double y1_;
public:
	Point(double x1, double y1) : x1_(x1), y1_(y1) {}

	virtual void getParameters()
	{
		UInterface::getID(1);
		UInterface::getPoint(x1_, y1_);
	}

	//Point& Point :: operator = (Point& point)
	//{
	//	x1_ = point.x1_;
	//	y1_ = point.y1_;
	//	return *this;
	//}
};

class Circle : public Point
{
protected:
	double radius;
public:

	Circle(int xCenter = 0, int yCenter = 0, double radius = 0.0) : Point(xCenter, yCenter)
	{
		this -> radius = radius;
	}

	virtual void getParameters()
	{
		UInterface::getID(2);
		UInterface::getPoint(x1_, y1_);
		UInterface::getID(3);
		UInterface::getRadius(radius);
	}
};

class Line : public Point
{
protected:
	double x2_;
	double y2_;
public:
	Line(double x1, double y1, double x2, double y2) 
		: Point(x1, y1), x2_(x2), y2_(y2) {}

	virtual void getParameters()
	{
		UInterface::getID(4);
		UInterface::getPoint(x1_, y1_);
		UInterface::getID(5);
		UInterface::getPoint(x2_, y2_);
	}
};

class Triangle : public Line
{
protected:
	double x3_;
	double y3_;
public:
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3) : 
		Line(x1, y1, x2, y2), x3_(x3), y3_(y3) {}

	virtual void getParameters()
	{
		UInterface::getID(4);
		UInterface::getPoint(x1_, y1_);
		UInterface::getID(5);
		UInterface::getPoint(x2_, y2_);
		UInterface::getID(6);
		UInterface::getPoint(x3_, y3_);
	}
};


class Quadrilateral : public Triangle
{
protected:
	double x4_;
	double y4_;
public:

	Quadrilateral(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) 
		: Triangle(x1, y1, x2, y2, x3, y3) , x4_(x4), y4_(y4)  {}

	virtual void getParameters()
	{
		UInterface::getID(4);
		UInterface::getPoint(x1_, y1_);
		UInterface::getID(5);
		UInterface::getPoint(x2_, y2_);
		UInterface::getID(6);
		UInterface::getPoint(x3_, y3_);
		UInterface::getID(7);
		UInterface::getPoint(x4_, y4_);
	}
};
