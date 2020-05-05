#include<iostream>
#include<fstream>
#include"Date.h"
#include"Vector.h"

using namespace std;

int main() {
	setlocale(0, "");
	ifstream in("in.txt");

	
	int day, month, year;
	Vector v;
	while (!in.eof()) {
		in >> day >> month >> year;
		v.add(Date(day, month, year));
	}

	for (int i = 0; i < v.size(); i++)
	{
		v.at(i).print();
	}
	cout << endl;

	int choise;


	Date d1(9, 7, 2002);
	Date d2(9, 7, 2002);
	Date r;
	Date d3;

	while (true)
	{
		cout << "¬ведите 1 дл€ сложени€ даты" << endl;
		cout << "¬ведите 2 дл€ вычитани€ даты" << endl;
		cout << "¬ведите 3 дл€ сложени€ к дате целого цисла дней" << endl;
		cout << "¬ведите 4 дл€ вычитани€ к дате целого цисла дней" << endl;
		cout << "¬ведите 5 чтобы сравн€ть две даты " << endl;
		cout << "¬ведите 6 чтобы вывести все даты" << endl;
		cout << "¬ведите 7 чтобы вывести даты в американском стиле" << endl;
		cout << "¬ведите 8 дл€ копирование одной даты в другую" << endl;
		cout << "¬ведите 0 чтобы выйти" << endl;
		cin >> choise;
		if (choise == 0) break;
		switch (choise)
		{
		case 1:
			r = d1 + d2;
			r.print();
			break;
		case 2:
			r = d1 - d2;
			break;
		case 3:
			int days;
			cin >> days;
			r = d1 + days;
			r.print();
			break;
		case 4:
			int days1;
			cin >> days1;
			r = d1 - days1;
			r.print();
			break;
		case 5:
			cout << d1.isE(d2) << endl;
			break;
		case 6:
			for (int i = 0; i < v.size(); i++)
			{
				v.at(i).print();
			}
			cout << endl;
			break;
		case 7:
			d1.printAmerican();
			break;
		case 8:
			Vector::Vector();
			d3.print();
			break;
		}
	}
	system ("pause");
	return 0;
}