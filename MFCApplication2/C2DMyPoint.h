#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <math.h>
#include <fstream>
#include <conio.h>
#include <cstdio>

#define eps 1e-10
using namespace std;

class CMy2DPoint
{
public:
	double m_x, m_y;

	CMy2DPoint();
	CMy2DPoint(double x, double y);
	~CMy2DPoint();

	CMy2DPoint operator+(const CMy2DPoint& point);
	CMy2DPoint operator-(const CMy2DPoint& point);
	CMy2DPoint operator*(double k);
	CMy2DPoint operator*(const CMy2DPoint& point);
	CMy2DPoint operator/(double k);
	bool operator==(const CMy2DPoint& point);
	bool operator!=(const CMy2DPoint& point);
};

CMy2DPoint operator* (double k, CMy2DPoint& point);
ostream& operator<<(ostream& out, const CMy2DPoint& point);
istream& operator>>(istream& input, CMy2DPoint& point);
