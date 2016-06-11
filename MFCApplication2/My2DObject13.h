#pragma once
#include "C2DMyPoint.h"

class CMy2DObject13
{
	double A, A1, A2, A3, m_dAngle;
	CMy2DPoint m_centr;
public:
	CMy2DObject13() : A(0), A1(0), A2(0), A3(0), m_centr(), m_dAngle(0) {};
	CMy2DObject13(double A, double A1, double A2, double A3, double m_dAngle, CMy2DPoint m_centr);
	~CMy2DObject13() {};

	const double GetA() { return A; }
	const double GetA1() { return A1; }
	const double GetA2() { return A2; }
	const double GetA3() { return A3; }
	const double Get_Angle() { return m_dAngle; }
	const CMy2DPoint Get_centr() { return m_centr; }

	void print();
	void Draw(CDC &dc);
	
	void setA(double a);
	void setA1(double a1);
	void setA2(double a2);
	void setA3(double a3);
	void setAngle(double angle);
	void set_centr(CMy2DPoint centr);

	void Move(double dX, double dY, double dAngle = 0);
	void Move(const CMy2DPoint &delta, double dAngle = 0);
	void Rotate(double dAngle) { m_dAngle += dAngle; }

	bool IsInside(double x, double y);
	bool IsInside(const CMy2DPoint& point);

};

