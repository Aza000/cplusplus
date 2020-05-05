#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;
/*1.	***Написать программу «справочник». Создать два одномерных массива. Один массив хранит номера ICQ, второй – телефонные номера. Реализовать меню для пользователя: 
a)	отсортировать по номерам ICQ
b)	отсортировать по номерам телефона
c)	вывести список пользователей
d)	выход
*/

//4 3 6 5
//6 9 3 7

//3 4 5 6
//3 6 7 9

int main() {
	const int n = 10;
	const int m = 2;
	int a[n][m];
	
	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = rand() % 11;	
		}
	}
cout << setw(7) << "TelNo" << setw(7) << "ICQ" << endl;
	for (int j = 0; j < n; j++) {
		
		for (int i = 0; i < m; i++) {
			cout << setw(7) << a[i][j];

		}
		cout << endl;
	}


	int choice;
	while (true) {
		cout << "Enter 1 to sort by te no" << endl;
		cout << "Enter 2 to sort by ICQ" << endl;
		cout << "Enter 0 to exit" << endl;
		cin >> choice;
		if (choice == 0) break;
		switch (choice) {
		case 1: {
			for (int pass = 0; pass < n - 1; pass++) {
				for (int i = 0; i < n - 1; i++) {
					if (a[i][0] >= a[i + 1][0]) {
						swap(a[i][0], a[i + 1][0]);
						swap(a[i][1], a[i + 1][1]);
					}
				}
			}
			cout << setw(7) << "TelNo" << setw(7) << "ICQ" << endl;
			for (int i = 0; i < n; i++) {

				for (int j = 0; j < m; j++) {
					cout << setw(7) << a[i][j];

				}
				cout << endl;
			}
		}
			break;
		case 2:
		{	for (int pass = 0; pass < n - 1; pass++) {
				for (int i = 0; i < n - 1; i++) {
					if (a[i][1] >= a[i + 1][1]) {
						swap(a[i][0], a[i + 1][0]);
						swap(a[i][1], a[i + 1][1]);}
				}
			}
			cout << setw(7) << "TelNo" << setw(7) << "ICQ" << endl;
			for (int i = 0; i < n; i++) {

				for (int j = 0; j < m; j++) {
					cout << setw(7) << a[i][j];
				}
				cout << endl;
			}
		}
			break;

		}

	}



	system("pause");
	return 0;
}