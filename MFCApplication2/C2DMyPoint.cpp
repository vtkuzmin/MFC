#include "stdafx.h"
#include "C2DMyPoint.h"


CMy2DPoint::CMy2DPoint():m_x(0.0),m_y(0.0) {}
CMy2DPoint::CMy2DPoint(double x, double y) :m_x(x), m_y(y) {};
CMy2DPoint::~CMy2DPoint(){}

CMy2DPoint CMy2DPoint::operator+(const CMy2DPoint& point)
{ 
	return CMy2DPoint(m_x + point.m_x, m_y + point.m_y);
}
CMy2DPoint CMy2DPoint::operator-(const CMy2DPoint& point)
{
	return CMy2DPoint(m_x - point.m_x, m_y - point.m_y);
}
CMy2DPoint CMy2DPoint::operator*(double k)
{
	return CMy2DPoint(m_x*k, m_y*k);
}
CMy2DPoint CMy2DPoint::operator*(const CMy2DPoint& point)
{ 
	return CMy2DPoint(m_x*point.m_x, m_y*point.m_y);
}
CMy2DPoint CMy2DPoint::operator/(double k)
{
	return operator*(1 / k);
}
bool CMy2DPoint::operator==(const CMy2DPoint& point) {
	return (abs(m_x - point.m_x) < eps && abs(m_y - point.m_y) < eps);
}
bool CMy2DPoint::operator!=(const CMy2DPoint& point) {
	return !operator==(point);
}

CMy2DPoint operator* (double k, CMy2DPoint& point) {
	return point.operator*(k);
}
ostream& operator<<(ostream& out, const CMy2DPoint& point) {
	out << "(" << point.m_x << ";" << point.m_y << ")";
	return out;
}
istream& operator>>(istream& is, CMy2DPoint& point) {
	is >> point.m_x >> point.m_y;
	return is;
}