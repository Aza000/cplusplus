#include"Var.h"

int main() {

	setlocale(LC_ALL, "");

	Var a;
	Var b="10";
	Var aa = "Microsoft";
	Var bb = "Windows";
	cout << "b �� ��������� 10 ������� � ����� �������������� ��������" << endl;
	cin >> a;

	int choice;
	while (true) {
		
		cout << "������� 1 ����� +" << endl;
		cout << "������� 2 ����� +=" << endl;
		cout << "������� 3 ����� -" << endl;
		cout << "������� 4 ����� -=" << endl;
		cout << "������� 5 ����� *" << endl;
		cout << "������� 6 ����� *=" << endl;
		cout << "������� 7 ����� /" << endl;
		cout << "������� 8 ����� /=" << endl;
		cout << "������� 9 ����� <" << endl;
		cout << "������� 10 ����� <=" << endl;
		cout << "������� 11 ����� >" << endl;
		cout << "������� 12 ����� >=" << endl;
		cout << "������� 13 ����� ==" << endl;
		cout << "������� 14 ����� !=" << endl;
		cout << "������� 0 ����� �����" << endl;
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