#include "stdafx.h"
#include "My2DObject13.h"

CMy2DObject13::CMy2DObject13(double A, double A1, double A2, double A3, double m_dAngle, CMy2DPoint m_centr) {
	if ((A - A1 - A2) <= 0 || (A - A3 - A2) <= 0 || sqrt(1.25)*A - A3 - A1 <= 0) {
		cout << "Self-intersection!" << endl;
		this->A = 0.0;
		this->A1 = 0.0;
		this->A2 = 0.0;
		this->A3 = 0.0;
		this->m_dAngle = 0.0;
		this->m_centr.m_x = 0.0;
		this->m_centr.m_y = 0.0;
		cout << "Now all fields = 0!" << endl;
	}
	else {
		this->A = A;
		this->A1 = A1;
		this->A2 = A2;
		this->A3 = A3;
		this->m_dAngle = m_dAngle;
		this->m_centr.m_x = m_centr.m_x;
		this->m_centr.m_y = m_centr.m_y;
	}
}

void CMy2DObject13::print()
{
	cout << endl << "Figure's centre:" << m_centr << endl;;
	cout << "Figure's dimensions:" << " A = " << A << " A1 = " << A1 << " A2 = " << A2 << " A3 = " << A3 << endl;
	cout << "Rotation angle = " << m_dAngle << endl << endl;

}

void CMy2DObject13::Draw(CDC &dc) {

	int x = m_centr.m_x;
	int y = m_centr.m_y;

	//x = x1*cos(m_dAngle) + y1*sin(m_dAngle); //сделаем обратное вращение точки
	//y = y1*cos(m_dAngle) - x1*sin(m_dAngle);

	dc.MoveTo((-A / 2 + A2)*cos(m_dAngle) - (A / 2)*sin(m_dAngle)+x,-( (A / 2)*cos(m_dAngle)+ (-A / 2 + A2)*sin(m_dAngle))+y);
	dc.LineTo((A / 2 )*cos(m_dAngle) - (A / 2)*sin(m_dAngle) + x, -((A / 2)*cos(m_dAngle) + (A / 2)*sin(m_dAngle)) + y);
	dc.LineTo((A / 2)*cos(m_dAngle) - (A1)*sin(m_dAngle) + x, -((A1)*cos(m_dAngle) + (A / 2)*sin(m_dAngle)) + y);
	dc.AngleArc((A / 2)*cos(m_dAngle) - (0)*sin(m_dAngle) + x,-( (0)*cos(m_dAngle) + (A / 2)*sin(m_dAngle)) + y, A1, 90+m_dAngle*180/M_PI, 180);
	dc.LineTo((A / 2)*cos(m_dAngle) - (-A / 2)*sin(m_dAngle) + x, -((-A / 2)*cos(m_dAngle) + (A / 2)*sin(m_dAngle)) + y);
	dc.LineTo((-A / 2 + A3)*cos(m_dAngle) - (-A / 2)*sin(m_dAngle) + x, -((-A / 2)*cos(m_dAngle) + (-A / 2 + A3)*sin(m_dAngle)) + y);
	dc.AngleArc((-A / 2)*cos(m_dAngle) - (-A / 2)*sin(m_dAngle) + x, -((-A / 2)*cos(m_dAngle) + (-A / 2)*sin(m_dAngle)) + y, A3, m_dAngle * 180 / M_PI, 90);
	dc.LineTo((-A / 2)*cos(m_dAngle) - (A / 2 - A2)*sin(m_dAngle) + x, -((A / 2 - A2)*cos(m_dAngle) + (-A / 2)*sin(m_dAngle)) + y);
	dc.LineTo((-A / 2+A2)*cos(m_dAngle) - (A / 2 - A2)*sin(m_dAngle) + x,-( (A / 2 - A2)*cos(m_dAngle) + (-A / 2+A2)*sin(m_dAngle)) + y);
	dc.LineTo((-A / 2 + A2)*cos(m_dAngle) - (A / 2)*sin(m_dAngle) + x, -((A / 2)*cos(m_dAngle) + (-A / 2 + A2)*sin(m_dAngle)) + y);
	/*
	dc.MoveTo(x - A / 2 + A2, y - A / 2);
	dc.LineTo(x + A / 2, y - A / 2);
	dc.LineTo(x + A / 2, y - A1);
	dc.AngleArc(x + A / 2, y, A1, 90, 180);
	dc.LineTo(x + A / 2, y + A / 2);
	dc.LineTo(x - A / 2 + A3, y + A / 2);
	dc.AngleArc(x - A / 2, y + A / 2, A3, 0, 90);
	dc.LineTo(x - A / 2, y - A / 2 + A2);
	dc.LineTo(x - A / 2 + A2, y - A / 2 + A2);
	dc.LineTo(x - A / 2 + A2, y - A / 2);
	*/
}

void CMy2DObject13::setA(double a) {
	if (!((a - A1 - A2) <= 0 || (a - A3 - A2) <= 0 || sqrt(1.25)*a - A3 - A1 <= 0 || a < A/2)) A = a;
	else cout << "Self-intersection!" << endl;
}
void CMy2DObject13::setA1(double a1) {
	if (!((A - a1 - A2) <= 0 || sqrt(1.25)*A - A3 - a1 <= 0)) A1 = a1;
	else cout << "Self-intersection!" << endl;
}
void CMy2DObject13::setA2(double a2) {
	if (!((A - A1 - a2) <= 0 || (A - A3 - a2) <= 0)) A2 = a2;
	else cout << "Self-intersection!" << endl;
}
void CMy2DObject13::setA3(double a3) {
	if (!((A - a3 - A2) <= 0 || sqrt(1.25)*A - a3 - A1 <= 0)) A3 = a3;
	else cout << "Self-intersection!" << endl;
}
void CMy2DObject13::setAngle(double angle)
{
	this->m_dAngle = angle;
}
void CMy2DObject13::set_centr(CMy2DPoint centr) {
	/*Проверка не нужна*/
	this->m_centr.m_x = centr.m_x;
	this->m_centr.m_y = centr.m_y;
}
void CMy2DObject13::Move(double dX, double dY, double dAngle) {
	m_centr.m_x = m_centr.m_x + dX;
	m_centr.m_y = m_centr.m_y + dY;
	m_dAngle += dAngle;
}

void CMy2DObject13::Move(const CMy2DPoint &delta, double dAngle) {
	m_centr.m_x = m_centr.m_x + delta.m_x;
	m_centr.m_y = m_centr.m_y + delta.m_y;
	m_dAngle += dAngle;
}

bool CMy2DObject13::IsInside(double x, double y) {
	x = x - m_centr.m_x; //перемещаем точку так, будто фигура в начале координат
	y = y - m_centr.m_y;

	double x1 = x;
	double y1 = y;
	x = x1*cos(m_dAngle) + y1*sin(m_dAngle); //сделаем обратное вращение точки
	y = y1*cos(m_dAngle) - x1*sin(m_dAngle);

	/* И проверим принадлежность нашей фигуре, если бы она находилась в начале координат и угол поворота = 0 */
	return (abs(x) <= A / 2 && abs(y) <= A / 2 && //в большом квадрате
		!(abs(x + A / 2 - A2 / 2) < A2 / 2 && abs(y - A / 2 + A2 / 2) < A2 / 2) && // не в малом квадрате
		!(pow(x + A / 2, 2) + pow(y + A / 2, 2) < A3*A3) && // не в круге с радиусом А3
		!(pow(x - A / 2, 2) + pow(y, 2) < A1*A1)); // не в круг с радиусом А1

}

bool CMy2DObject13::IsInside(const CMy2DPoint& point) {
	double x = point.m_x - m_centr.m_x; //перемещаем точку так, будто фигура в начале координат
	double y = point.m_y - m_centr.m_y;

	double x1 = x;
	double y1 = y;
	x = x1*cos(m_dAngle) + y1*sin(m_dAngle); //сделаем обратное вращение точки
	y = y1*cos(m_dAngle) - x1*sin(m_dAngle);

	/* И проверим принадлежность нашей фигуре, если бы она находилась в начале координат и угол поворота = 0 */
	return (abs(x) <= A / 2 && abs(y) <= A / 2 && //в большом квадрате
		!(abs(x + A / 2 - A2 / 2) < A2 / 2 && abs(y - A / 2 + A2 / 2) < A2 / 2) && // не в малом квадрате
		!(pow(x + A / 2, 2) + pow(y + A / 2, 2) < A3*A3) && // не в круге с радиусом А3
		!(pow(x - A / 2, 2) + pow(y, 2) < A1*A1)); // не в круг с радиусом А1


}