#include "My2DObject13.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	setlocale(LC_NUMERIC, "eng");

	cout << " ООП (C++). 2 курс, 3 модуль. Домашнее Задание 1" << endl;
	cout << " Кузьмин Вадим БПМ-142" << endl;
	cout << " Вариант 13" << endl << endl;
	CMy2DPoint point;
	CMy2DPoint point2(0.0, 0.0);
	CMy2DPoint point3(2.0, 2.0);
	//ofstream fout("point_out.txt");
	//fout << point3;
	//fout.close();
	//cin >> point;
	//ifstream fin("point_in.txt");
	//fin >> point;
	//fin.close();
	//cout << point;
	//cout << point << point2 + point3 << point3*2.0 << point3/2 << point3*point3 << 10.0*point3 << endl << point2 - point3 << endl;
	CMy2DObject13 figure(12.0, 3.0, 2.0, 4.0, 0.0, point2);
	figure.print();
	//figure.setA(2.0);
	//figure.setA1(10);
	//figure.setA2(7);
	//figure.print();
	//cout  << figure.IsInside(3.0, 0.0) << endl << figure.IsInside(-6.0, -2.0) << endl << figure.IsInside(-4.0, 4.0) << endl;
	//figure.Move(point3);
	//figure.Get();
	figure.Rotate(M_PI);
	figure.print();
	//cout << figure.IsInside(5.0, -2.0) << endl << figure.IsInside(-4.0, 0.0) << endl << figure.IsInside(7.0, 0.0) << endl;
	CMy2DPoint test(5.0, -2.0);
	cout << "Point " << test << (figure.IsInside(test) == 1 ? " belongs to the figure" : " doesn't belong to the figure.") << endl;
	CMy2DPoint test2(-4.0, 0.0);
	cout << "Point " << test2 << (figure.IsInside(test2) == 1 ? " belongs to the figure" : " doesn't belong to the figure.") << endl;
	getch();
	return 0;
}