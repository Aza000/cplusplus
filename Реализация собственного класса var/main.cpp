#include"Var.h"

int main() {

	setlocale(LC_ALL, "");

	Var a;
	Var b="10";
	Var aa = "Microsoft";
	Var bb = "Windows";
	cout << "b по умолчанию 10 введите а чтобы конвертировать значение" << endl;
	cin >> a;

	int choice;
	while (true) {
		
		cout << "¬ведите 1 чтобы +" << endl;
		cout << "¬ведите 2 чтобы +=" << endl;
		cout << "¬ведите 3 чтобы -" << endl;
		cout << "¬ведите 4 чтобы -=" << endl;
		cout << "¬ведите 5 чтобы *" << endl;
		cout << "¬ведите 6 чтобы *=" << endl;
		cout << "¬ведите 7 чтобы /" << endl;
		cout << "¬ведите 8 чтобы /=" << endl;
		cout << "¬ведите 9 чтобы <" << endl;
		cout << "¬ведите 10 чтобы <=" << endl;
		cout << "¬ведите 11 чтобы >" << endl;
		cout << "¬ведите 12 чтобы >=" << endl;
		cout << "¬ведите 13 чтобы ==" << endl;
		cout << "¬ведите 14 чтобы !=" << endl;
		cout << "¬ведите 0 чтобы выйти" << endl;
		cin >> choice;
		if (choice == 0)
			break;
		switch (choice)
		{
		case 1:
			cout << "summa = " << (a + b) << endl;
			cout << "Microsoft" << endl << "Windows" << endl << aa + bb << endl;
			break;
	
		case 2:
			cout << "summa = " << (a += b) << endl;
			cout << "Microsoft" << endl << "Windows" << endl << (aa += bb) << endl;
			break;

		case 3:
			cout << (a - b) << endl;
			cout << "Microsoft" << endl << "Windows" << endl << (aa - bb) << endl;
			break;

		case 4:
			cout << "summa = "<<(a -= b) << endl;
			cout << "Microsoft" << endl << "Windows" << endl << (aa -= bb) << endl;
			break;

		case 5:
			cout << "summa = " << (a * b) << endl;
			break;

		case 6:
			cout << "summa = "<<(a *= b) << endl;
			cout << "Microsoft" << endl << "Windows" << endl << aa * bb << endl;
			break;

		case 7:
			try {
				cout << "summa = " << a / b << endl;
				cout << "Microsoft" << endl << "Windows" << endl << aa / bb << endl;
	            }
			catch (const char* e) {
				cout << e << endl;
			}
			break;

		case 8:
			try {
				cout << "summa = " << (a /= b) << endl;
				cout << "Microsoft" << endl << "Windows" << endl << (aa /= bb) << endl;

			}
			catch (const char* f) {
				cout << f << endl;
			}
			break;

		case 9:
			if (a < b) 
				cout << "a menshe b" << endl;
			else cout << "a bolshe b" << endl;
			 break;

		case 10:
			if (a <=b)
				cout << "a raven b" << endl;
			else cout << "ne ravni" << endl;
			break;

		case 11:
			if (a > b)
				cout << "a bolshe b" << endl;
			else cout << "a menshe b" << endl;
			break;

		case 12:
			if (a >= b)
				cout << "a raven b" << endl;
			else cout << "ne ravni" << endl;
			break;

		case 13:
			if (a == b) {
				cout << "a raven b" << endl;
			}
			else cout << "ne ravni" << endl;
			break;

		case 14:
			if (a != b)
			{
				cout << "a ne raven b" << endl;
			}
			else cout << "a raven b" << endl;
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}